#include "STM32F4.hpp"
#include "STM32f4.hpp"
#include <memory.h>

STM32F4_CAN::STM32F4_CAN(CAN_HandleTypeDef* hcan) : _hcan(hcan) {};

bool STM32F4_CAN::init(const BaudRate baudrate) {
    if (baudrate != BaudRate::NONE) return false; // Ensure that user is aware that baudrate is meaningless

    int started = HAL_CAN_START(*_hcan);

    if (started != HAL_OK) {
        std::cout << "HAL CAN Failed to start.\n";
        return false;
    }

    int noti_activated = HAL_CAN_ActivateNotification(*_hcan, CAN_IT_RX_FIFO0_MSG_PENDING);

    if (!noti_activated) {
        std::cout << "Failed to activate CAN interrupts.\n";
        return false;
    }
    
    return true;
}

bool STM32F4_CAN::send(const CAN_Frame& msg) {
    if (HAL_CAN_GetTxMailboxesFreeLevel(*_hcan) > 0) {
        CAN_TxHeaderTypeDef TxHeader;

        if (msg._extendedId) {
            TxHeader.ExtId = msg._id;
            TxHeader.IDE = CAN_ID_EXT;
        } else {
            TxHeader.StdId = msg._id;
            TxHeader.IDE = CAN_ID_STD;
        }

        TxHeader.RTR = CAN_RTR_DATA;
        TxHeader.DLC = msg._length;

        HAL_StatusTypeDef msg_status = HAL_CAN_AddTxMessage(*_hcan, &TxHeader, msg._data.data(), &_TxMailBox);

        if (msg_status != HAL_OK) {
            std::cout << "Failed to send CAN message. Status:" << msg_status << '\n';
            return false;
        }

        return true;
    }

    return false;
}

bool STM32F4_CAN::recv(CAN_Frame& msg) {
    CAN_RxHeaderTypeDef RxHeader;                                                                       
    uint8_t rx_data[8];
                                                                                                        
    if (HAL_CAN_GetRxFifoFillLevel(*_hcan, CAN_RX_FIFO0) == 0)                                             
        return false;
                                                                                                        
    HAL_StatusTypeDef msg_status = HAL_CAN_GetRxMessage(*_hcan, CAN_RX_FIFO0, &RxHeader, rx_data);
    
    if (msg_status != HAL_OK) {
        std::cout << "Failed to recv CAN message. Status:" << msg_status << '\n';
        return false;
    }

    if (RxHeader.IDE == CAN_ID_EXT) {
        msg._id = RxHeader.ExtId;
        msg._extendedId = true;
    } else {
        msg._id = RxHeader.StdId;
        msg._extendedId = false;
    }
                                                                         
    msg._length = RxHeader.DLC;                                             
    memcpy(msg._data, rx_data, RxHeader.DLC);                                                          
    return true;
}

uint32_t STM32F4_CAN::time_ms() { return 0; }

uint32_t STM32F4_CAN::getTxMailBox() { return _TxMailBox; }
