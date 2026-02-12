#ifndef STM32F4CAN_HPP
#define STM32F4CAN_HPP

#include "../../nfr_can/ICAN.hpp"

class STM32F4Can final : public ICAN {
public:
  bool init(const BaudRate baudrate) override;
  bool send(const CAN_Frame &msg) override;
  bool recv(CAN_Frame &msg) override;
  uint32_t time_ms() override;
};

#endif