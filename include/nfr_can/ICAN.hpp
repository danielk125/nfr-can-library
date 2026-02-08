#ifndef ICAN_HPP
#define ICAN_HPP
#include <array>

struct CAN_Frame {
    uint32_t _id{};
    uint8_t _length{};
    std::array<uint8_t, 8> _data{};
    bool _extendedId{};

    CAN_Frame() = default;

    CAN_Frame(uint32_t id, uint8_t length, std::array<uint8_t, 8> data, bool extended)
        : _id(id), _length(length), _data(data), _extendedId(extended) {
    }
};

enum class BaudRate {
    kBaud1M = 1000000,
    kBaud500K = 500000,
    kBaud250K = 250000,
    kBaud125k = 125000
};

struct ICAN {
    virtual ~ICAN() = default;

    virtual bool init(const BaudRate baudrate) = 0;
    virtual bool send(const CAN_Frame& msg) = 0;
    virtual bool recv(CAN_Frame& msg) = 0;
    virtual uint32_t time_ms() = 0;
};

#endif