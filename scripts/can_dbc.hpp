#include "CAN_interface.cpp"
namespace CANDBC {
CAN_Signal_FLOAT GenAmps = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT FrontFanAmps = MakeSignalSigned(float, 16, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT RearFanAmps = MakeSignalSigned(float, 24, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT FrontPumpAmps = MakeSignalSigned(float, 32, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT RearPumpAmps = MakeSignalSigned(float, 40, 8, 0.01, 0.0, True);
RX_CAN_Message(5) PdmCurrent{DriveBus, 0x2A1, GenAmps, FrontFanAmps, RearFanAmps, FrontPumpAmps, RearPumpAmps};

CAN_Signal_FLOAT BatVolt = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_BOOL LowBatVoltWarning = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_BOOL DangerBatVoltWarning = MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True);
RX_CAN_Message(3) PdmBatVolt{DriveBus, 0x2A2, BatVolt, LowBatVoltWarning, DangerBatVoltWarning};

CAN_Signal_INT16 Rpm = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 MotorCurrent = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 DcVoltage = MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True);
CAN_Signal_INT16 DcCurrent = MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True);
RX_CAN_Message(4) FrontRightInverterMotorStatus{DriveBus, 0x28B, Rpm, MotorCurrent, DcVoltage, DcCurrent};

CAN_Signal_INT16 IgbtTemp = MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True);
CAN_Signal_INT16 MotorTemp = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
RX_CAN_Message(2) FrontRightInverterTempStatus{DriveBus, 0x28C, IgbtTemp, MotorTemp};

CAN_Signal_UINT32 AhCharged = MakeSignalExp(uint32_t, 32, 32, 0.0001, 0.0);
RX_CAN_Message(1) FrontRightInverterCurrentDraw{DriveBus, nan, AhCharged};

CAN_Signal_UINT32 WhDrawn = MakeSignalExp(uint32_t, 0, 32, 0.001, 0.0);
CAN_Signal_UINT32 WhCharged = MakeSignalExp(uint32_t, 32, 32, 0.001, 0.0);
RX_CAN_Message(2) FrontRightInverterPowerDraw{DriveBus, 0x28E, WhDrawn, WhCharged};

CAN_Signal_UINT8 FaultCode = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
RX_CAN_Message(1) FrontRightInverterFaultStatus{DriveBus, 0x28A, FaultCode};

RX_CAN_Message(4) FrontLeftInverterMotorStatus{DriveBus, 0x286, Rpm, MotorCurrent, DcVoltage, DcCurrent};

RX_CAN_Message(2) FrontLeftInverterTempStatus{DriveBus, 0x287, IgbtTemp, MotorTemp};

RX_CAN_Message(1) FrontLeftInverterCurrentDraw{DriveBus, nan, AhCharged};

RX_CAN_Message(2) FrontLeftInverterPowerDraw{DriveBus, 0x289, WhDrawn, WhCharged};

RX_CAN_Message(1) FrontLeftInverterFaultStatus{DriveBus, 0x285, FaultCode};

RX_CAN_Message(6) RearInverterMotorStatus{DriveBus, 0x281, Rpm, MotorCurrent, DcVoltage, DcCurrent, IgbtTemp, MotorTemp};

RX_CAN_Message(1) RearInverterCurrentDraw{DriveBus, nan, AhCharged};

RX_CAN_Message(2) RearInverterPowerDraw{DriveBus, 0x284, WhDrawn, WhCharged};

RX_CAN_Message(1) RearInverterFaultStatus{DriveBus, 0x280, FaultCode};

CAN_Signal_INT32 SetCurrent = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);
RX_CAN_Message(1) EcuSetCurrentFrontLeftInverter{DriveBus, 0x20D, SetCurrent};

CAN_Signal_INT32 SetCurrentBrake = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);
RX_CAN_Message(1) EcuSetCurrentBrakeFrontLeftInverter{DriveBus, 0x20E, SetCurrentBrake};

RX_CAN_Message(1) EcuSetCurrentFrontRightInverter{DriveBus, 0x20F, SetCurrent};

RX_CAN_Message(1) EcuSetCurrentBrakeFrontRightInverter{DriveBus, 0x210, SetCurrentBrake};

RX_CAN_Message(1) EcuSetCurrentRearInverter{DriveBus, 0x200, SetCurrent};

RX_CAN_Message(1) EcuSetCurrentBrakeRearInverter{DriveBus, 0x201, SetCurrentBrake};

CAN_Signal_INT16 Apps1Throttle = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 Apps2Throttle = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
RX_CAN_Message(2) EcuThrottle{DriveBus, 0x202, Apps1Throttle, Apps2Throttle};

CAN_Signal_INT16 FrontBrakePressure = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 RearBrakePressure = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_BOOL BrakePressed = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);
RX_CAN_Message(3) EcuBrake{DriveBus, 0x203, FrontBrakePressure, RearBrakePressure, BrakePressed};

CAN_Signal_BOOL ImplausibilityPresent = MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True);
CAN_Signal_BOOL AppssDisagreementImp = MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True);
CAN_Signal_BOOL BppcImp = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_BOOL BrakeInvalidImp = MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True);
CAN_Signal_BOOL AppssInvalidImp = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);
RX_CAN_Message(5) EcuImplausibility{DriveBus, 0x204, ImplausibilityPresent, AppssDisagreementImp, BppcImp, BrakeInvalidImp, AppssInvalidImp};

CAN_Signal_UINT8 BmsCommand = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
RX_CAN_Message(1) EcuBmsCommandMessage{DriveBus, 0x205, BmsCommand};

CAN_Signal_UINT8 DriveState = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
RX_CAN_Message(1) EcuDriveStatus{DriveBus, 0x206, DriveState};

CAN_Signal_BOOL ActiveAeroState = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_INT16 ActiveAeroPosition = MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True);
RX_CAN_Message(2) EcuActiveAeroCommand{DriveBus, 0x208, ActiveAeroState, ActiveAeroPosition};

CAN_Signal_UINT8 FrontPumpDutyCycle = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 RearPumpDutyCycle = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontFanDutyCycle = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 RearPumpDutyCycle = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);
RX_CAN_Message(4) EcuPumpFanCommand{DriveBus, 0x209, FrontPumpDutyCycle, RearPumpDutyCycle, FrontFanDutyCycle, RearPumpDutyCycle};

CAN_Signal_UINT8 AccelLutIdResponse = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
RX_CAN_Message(1) EcuLutResponse{DriveBus, 0x20A, AccelLutIdResponse};

CAN_Signal_BOOL IgbtTempLimiting = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL BatteryTempLimiting = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL MotorTempLimiting = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
RX_CAN_Message(3) EcuTempLimitingStatus{DriveBus, 0x20B, IgbtTempLimiting, BatteryTempLimiting, MotorTempLimiting};

CAN_Signal_UINT8 TorqueStatus = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
RX_CAN_Message(1) EcuTorqueStatus{DriveBus, 0x20C, TorqueStatus};

CAN_Signal_UINT8 EcuEnableResponse = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsEnableResponse = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 PdmEnableResponse = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
RX_CAN_Message(3) CmRequestDrivetrain{DriveBus, 0x490, EcuEnableResponse, BmsEnableResponse, PdmEnableResponse};

CAN_Signal_UINT8 DynamicsEnableResponse = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontEnableResponse = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 TelemetryEnableResponse = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
RX_CAN_Message(3) CmRequestDaq{DriveBus, 0x491, DynamicsEnableResponse, FrontEnableResponse, TelemetryEnableResponse};

CAN_Signal_UINT8 BlEnableResponse = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BrEnableResponse = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FlEnableResponse = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrEnableResponse = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);
RX_CAN_Message(4) CmRequestWheel{DriveBus, 0x492, BlEnableResponse, BrEnableResponse, FlEnableResponse, FrEnableResponse};

CAN_Signal_UINT64 Counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
RX_CAN_Message(1) CmResponseEcu{DriveBus, 0x590, Counter};

RX_CAN_Message(1) CmResponseBms{DriveBus, 0x591, Counter};

RX_CAN_Message(1) CmResponsePdm{DriveBus, 0x592, Counter};

RX_CAN_Message(1) CmResponseDynamics{DriveBus, 0x593, Counter};

RX_CAN_Message(1) CmResponseFront{DriveBus, 0x594, Counter};

RX_CAN_Message(1) CmResponseTelemetry{DriveBus, 0x595, Counter};

RX_CAN_Message(1) CmResponseBl{DriveBus, 0x596, Counter};

RX_CAN_Message(1) CmResponseBr{DriveBus, 0x597, Counter};

RX_CAN_Message(1) CmResponseFl{DriveBus, 0x598, Counter};

RX_CAN_Message(1) CmResponseFr{DriveBus, 0x599, Counter};

CAN_Signal_UINT8 EcuStatus = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsStatus = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 PdmStatus = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
RX_CAN_Message(3) CmNodeStatusDrivetrain{DriveBus, 0x192, EcuStatus, BmsStatus, PdmStatus};

CAN_Signal_UINT8 DynamicsStatus = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontStatus = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 TelemetryStatus = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
RX_CAN_Message(3) CmNodeStatusDaq{DriveBus, 0x193, DynamicsStatus, FrontStatus, TelemetryStatus};

CAN_Signal_UINT8 BlStatus = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BrStatus = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FlStatus = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrStatus = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);
RX_CAN_Message(4) CmNodeStatusWheel{DriveBus, 0x194, BlStatus, BrStatus, FlStatus, FrStatus};

CAN_Signal_FLOAT MaxDischargeCurrent = MakeSignalSigned(float, 0, 12, 0.1, 0.0, True);
CAN_Signal_FLOAT MaxRegenCurrent = MakeSignalSigned(float, 12, 12, 0.1, 0.0, True);
CAN_Signal_FLOAT BatteryVoltage = MakeSignalSigned(float, 24, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT BatteryTemperature = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT BatteryCurrent = MakeSignalSigned(float, 48, 16, 0.01, -100.0, True);
RX_CAN_Message(5) BmsSoe{DriveBus, 0x150, MaxDischargeCurrent, MaxRegenCurrent, BatteryVoltage, BatteryTemperature, BatteryCurrent};

CAN_Signal_BOOL InternalfaultSummary = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL ExternalFault = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL UndervoltageFault = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvervoltageFault = MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True);
CAN_Signal_BOOL UndertemperatureFault = MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvertemperatureFault = MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvercurrentFault = MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OpenWireFault = MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OpenWireTempFault = MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True);
CAN_Signal_BOOL PecFault = MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True);
CAN_Signal_UINT8 TotalPecFailures = MakeSignalExp(uint8_t, 10, 8, 1.0, 0.0);
RX_CAN_Message(11) BmsFaults{DriveBus, 0x151, InternalfaultSummary, ExternalFault, UndervoltageFault, OvervoltageFault, UndertemperatureFault, OvertemperatureFault, OvercurrentFault, OpenWireFault, OpenWireTempFault, PecFault, TotalPecFailures};

CAN_Signal_UINT8 BmsState = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 ImdState = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_FLOAT MaxCellTemp = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT MinCellTemp = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT MaxCellVoltage = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT MinCellVoltage = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT BmsSoc = MakeSignalSigned(float, 48, 8, 0.004, 0.0, True);
RX_CAN_Message(7) BmsStatus{DriveBus, 0x152, BmsState, ImdState, MaxCellTemp, MinCellTemp, MaxCellVoltage, MinCellVoltage, BmsSoc};

CAN_Signal_FLOAT CellV0 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV1 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV2 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV3 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV4 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV5 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV6 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset0 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages0{DriveBus, 0x153, CellV0, CellV1, CellV2, CellV3, CellV4, CellV5, CellV6, CellOcvOffset0};

CAN_Signal_FLOAT CellV7 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV8 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV9 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV10 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV11 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV12 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV13 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset1 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages1{DriveBus, 0x154, CellV7, CellV8, CellV9, CellV10, CellV11, CellV12, CellV13, CellOcvOffset1};

CAN_Signal_FLOAT CellV14 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV15 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV16 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV17 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV18 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV19 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV20 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset2 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages2{DriveBus, 0x155, CellV14, CellV15, CellV16, CellV17, CellV18, CellV19, CellV20, CellOcvOffset2};

CAN_Signal_FLOAT CellV21 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV22 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV23 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV24 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV25 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV26 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV27 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset3 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages3{DriveBus, 0x156, CellV21, CellV22, CellV23, CellV24, CellV25, CellV26, CellV27, CellOcvOffset3};

CAN_Signal_FLOAT CellV28 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV29 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV30 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV31 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV32 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV33 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV34 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset4 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages4{DriveBus, 0x157, CellV28, CellV29, CellV30, CellV31, CellV32, CellV33, CellV34, CellOcvOffset4};

CAN_Signal_FLOAT CellV35 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV36 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV37 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV38 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV39 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV40 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV41 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset5 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages5{DriveBus, 0x158, CellV35, CellV36, CellV37, CellV38, CellV39, CellV40, CellV41, CellOcvOffset5};

CAN_Signal_FLOAT CellV42 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV43 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV44 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV45 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV46 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV47 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV48 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset6 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages6{DriveBus, 0x159, CellV42, CellV43, CellV44, CellV45, CellV46, CellV47, CellV48, CellOcvOffset6};

CAN_Signal_FLOAT CellV49 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV50 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV51 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV52 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV53 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV54 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV55 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset7 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages7{DriveBus, 0x15A, CellV49, CellV50, CellV51, CellV52, CellV53, CellV54, CellV55, CellOcvOffset7};

CAN_Signal_FLOAT CellV56 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV57 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV58 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV59 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV60 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV61 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV62 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset8 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages8{DriveBus, 0x15B, CellV56, CellV57, CellV58, CellV59, CellV60, CellV61, CellV62, CellOcvOffset8};

CAN_Signal_FLOAT CellV63 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV64 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV65 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV66 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV67 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV68 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV69 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset9 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages9{DriveBus, 0x15C, CellV63, CellV64, CellV65, CellV66, CellV67, CellV68, CellV69, CellOcvOffset9};

CAN_Signal_FLOAT CellV70 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV71 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV72 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV73 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV74 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV75 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV76 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset10 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages10{DriveBus, 0x15D, CellV70, CellV71, CellV72, CellV73, CellV74, CellV75, CellV76, CellOcvOffset10};

CAN_Signal_FLOAT CellV77 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV78 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV79 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV80 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV81 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV82 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV83 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset11 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages11{DriveBus, 0x15E, CellV77, CellV78, CellV79, CellV80, CellV81, CellV82, CellV83, CellOcvOffset11};

CAN_Signal_FLOAT CellV84 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV85 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV86 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV87 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV88 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV89 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV90 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset12 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages12{DriveBus, 0x15F, CellV84, CellV85, CellV86, CellV87, CellV88, CellV89, CellV90, CellOcvOffset12};

CAN_Signal_FLOAT CellV91 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV92 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV93 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV94 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV95 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV96 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV97 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset13 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages13{DriveBus, 0x160, CellV91, CellV92, CellV93, CellV94, CellV95, CellV96, CellV97, CellOcvOffset13};

CAN_Signal_FLOAT CellV98 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV99 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV100 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV101 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV102 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV103 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV104 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset14 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages14{DriveBus, 0x161, CellV98, CellV99, CellV100, CellV101, CellV102, CellV103, CellV104, CellOcvOffset14};

CAN_Signal_FLOAT CellV105 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV106 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV107 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV108 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV109 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV110 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV111 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset15 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages15{DriveBus, 0x162, CellV105, CellV106, CellV107, CellV108, CellV109, CellV110, CellV111, CellOcvOffset15};

CAN_Signal_FLOAT CellV112 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV113 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV114 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV115 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV116 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV117 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV118 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset16 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages16{DriveBus, 0x163, CellV112, CellV113, CellV114, CellV115, CellV116, CellV117, CellV118, CellOcvOffset16};

CAN_Signal_FLOAT CellV119 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV120 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV121 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV122 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV123 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV124 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV125 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset17 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages17{DriveBus, 0x164, CellV119, CellV120, CellV121, CellV122, CellV123, CellV124, CellV125, CellOcvOffset17};

CAN_Signal_FLOAT CellV126 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV127 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV128 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV129 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV130 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV131 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV132 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset18 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages18{DriveBus, 0x165, CellV126, CellV127, CellV128, CellV129, CellV130, CellV131, CellV132, CellOcvOffset18};

CAN_Signal_FLOAT CellV133 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV134 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV135 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV136 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV137 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV138 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellV139 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT CellOcvOffset19 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
RX_CAN_Message(8) BmsVoltages19{DriveBus, 0x166, CellV133, CellV134, CellV135, CellV136, CellV137, CellV138, CellV139, CellOcvOffset19};

CAN_Signal_FLOAT CellT0 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT1 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT2 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT3 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT4 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT5 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT6 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT7 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures0{DriveBus, 0x167, CellT0, CellT1, CellT2, CellT3, CellT4, CellT5, CellT6, CellT7};

CAN_Signal_FLOAT CellT8 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT9 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT10 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT11 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT12 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT13 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT14 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT15 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures1{DriveBus, 0x168, CellT8, CellT9, CellT10, CellT11, CellT12, CellT13, CellT14, CellT15};

CAN_Signal_FLOAT CellT16 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT17 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT18 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT19 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT20 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT21 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT22 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT23 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures2{DriveBus, 0x169, CellT16, CellT17, CellT18, CellT19, CellT20, CellT21, CellT22, CellT23};

CAN_Signal_FLOAT CellT24 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT25 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT26 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT27 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT28 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT29 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT30 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT31 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures3{DriveBus, 0x16A, CellT24, CellT25, CellT26, CellT27, CellT28, CellT29, CellT30, CellT31};

CAN_Signal_FLOAT CellT32 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT33 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT34 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT35 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT36 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT37 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT38 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT39 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures4{DriveBus, 0x16B, CellT32, CellT33, CellT34, CellT35, CellT36, CellT37, CellT38, CellT39};

CAN_Signal_FLOAT CellT40 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT41 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT42 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT43 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT44 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT45 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT46 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT47 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures5{DriveBus, 0x16C, CellT40, CellT41, CellT42, CellT43, CellT44, CellT45, CellT46, CellT47};

CAN_Signal_FLOAT CellT48 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT49 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT50 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT51 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT52 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT53 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT54 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT55 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures6{DriveBus, 0x16D, CellT48, CellT49, CellT50, CellT51, CellT52, CellT53, CellT54, CellT55};

CAN_Signal_FLOAT CellT56 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT57 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT58 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT59 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT60 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT61 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT62 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT63 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures7{DriveBus, 0x16E, CellT56, CellT57, CellT58, CellT59, CellT60, CellT61, CellT62, CellT63};

CAN_Signal_FLOAT CellT64 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT65 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT66 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT67 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT68 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT69 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT70 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT71 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures8{DriveBus, 0x16F, CellT64, CellT65, CellT66, CellT67, CellT68, CellT69, CellT70, CellT71};

CAN_Signal_FLOAT CellT72 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT73 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT74 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT75 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT76 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT77 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT78 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT CellT79 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
RX_CAN_Message(8) BmsTemperatures9{DriveBus, 0x170, CellT72, CellT73, CellT74, CellT75, CellT76, CellT77, CellT78, CellT79};

CAN_Signal_UINT64 ControllerError = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
RX_CAN_Message(1) Can2usbControllerError{DriveBus, 0x004, ControllerError};

CAN_Signal_UINT64 ControllerErrorNack = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
RX_CAN_Message(1) Can2usbControllerErrorNackError{DriveBus, 0x024, ControllerErrorNack};

CAN_Signal_UINT64 ControllerErrorProtocolViolation = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
RX_CAN_Message(1) Can2usbControllerErrorProtocolViolation{DriveBus, 0x00C, ControllerErrorProtocolViolation};

}