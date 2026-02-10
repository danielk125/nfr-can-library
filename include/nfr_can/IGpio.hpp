#ifndef IGPIO_HPP
#define IGPIO_HPP
#include <cstdint>

enum class GpioLevel : uint8_t { G_LOW = 0, G_HIGH = 1, G_UNDEF = 2};

struct IGpio {
    virtual ~IGpio() = default;

    virtual bool gpio_write(GpioLevel level) = 0;

    virtual bool gpio_read(GpioLevel& out) = 0;
};

#endif
