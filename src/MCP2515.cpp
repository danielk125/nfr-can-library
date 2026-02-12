#include "../include/nfr_can/MCP2515.hpp"
#include <bitset>
#include <cstring>
#include <iostream>

void MCP2515::select(bool set) {
    while(!_cs.gpio_write(set ? GpioLevel::G_LOW : GpioLevel::G_HIGH));
}

bool MCP2515::reset() {
    uint8_t cmd = CMD_RESET;

    select(true);
    bool ok = _spi.ISpi_write(&cmd, 1);
    select(false);

    _clock.sleepMs(10);
    return ok;
}

bool MCP2515::writeRegister(uint8_t addr, uint8_t val) {
    uint8_t data[3]{CMD_WRITE, addr, val};

    select(true);
    bool ok = _spi.ISpi_write(data, 3);
    select(false);

    return ok;
}

bool MCP2515::readRegister(uint8_t addr, uint8_t& out) {
    uint8_t tx[3]{CMD_READ, addr, 0x00};
    uint8_t rx[3]{};  // needs to be same length to account for full-duplex

    select(true);
    bool ok = _spi.ISpi_transfer(tx, rx, 3);
    select(false);

    if (!ok)
        return false;
    out = rx[2];
    return true;
}

bool MCP2515::bitModify(uint8_t addr, uint8_t mask, uint8_t data) {
    uint8_t buf[4]{CMD_BITMOD, addr, mask, data};

    select(true);
    bool ok = _spi.ISpi_write(buf, 4);
    select(false);

    return ok;
}

bool MCP2515::writeRegisters(uint8_t startAddr, const uint8_t* data, uint8_t len) {
    if (!data || len == 0) return false;

    uint8_t buf[2 + 32]{};
    buf[0] = CMD_WRITE;
    buf[1] = startAddr;
    std::memcpy(&buf[2], data, len);

    select(true);
    bool ok = _spi.ISpi_write(buf, static_cast<size_t>(2 + len));
    select(false);
    return ok;
}

bool MCP2515::readRegisters(uint8_t startAddr, uint8_t* data, uint8_t len) {
    if (len == 0)
        return false;

    uint8_t tx[2 + 32]{};
    uint8_t rx[2 + 32]{};

    tx[0] = CMD_READ;
    tx[1] = startAddr;

    select(true);
    bool ok = _spi.ISpi_transfer(tx, rx, static_cast<size_t>(2 + len));
    select(false);
    if (!ok)
        return false;

    std::memcpy(data, &rx[2], len);
    return true;
}

bool MCP2515::probe(std::string& error) {
    select(false);
    if (!reset()) {
        error = "reset failure";
        return false;
    }

    if (!bitModify(REG_CANCTRL, CANCTRL_REQOP_MASK, CANCTRL_MODE_CONFIG)) {
        error = "bitmode failure";
        return false;
    }

    uint8_t out;
    if (!readRegister(REG_CANSTAT, out)) {
        error = "read reg failure";
        return false;
    };

    char buf[64];
    snprintf(buf, sizeof(buf), "CANSTAT=0x%02X (want OPMOD=0x80)", out);
    error = buf;

    return (out & CANCTRL_REQOP_MASK) == CANCTRL_MODE_CONFIG;
}

void MCP2515::packId(
    uint32_t id, bool extended, uint8_t& sidh, uint8_t& sidl, uint8_t& eid8, uint8_t& eid0) {
    if (!extended) {
        // 11-bit standard
        id &= 0x7FF;
        sidh = static_cast<uint8_t>(id >> 3);
        sidl = static_cast<uint8_t>((id & 0x7) << 5);  // bits 7..5
        sidl &= 0xE0;
        eid8 = 0;
        eid0 = 0;
    } else {
        // 29-bit extended
        id &= 0x1FFFFFFF;
        sidh = static_cast<uint8_t>(id >> 21);
        sidl = static_cast<uint8_t>(((id >> 18) & 0x7) << 5);
        sidl |= 0x08;                                    // IDE bit
        sidl |= static_cast<uint8_t>((id >> 16) & 0x3);  // EID17..16 into bits 1..0
        eid8 = static_cast<uint8_t>((id >> 8) & 0xFF);
        eid0 = static_cast<uint8_t>(id & 0xFF);
    }
}

void MCP2515::unpackId(
    uint8_t sidh, uint8_t sidl, uint8_t eid8, uint8_t eid0, uint32_t& id, bool& extended) {
    extended = (sidl & 0x08) != 0;
    if (!extended) {
        id = (static_cast<uint32_t>(sidh) << 3) | (static_cast<uint32_t>(sidl) >> 5);
        id &= 0x7FF;
    } else {
        uint32_t sid =
            (static_cast<uint32_t>(sidh) << 3) | ((static_cast<uint32_t>(sidl) >> 5) & 0x7);
        uint32_t eid = (static_cast<uint32_t>(sidl) & 0x3) << 16;
        eid |= static_cast<uint32_t>(eid8) << 8;
        eid |= static_cast<uint32_t>(eid0);
        id = (sid << 18) | eid;
        id &= 0x1FFFFFFF;
    }
}

bool MCP2515::baudRateToCNF(BaudRate baud, bitRateConfig& out) {
    switch (baud) {
        case BaudRate::kBaud125k:
            out = {0x01, 0xB1, 0x05};
            return true;
        case BaudRate::kBaud250K:
            out = {0x00, 0xB1, 0x05};
            return true;
        case BaudRate::kBaud500K:
            out = {0x00, 0x91, 0x01};
            return true;
        case BaudRate::kBaud1M:
            out = {0x00, 0x80, 0x00};
            return true;
        default:
            return false;
    }
}

bool MCP2515::init(const BaudRate baud) {
    bitRateConfig cfg;
    if (!baudRateToCNF(baud, cfg))
        return false;

    // CS should idle high for MCP2515
    select(false);

    if (!reset())
        return false;

    auto waitForMode = [&](uint8_t wantMode, uint32_t timeoutMs) -> bool {
        const uint32_t start = _clock.monotonicMs();
        while ((_clock.monotonicMs() - start) < timeoutMs) {
            uint8_t canstat = 0;
            if (!readRegister(REG_CANSTAT, canstat))
                return false;
            if ((canstat & CANCTRL_REQOP_MASK) == wantMode)
                return true;
            _clock.sleepMs(1);
        }
        return false;
    };

    // Enter config mode
    if (!bitModify(REG_CANCTRL, CANCTRL_REQOP_MASK, CANCTRL_MODE_CONFIG))
        return false;
    if (!waitForMode(CANCTRL_MODE_CONFIG, 50))
        return false;

    // Program bit timing
    if (!writeRegister(REG_CNF1, cfg.cnf1))
        return false;
    if (!writeRegister(REG_CNF2, cfg.cnf2))
        return false;
    if (!writeRegister(REG_CNF3, cfg.cnf3))
        return false;

    // Accept all messages into RXB0 (RXM1:RXM0 = 11)
    if (!writeRegister(REG_RXB0CTRL, 0x60))
        return false;

    // Enable RX0 interrupt (RX0IE = bit0)
    if (!writeRegister(REG_CANINTE, 0x01))
        return false;

    // Clear interrupt flags
    if (!writeRegister(REG_CANINTF, 0x00))
        return false;

    // Disable RTS-pin-triggered sends (TXnRTS pins can float safely)
    if (!writeRegister(REG_TXRTSCTRL, 0x00))
        return false;

    // Request normal mode
    if (!bitModify(REG_CANCTRL, CANCTRL_REQOP_MASK, CANCTRL_MODE_NORMAL))
        return false;
    if (!waitForMode(CANCTRL_MODE_NORMAL, 50)) {
        uint8_t canctrl = 0, canstat = 0;
        (void)readRegister(REG_CANCTRL, canctrl);
        (void)readRegister(REG_CANSTAT, canstat);
        std::cout << "Failed to enter NORMAL. "
                  << "CANCTRL=0x" << std::hex << (int)canctrl << " CANSTAT=0x" << (int)canstat
                  << std::dec << "\n";
        return false;
    }

    // Clear any stale pending TX requests so send() can make progress
    if (!abortAllTx()) {
        std::cout << "Failed to abortAllTx() during begin()\n";
        return false;
    }
    // clear TXB0CTRL flags (ABTF/MLOA/TXERR/TXREQ) explicitly
    if (!writeRegister(REG_TXB0CTRL, 0x00)) {
        std::cout << "Failed to clear TXB0CTRL during begin()\n";
        return false;
    }

    // Dump some debug info
    {
        uint8_t canstat = 0, canctrl = 0, txb0 = 0;
        readRegister(REG_CANSTAT, canstat);
        readRegister(REG_CANCTRL, canctrl);
        readRegister(REG_TXB0CTRL, txb0);
        std::cout << "[MCP2515::begin] CANCTRL=0x" << std::hex << (int)canctrl << " CANSTAT=0x"
                  << (int)canstat << " TXB0CTRL=0x" << (int)txb0 << std::dec << "\n";
    }

    return true;
}

bool MCP2515::send(const CAN_Frame& msg) {
    // Must be in normal mode to expect real TX/ACK behavior
    uint8_t canstat = 0;
    if (!readRegister(REG_CANSTAT, canstat)) {
        std::cout << "Failed to read CANSTAT\n";
        dumpStatus("CANSTAT read failed");
        return false;
    }
    if ((canstat & CANCTRL_REQOP_MASK) != CANCTRL_MODE_NORMAL) {
        std::cout << "Refusing to send: not in NORMAL mode. CANSTAT=0x" << std::hex << (int)canstat
                  << std::dec << "\n";
        dumpStatus("not in normal mode");
        return false;
    }

    // Pre-check TXB0 state
    uint8_t txctrl = 0;
    if (!readRegister(REG_TXB0CTRL, txctrl)) {
        std::cout << "Failed to read TXB0CTRL\n";
        dumpStatus("read TXB0CTRL failed");
        return false;
    }

    if (txctrl & TXBCTRL_TXREQ) {
        std::cout << "TXB0 is busy: " << std::bitset<8>(txctrl) << "\n";
        dumpStatus("TXB0 busy before load");

        // Recovery: clear stuck TXREQ so future sends can proceed
        if (!abortAllTx()) {
            std::cout << "abortAllTx() failed while TXB0 busy\n";
            dumpStatus("abortAllTx failed");
            return false;
        }

        uint8_t after = 0;
        if (readRegister(REG_TXB0CTRL, after)) {
            std::cout << "After ABAT, TXB0CTRL=0b" << std::bitset<8>(after) << "\n";
        }
        return false;  // caller can retry next tick
    }

    uint8_t sidh = 0, sidl = 0, eid8 = 0, eid0 = 0;
    packId(msg._id, msg._extendedId, sidh, sidl, eid8, eid0);

    const uint8_t dlc = (msg._length <= 8) ? msg._length : 8;
    const uint8_t txdlc = dlc & 0x0F;

    uint8_t hdr[5]{sidh, sidl, eid8, eid0, txdlc};
    if (!writeRegisters(REG_TXB0SIDH, hdr, 5)) {
        std::cout << "Failed to write TXB0SIDH\n";
        dumpStatus("write TX header failed");
        return false;
    }

    uint8_t buf[8]{};
    for (uint8_t i = 0; i < dlc; i++) {
        buf[i] = msg._data[i];
    }

    if (dlc > 0) {
        if (!writeRegisters(REG_TXB0D0, buf, dlc)) {
            std::cout << "Failed to write TXB0D0\n";
            dumpStatus("write TX data failed");
            return false;
        }
    }

    // Kick TX
    uint8_t cmd = CMD_RTS_TX0;
    select(true);
    bool ok = _spi.ISpi_write(&cmd, 1);
    select(false);

    if (!ok) {
        std::cout << "Failed to send RTS command\n";
        dumpStatus("RTS SPI write failed");
        return false;
    }

    // poll briefly to see if TXREQ clears
    const uint32_t start = _clock.monotonicMs();
    uint8_t last = 0;
    while ((_clock.monotonicMs() - start) < 10) {
        uint8_t t = 0;
        if (!readRegister(REG_TXB0CTRL, t)) {
            std::cout << "Failed to read TXB0CTRL after RTS\n";
            dumpStatus("post-RTS TXB0CTRL read failed");
            return false;
        }
        last = t;

        if ((t & TXBCTRL_TXREQ) == 0) {
            return true;
        }

        _clock.sleepMs(1);
    }

    std::cout << "TXB0 still busy after RTS (10ms). TXB0CTRL=0b" << std::bitset<8>(last) << "\n";
    dumpStatus("post-RTS TXREQ stuck");

    abortAllTx();
    return false;
}

bool MCP2515::recv(CAN_Frame& msg) {
    uint8_t intf = 0;
    if (!readRegister(REG_CANINTF, intf))
        return false;

    if ((intf & CANINTF_RX0IF) == 0) {
        return false;
    }

    uint8_t hdr[5] = {0};
    if (!readRegisters(REG_RXB0SIDH, hdr, 5))
        return false;

    const uint8_t sidh = hdr[0];
    const uint8_t sidl = hdr[1];
    const uint8_t eid8 = hdr[2];
    const uint8_t eid0 = hdr[3];
    const uint8_t dlc_raw = hdr[4];

    msg._extendedId = (sidl & RXB0SIDL_IDE) != 0;
    msg._length = static_cast<uint8_t>(dlc_raw & RXB0DLC_LENMSK);
    if (msg._length > 8)
        msg._length = 8;

    unpackId(sidh, sidl, eid8, eid0, msg._id, msg._extendedId);

    // write to buffer
    uint8_t buf[8];
    if (msg._length > 0) {
        if (!readRegisters(REG_RXB0D0, buf, msg._length))
            return false;
    }

    // write to message
    for (int i = 0; i < 8; i++) {
        msg._data[i] = buf[i];
    }

    // CANINTF bits are cleared by writing 0 to the bit
    if (!bitModify(REG_CANINTF, CANINTF_RX0IF, 0x00))
        return false;

    recvCount++;

    return true;
}

uint32_t MCP2515::time_ms() {
    return _clock.monotonicMs();
}

bool MCP2515::abortAllTx() {
    if (!bitModify(REG_CANCTRL, CANCTRL_ABAT, CANCTRL_ABAT))
        return false;
    _clock.sleepMs(1);
    return bitModify(REG_CANCTRL, CANCTRL_ABAT, 0x00);
}

void MCP2515::dumpStatus(const char* tag) {
    uint8_t canctrl = 0, canstat = 0, eflg = 0, tec = 0, rec = 0, txctrl = 0;

    bool ok0 = readRegister(REG_CANCTRL, canctrl);
    bool ok1 = readRegister(REG_CANSTAT, canstat);
    bool ok2 = readRegister(REG_EFLG, eflg);
    bool ok3 = readRegister(REG_TEC, tec);
    bool ok4 = readRegister(REG_REC, rec);
    bool ok5 = readRegister(REG_TXB0CTRL, txctrl);

    std::cout << "[MCP2515::send] " << tag << "\n";
    if (ok0)
        std::cout << "  CANCTRL=0x" << std::hex << (int)canctrl << std::dec << "\n";
    else
        std::cout << "  CANCTRL=<read failed>\n";

    if (ok1)
        std::cout << "  CANSTAT=0x" << std::hex << (int)canstat << std::dec
                  << " (OPMOD=" << std::bitset<3>((canstat >> 5) & 0x7) << ")\n";
    else
        std::cout << "  CANSTAT=<read failed>\n";

    if (ok2) {
        std::cout << "  EFLG=0x" << std::hex << (int)eflg << std::dec
                  << " (TXBO=" << ((eflg & EFLG_TXBO) ? 1 : 0)
                  << " TXEP=" << ((eflg & EFLG_TXEP) ? 1 : 0)
                  << " RXEP=" << ((eflg & EFLG_RXEP) ? 1 : 0)
                  << " TXWAR=" << ((eflg & EFLG_TXWAR) ? 1 : 0)
                  << " RXWAR=" << ((eflg & EFLG_RXWAR) ? 1 : 0)
                  << " EWARN=" << ((eflg & EFLG_EWARN) ? 1 : 0) << ")\n";
    } else {
        std::cout << "  EFLG=<read failed>\n";
    }

    if (ok3)
        std::cout << "  TEC=" << (int)tec << "\n";
    else
        std::cout << "  TEC=<read failed>\n";

    if (ok4)
        std::cout << "  REC=" << (int)rec << "\n";
    else
        std::cout << "  REC=<read failed>\n";

    if (ok5) {
        std::cout << "  TXB0CTRL=0b" << std::bitset<8>(txctrl)
                  << " (ABTF=" << ((txctrl & TXBCTRL_ABTF) ? 1 : 0)
                  << " MLOA=" << ((txctrl & TXBCTRL_MLOA) ? 1 : 0)
                  << " TXERR=" << ((txctrl & TXBCTRL_TXERR) ? 1 : 0)
                  << " TXREQ=" << ((txctrl & TXBCTRL_TXREQ) ? 1 : 0) << ")\n";
    } else {
        std::cout << "  TXB0CTRL=<read failed>\n";
    }
}

bool MCP2515::updateMissCounter() {
    // RX10VR
    uint8_t val;
    bool passed = readRegister(REG_EFLG, val);
    if (!passed) {
        return false;
    }

    uint8_t shifted = val >> 6;

    if (shifted > 0) {
        missCounter++;
        bitModify(REG_EFLG, 0xC0, 0x00);
    }

    return true;
}

float MCP2515::getMissCounter() {
    return missCounter;
}
