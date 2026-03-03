#ifndef __CAN_INTERFACE_H__
#define __CAN_INTERFACE_H__

#include "ICAN.hpp"

#include <cassert>
#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <memory>
#include <functional>
#include <type_traits>
#include <cstring>
#include <stdexcept>
#include <string>

#include "virtual_timer.hpp"

// Bit helpers -- defined at the bottom
static inline uint8_t getBit(const std::array<uint8_t, 8>& data, uint16_t bitIndex);
static inline void setBit(std::array<uint8_t, 8>& data, uint16_t bitIndex, uint8_t v);
static inline uint64_t extractRawLE(const std::array<uint8_t, 8>& data,
                                    uint16_t startBit,
                                    uint8_t length);
static inline void insertRawLE(std::array<uint8_t, 8>& data,
                               uint16_t startBit,
                               uint8_t length,
                               uint64_t raw);
static inline uint16_t BENextBit(uint16_t currentBit);
static inline uint64_t extractRawBE(const std::array<uint8_t, 8>& data,
                                    uint16_t startBit,
                                    uint8_t length);
static inline void insertRawBE(std::array<uint8_t, 8>& data,
                               uint16_t startBit,
                               uint8_t length,
                               uint64_t raw);
static inline int64_t signExtend(uint64_t raw, uint8_t length);
static inline uint64_t maskN(uint8_t n);

using RawSignalValue = uint64_t;

enum class Endianness { littleEndian, bigEndian };

struct ICAN_Signal_DataBuf {
    std::array<uint8_t, 8> buf;
    uint8_t data_length;
};


enum class SignalType { INT8, INT16, INT32, INT64, UINT8, UINT16, UINT32, UINT64, FLOAT, BOOL };

struct ICAN_Signal {
    virtual ~ICAN_Signal() = default;

    virtual void decode(const std::array<uint8_t, 8>& data) = 0;

    virtual void encode(std::array<uint8_t, 8>& data) const = 0;

    virtual ICAN_Signal_DataBuf toBuf() const = 0;

    virtual std::string to_string() const = 0;

    virtual SignalType getSignalType() = 0;

    virtual void set(SignalType type, void *data) = 0;
};

struct CAN_Signal_config {
    uint8_t startBit;
    uint8_t length;
    double factor;
    double offset;
    bool isSigned = false;
    Endianness endian = Endianness::littleEndian;
};



template <typename T>
class CAN_Signal : public ICAN_Signal {
   public:
    CAN_Signal(uint8_t startBit,
               uint8_t length,
               double factor,
               double offset,
               bool isSigned = false,
               Endianness endian = Endianness::littleEndian)
        : _startBit(startBit),
          _length(length),
          _factor(factor),
          _offset(offset),
          _isSigned(isSigned),
          _endian(endian),
          _sRawValue() {
        set(0);
    }

    CAN_Signal(CAN_Signal_config& cfg,
               bool isSigned = false,
               Endianness endian = Endianness::littleEndian)
        : CAN_Signal(cfg.startBit, cfg.length, cfg.factor, cfg.offset, isSigned, endian) {
    }

    uint8_t startBit() {
        return _startBit;
    }
    uint8_t length() {
        return _length;
    }
    double factor() {
        return _factor;
    }
    double offset() {
        return _offset;
    }
    bool isSigned() {
        return _isSigned;
    }
    RawSignalValue getRawValue() {
        return _sRawValue;
    }

    T get() const {
        return _sValue;
    }

    ICAN_Signal_DataBuf toBuf() const override {
        T data = get();

        uint64_t temp = 0;
        uint8_t length = static_cast<uint8_t>(sizeof(T));
        std::memcpy(&temp, &data, length);

        std::array<uint8_t, 8> buf{};

        for (int i = 0; i < 8; i++) {
            buf[7 - i] = static_cast<uint8_t>(temp % 0xFF);
            temp >>= 8;
        }

        ICAN_Signal_DataBuf dataBuf;
        dataBuf.buf = buf;
        dataBuf.data_length = length;

        return dataBuf;
    }

    std::string to_string() const override {
        return std::to_string(get());
    }

    void set(SignalType type, void *val) override {
        _sValue = *static_cast<T*>(val);
    }

    void set(T val) {
        _sValue = val;
    }

    void decode(const std::array<uint8_t, 8>& data) override {
        // 1) extract raw bits
        uint64_t rawU = _endian == Endianness::bigEndian ? extractRawBE(data, _startBit, _length)
                                                         : extractRawLE(data, _startBit, _length);
        _sRawValue = rawU;

        // 2) interpret signed/unsigned raw
        double phys = 0.0;
        if (_isSigned) {
            int64_t rawS = signExtend(rawU, _length);
            phys = (double)rawS * _factor + _offset;
        } else {
            phys = (double)rawU * _factor + _offset;
        }

        // 3) store into variant in the correct type
        _sValue = (T)phys;
    }

    void encode(std::array<uint8_t, 8>& data) const override {
        // 1) read physical from _value as double
        double phys = (double)_sValue;

        // 2) physical -> raw (inverse scaling)
        double rawD = (phys - _offset) / _factor;

        // choose rounding policy; nearbyint uses current rounding mode
        // llround is common (round half away from zero)
        int64_t rawS = (int64_t)std::llround(rawD);

        // 3) clamp/mask into N bits
        uint64_t rawU = 0;
        if (_isSigned) {
            rawU = (uint64_t)rawS & maskN(_length);
        } else {
            if (rawS < 0)
                rawS = 0;
            rawU = (uint64_t)rawS & maskN(_length);
        }

        // 4) insert bits
        if (_endian == Endianness::bigEndian)
            insertRawBE(data, _startBit, _length, rawU);
        else
            insertRawLE(data, _startBit, _length, rawU);
    }

    SignalType getSignalType() override {
        if (typeid(T) == typeid(int8_t)) {
            return SignalType::INT8;
        } else if (typeid(T) == typeid(int16_t)) {
            return SignalType::INT16;
        } else if (typeid(T) == typeid(int32_t)) {
            return SignalType::INT32;
        } else if (typeid(T) == typeid(int64_t)) {
            return SignalType::INT64;
        } else if (typeid(T) == typeid(uint8_t)) {
            return SignalType::UINT8;
        } else if (typeid(T) == typeid(uint16_t)) {
            return SignalType::UINT16;
        } else if (typeid(T) == typeid(uint32_t)) {
            return SignalType::UINT32;
        } else if (typeid(T) == typeid(uint64_t)) {
            return SignalType::UINT64;
        } else if (typeid(T) == typeid(float)) {
            return SignalType::FLOAT;
        } else if (typeid(T) == typeid(bool)) {
            return SignalType::BOOL;
        } else {
            throw std::runtime_error("Unexpected Signal type.");
        }
    }

   private:
    uint8_t _startBit;
    uint8_t _length;
    double _factor;
    double _offset;
    bool _isSigned;
    Endianness _endian;
    T _sValue;
    RawSignalValue _sRawValue;
};

struct CAN_Message_ID {
    uint32_t id;
    bool extended;

    friend bool operator==(const CAN_Message_ID& a, const CAN_Message_ID& b) {
        return a.id == b.id && a.extended == b.extended;
    }
};

struct MsgKeyHash {
    size_t operator()(const CAN_Message_ID& k) const noexcept {
        return (static_cast<size_t>(k.id) * 1315423911u) ^ static_cast<size_t>(k.extended);
    }
};

struct ICAN_Message {
    virtual ~ICAN_Message() = default;
    virtual CAN_Message_ID get_id() const = 0;
    virtual uint8_t length() const = 0;
    virtual uint8_t get_num_signals() const = 0;

    virtual void decode_from(const CAN_Frame& frame) = 0;
    virtual void encode_to_frame(CAN_Frame& frame) const = 0;
    virtual bool attach_rx_callback(std::function<void()> callback) = 0;

    virtual ICAN_Signal* get_signal(uint8_t index) = 0;
};

class CAN_Bus {
    std::unique_ptr<ICAN> _can;
    std::unordered_map<CAN_Message_ID, ICAN_Message*, MsgKeyHash> _rx_map;

   public:
    CAN_Bus(std::unique_ptr<ICAN> can) : _can(std::move(can)) {
    }
    CAN_Bus() : _can(nullptr) {
    }

    std::vector<ICAN_Message*> get_messages() {
        std::vector<ICAN_Message*> messagePtrs;

        for (const auto& [key, value] : _rx_map) {
            messagePtrs.push_back(value);
        }

        return messagePtrs;
    }

    bool init(const BaudRate baud) {
        if (_can) {
            return _can->init(baud);
        }

        return true;
    }

    void set_driver(std::unique_ptr<ICAN> can) {
        _can = std::move(can);
    }

    void register_message(ICAN_Message& msg) {
        auto k = msg.get_id();
        auto [it, inserted] = _rx_map.emplace(k, &msg);
        if (!inserted) {
            throw std::runtime_error("Duplicate message key registered");
        }
    }

    void unregister_message(ICAN_Message& msg) {
        auto k = msg.get_id();
        auto it = _rx_map.find(k);
        if (it != _rx_map.end() && it->second == &msg) {
            _rx_map.erase(it);
        }
    }

    bool send(const ICAN_Message& msg) {
        if (!_can) {
            return false;
        }

        CAN_Frame fr;
        msg.encode_to_frame(fr);
        return _can->send(fr);
    }

    uint32_t get_time() {
        if (!_can) {
            return 0;
        }

        return _can->time_ms();
    }

    ICAN_Message *get_message_from_id(uint32_t id) {
        CAN_Message_ID msgId { id, false };
        return _rx_map.at(msgId);
    }

    void tick_bus() {
        if (!_can) {
            return;
        }

        CAN_Frame rx_msg;
        while (_can->recv(rx_msg)) {
            CAN_Message_ID k{rx_msg._id, rx_msg._extendedId};

            auto it = _rx_map.find(k);
            if (it != _rx_map.end() && it->second) {
                it->second->decode_from(rx_msg);
            }
        }
    }
};

struct RX_can_msg_config {
    CAN_Bus& bus;
    uint32_t id;
    bool extended;
    uint8_t length;
    std::function<void()> callback_func{};
};

struct TX_can_msg_config {
    CAN_Bus& bus;
    uint32_t id;
    bool extended;
    uint8_t length;
    uint32_t period;
    VirtualTimerGroup& timerGroup;
};

template <size_t num_signals, bool RX>  // add bool for rx
class CAN_Message : public ICAN_Message {
   public:
    template <class>
    struct is_shared_ptr_to_ican_signal : std::false_type {};

    template <class U>
    struct is_shared_ptr_to_ican_signal<std::shared_ptr<U>>
        : std::bool_constant<std::is_base_of_v<ICAN_Signal, U>> {};

    template <class... Ts>
    using enable_if_all_signals_t =
        std::enable_if_t<(is_shared_ptr_to_ican_signal<std::decay_t<Ts>>::value && ...), int>;

    // Constructor for RX
    template <class... Ps, enable_if_all_signals_t<Ps...> = 0>
    CAN_Message(CAN_Bus& bus, uint32_t id, bool extended, uint8_t length, Ps&&... signals)
        : CAN_Message(bus,
                      id,
                      extended,
                      length,
                      std::function<void()>{},  // default to void
                      std::forward<Ps>(signals)...) {
        static_assert(RX, "TX constructor called for RX message!");
    }

    // Constructor for RX message with callback
    template <class... Ps>
    CAN_Message(CAN_Bus& bus,
                uint32_t id,
                bool extended,
                uint8_t length,
                std::function<void(void)> callback_function,
                Ps&&... signals)
        : _bus(bus),
          _id(id),
          _extended(extended),
          _length(length),
          _callback_function(std::move(callback_function)),
          _signals{std::static_pointer_cast<ICAN_Signal>(std::forward<Ps>(signals))...},
          _last_recv_time(0) {
        static_assert(sizeof...(signals) == num_signals, "wrong number of signals");
        static_assert(RX, "TX constructor called for RX message!");
        static_assert((is_shared_ptr_to_ican_signal<std::decay_t<Ps>>::value && ...),
                      "Signals must be shared_ptr to ICAN_Signal-derived");
        _bus.register_message(*this);
    }

    // Constructor for TX message
    template <class... Ps>
    CAN_Message(CAN_Bus& bus,
                uint32_t id,
                bool extended,
                uint8_t length,
                uint32_t period,
                VirtualTimerGroup& timerGroup,
                Ps&&... signals)
        : _bus(bus),
          _id(id),
          _extended(extended),
          _length(length),
          _transmit_timer(
              period, [this]() { _bus.send(*this); }, VirtualTimer::Type::kRepeating),
          _signals{std::static_pointer_cast<ICAN_Signal>(std::forward<Ps>(signals))...},
          _last_recv_time(0) {
        static_assert(sizeof...(signals) == num_signals, "wrong number of signals");
        static_assert(!RX, "RX constructor called for TX message!");
        static_assert((is_shared_ptr_to_ican_signal<std::decay_t<Ps>>::value && ...),
                      "Signals must be shared_ptr to ICAN_Signal-derived");
        timerGroup.AddTimer(_transmit_timer);
    }

    template <class... Ps>
    CAN_Message(RX_can_msg_config& cfg, Ps&&... signals)
        : CAN_Message(cfg.bus,
                      cfg.id,
                      cfg.extended,
                      cfg.length,
                      cfg.callback_func,
                      std::forward<Ps>(signals)...) {
        static_assert(RX, "Cannot give RX config struct to TX message!");
    }

    template <class... Ps>
    CAN_Message(TX_can_msg_config& cfg, Ps&&... signals)
        : CAN_Message(cfg.bus,
                      cfg.id,
                      cfg.extended,
                      cfg.length,
                      cfg.period,
                      cfg.timerGroup,
                      std::forward<Ps>(signals)...) {
        static_assert(!RX, "Cannot give TX config struct to RX message!");
    }

    ~CAN_Message() override {
        if constexpr (RX) {
            _bus.unregister_message(*this);
        } else {
            TX_disable();
        }
    }

    CAN_Message_ID get_id() const override {
        return {_id, _extended};
    }

    uint8_t get_num_signals() const override {
        return num_signals;
    }

    uint32_t id() {
        return _id;
    }

    uint8_t length() const override {
        return _length;
    }

    bool extended() {
        return _extended;
    }

    void decode_from(const CAN_Frame& frame) override {
        if constexpr (RX) {
            std::array<uint8_t, 8> data = frame._data;

            uint64_t tmp = 0;
            std::memcpy(&tmp, data.data(), sizeof(tmp));
            _raw = tmp;

            for (int i = 0; i < num_signals; i++) {
                _signals.at(i)->decode(data);
            }

            if (_callback_function) {
                _callback_function();
            }

            _last_recv_time = _bus.get_time();
        }
    }

    void encode_to_frame(CAN_Frame& frame) const override {
        if constexpr (!RX) {
            frame._id = _id;
            frame._extendedId = _extended;
            frame._length = _length;

            std::array<uint8_t, 8> data{};
            for (int i = 0; i < num_signals; i++) {
                _signals.at(i)->encode(data);
            }

            frame._data = data;
        }
    }

    bool attach_rx_callback(std::function<void(void)> callback_function) override {
        if constexpr (RX) {
            _callback_function = callback_function;
            return true;
        } else {
            return false;
        }
    }

    ICAN_Signal* get_signal(uint8_t index) override {
        if (index < num_signals) {
            return _signals[index].get();
        } else {
            return nullptr;
        }
    }

    std::array<ICAN_Signal_DataBuf, num_signals> getSignalData() {
        std::array<ICAN_Signal_DataBuf, num_signals> buf;
        for (int i = 0; i < num_signals; i++) {
            buf[i] = _signals[i]->toBuf();
        }

        return buf;
    }

    void TX_enable() {
        if constexpr (!RX) {
            _transmit_timer.Enable();
        }
    }

    void TX_disable() {
        if constexpr (!RX) {
            _transmit_timer.Disable();
        }
    }

    uint32_t getLastRecvTimeMS() {
        return _last_recv_time;
    }

   private:
    CAN_Bus& _bus;
    uint32_t _id;
    uint8_t _length;
    bool _extended;
    std::function<void(void)> _callback_function;
    std::array<std::shared_ptr<ICAN_Signal>, num_signals> _signals;

    uint32_t _last_recv_time;
    uint64_t _raw;
    VirtualTimer _transmit_timer;
};

// macros for constructing signals and messages in a readable way
/*
    IMPORTANT
    Message macros do not actually enforce that you use the correct constructor!
    They are purely for enhancing readability.
    You still should use the associated constructor for RX or TX messages.
*/
#define RX_CAN_Message(num_signals) CAN_Message<num_signals, true>

#define TX_CAN_Message(num_signals) CAN_Message<num_signals, false>

/*
    Macros for making signals
*/
#define MakeSignal(type, cfg)           \
    std::make_shared<CAN_Signal<type>>( \
        cfg.startBit, cfg.length, cfg.factor, cfg.offset, cfg.isSigned, cfg.endian);

#define MakeSignalExp(type, startBit, length, factor, offset) \
    std::make_shared<CAN_Signal<type>>(startBit, length, factor, offset);

#define MakeSignalSigned(type, startBit, length, factor, offset, isSigned) \
    std::make_shared<CAN_Signal<type>>(startBit, length, factor, offset, isSigned);

#define MakeSignalEndian(type, startBit, length, factor, offset, endianness) \
    std::make_shared<CAN_Signal<type>>(startBit, length, factor, offset, false, endianness);

#define MakeSignalSignedEndian(type, startBit, length, factor, offset, isSigned, endianness) \
    std::make_shared<CAN_Signal<type>>(startBit, length, factor, offset, isSigned, endianness);

// type definitions for signals for improving readability
using CAN_Signal_UINT8 = std::shared_ptr<CAN_Signal<uint8_t>>;
using CAN_Signal_UINT16 = std::shared_ptr<CAN_Signal<uint16_t>>;
using CAN_Signal_UINT32 = std::shared_ptr<CAN_Signal<uint32_t>>;
using CAN_Signal_UINT64 = std::shared_ptr<CAN_Signal<uint64_t>>;
using CAN_Signal_INT8 = std::shared_ptr<CAN_Signal<int8_t>>;
using CAN_Signal_INT16 = std::shared_ptr<CAN_Signal<int16_t>>;
using CAN_Signal_INT32 = std::shared_ptr<CAN_Signal<int32_t>>;
using CAN_Signal_INT64 = std::shared_ptr<CAN_Signal<int64_t>>;
using CAN_Signal_FLOAT = std::shared_ptr<CAN_Signal<float>>;
using CAN_Signal_BOOL = std::shared_ptr<CAN_Signal<bool>>;

// Bit helper definitions

static inline uint8_t getBit(const std::array<uint8_t, 8>& data, uint16_t bitIndex) {
    return (data[bitIndex / 8] >> (bitIndex % 8)) & 1u;
}

static inline void setBit(std::array<uint8_t, 8>& data, uint16_t bitIndex, uint8_t v) {
    uint8_t& b = data[bitIndex / 8];
    uint8_t mask = uint8_t(1u << (bitIndex % 8));
    if (v)
        b |= mask;
    else
        b &= uint8_t(~mask);
}

static inline uint64_t extractRawLE(const std::array<uint8_t, 8>& data,
                                    uint16_t startBit,
                                    uint8_t length) {
    assert(length >= 1 && length <= 64);
    uint64_t raw = 0;
    for (uint8_t i = 0; i < length; ++i) {
        raw |= (uint64_t)getBit(data, startBit + i) << i;
    }
    return raw;
}

static inline void insertRawLE(std::array<uint8_t, 8>& data,
                               uint16_t startBit,
                               uint8_t length,
                               uint64_t raw) {
    assert(length >= 1 && length <= 64);
    for (uint8_t i = 0; i < length; ++i) {
        setBit(data, startBit + i, (raw >> i) & 1u);
    }
}

static inline uint16_t BENextBit(uint16_t currentBit) {
    uint16_t byte = currentBit / 8;
    uint16_t bit = currentBit % 8;

    if (bit == 0) {
        return uint16_t((byte + 1) * 8 + 7);
    }
    return uint16_t(byte * 8 + (bit - 1));
}

static inline uint64_t extractRawBE(const std::array<uint8_t, 8>& data,
                                    uint16_t startBit,
                                    uint8_t length) {
    assert(length >= 1 && length <= 64);
    uint64_t raw = 0;
    uint16_t p = startBit;

    for (uint8_t i = 0; i < length; ++i) {
        raw = (raw << 1) | (uint64_t)getBit(data, p);
        p = BENextBit(p);
    }
    return raw;
}

static inline void insertRawBE(std::array<uint8_t, 8>& data,
                               uint16_t startBit,
                               uint8_t length,
                               uint64_t raw) {
    assert(length >= 1 && length <= 64);
    uint16_t p = startBit;

    for (uint8_t i = 0; i < length; ++i) {
        uint8_t bit = (raw >> (length - 1 - i)) & 1u;
        setBit(data, p, bit);
        p = BENextBit(p);
    }
}

static inline int64_t signExtend(uint64_t raw, uint8_t length) {
    if (length == 64)
        return (int64_t)raw;
    uint64_t sign = 1ULL << (length - 1);
    if (raw & sign) {
        uint64_t mask = ~((1ULL << length) - 1ULL);
        return (int64_t)(raw | mask);
    }
    return (int64_t)raw;
}

static inline uint64_t maskN(uint8_t n) {
    return (n == 64) ? ~0ULL : ((1ULL << n) - 1ULL);
}

#endif  // __CAN_INTERFACE_H__
