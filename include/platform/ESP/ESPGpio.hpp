#ifndef IGPIO_HPP
#define IGPIO_HPP

#include "../../nfr_can/IGpio.hpp"
#include <Arduino.h>

#endif

enum class GpioMode : uint8_t { G_OUTPUT = 0, G_INPUT = 1};

class ESPGpio final : public IGpio {
    uint32_t _pin;
    GpioMode _mode;

public:
    ESPGpio(uint32_t pin, GpioMode mode) : _pin(pin), _mode(mode) {
        pinMode(_pin, mode == GpioMode::G_OUTPUT ? OUTPUT : INPUT);
    }

    bool gpio_write(GpioLevel level) override {
        if (_mode == GpioMode::G_INPUT || level == GpioLevel::G_UNDEF) return false;

        digitalWrite(_pin, level == GpioLevel::G_HIGH ? HIGH : LOW);

        return true;
    }

    bool gpio_read(GpioLevel& out) override {
        if (_mode == GpioMode::G_OUTPUT) return false

        out = digitalRead(_pin) ? GpioLevel::G_HIGH : GpioLevel::G_LOW;
        return true;
    }
};
