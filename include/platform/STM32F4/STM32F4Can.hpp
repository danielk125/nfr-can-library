#ifndef STM32F4CAN_HPP
#define STM32F4CAN_HPP

#include "../../nfr_can/ICAN.hpp"
#include "stm32f4xx_hal_can.h"

class STM32F4Can final : public ICAN {
public:
  // TODO: hardcoded to 500k rn - make configurable later
  bool init(const BaudRate baudrate) override {
    _hcan.Instance = CAN1;
    _hcan.Init.Prescaler = 4;
    _hcan.Init.Mode = CAN_MODE_NORMAL;
    _hcan.Init.SyncJumpWidth = CAN_SJW_1TQ;
    _hcan.Init.TimeSeg1 = CAN_BS1_16TQ;
    _hcan.Init.TimeSeg2 = CAN_BS2_4TQ;
    _hcan.Init.TimeTriggeredMode = DISABLE;
    _hcan.Init.AutoBusOff = DISABLE;
    _hcan.Init.AutoWakeUp = DISABLE;
    _hcan.Init.AutoRetransmission = DISABLE;
    _hcan.Init.ReceiveFifoLocked = DISABLE;
    _hcan.Init.TransmitFifoPriority = DISABLE;
    HAL_StatusTypeDef status = HAL_CAN_Init(&_hcan);

    // setup filters
    // listening to all messages for now
    // TODO: make filtering configurable
    _canFilterConfig.FilterActivation = CAN_FILTER_ENABLE;
    _canFilterConfig.FilterBank = 0;
    _canFilterConfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
    _canFilterConfig.FilterIdHigh = 0;
    _canFilterConfig.FilterIdLow = 0;
    _canFilterConfig.FilterMaskIdHigh = 0;
    _canFilterConfig.FilterMaskIdLow = 0;
    _canFilterConfig.FilterMode = CAN_FILTERMODE_IDMASK;
    _canFilterConfig.FilterScale = CAN_FILTERSCALE_32BIT;
    _canFilterConfig.SlaveStartFilterBank = 14;

    status = HAL_CAN_ConfigFilter(&_hcan, &_canFilterConfig);

    // setup rx interrupt if we want it
    // HAL_CAN_ActivateNotification(&_hcan, CAN_IT_RX_FIFO0_MSG_PENDING);

    status = HAL_CAN_Start(&_hcan);

    return (status == HAL_OK) ? true : false;
  }

  bool send(const CAN_Frame &msg) override {
    // populate header
    CAN_TxHeaderTypeDef txHeader;
    txHeader.IDE = (msg._extendedId) ? CAN_ID_EXT : CAN_ID_STD;
    txHeader.StdId = msg._id;
    txHeader.RTR = CAN_RTR_DATA; // only supporting data frames
    txHeader.DLC = msg._length;

    // populate data
    auto status =
        HAL_CAN_AddTxMessage(&_hcan, &txHeader, msg._data.data(), &_txMailbox);
  }

  bool recv(CAN_Frame &msg) override;

  uint32_t time_ms() override;

private:
  CAN_HandleTypeDef _hcan;
  CAN_FilterTypeDef _canFilterConfig;
  uint32_t _txMailbox;
};

#endif