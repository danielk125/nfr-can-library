#ifndef __STM32f4_H__
#define __STM32f4_H__

#include "../../nfr_can/ICAN.hpp"
#include "stm32f4xx_hal.h"
#include <cstdint>
#include <memory>

class STM32F4_CAN : public ICAN {
private:
    CAN_HandleTypeDef* _hcan;
    uint32_t _TxMailBox;

public:
    STM32F4_CAN(CAN_HandleTypeDef* hcan);

    
    bool init(const BaudRate baudrate) override; 
    /*
        NOTE:   BaudRate is a dummy parameter and shoud be configured by CubeMX. 
                Pass BuadRate::NONE. 
                This will be fixed in future versions of the library.
    */ 
    bool send(const CAN_Frame& msg) override;
    bool recv(CAN_Frame& msg) override;

    uint32_t time_ms() override; // dummy function for now

    uint32_t getTxMailBox();
};

# endif // __STM32f4_H__
