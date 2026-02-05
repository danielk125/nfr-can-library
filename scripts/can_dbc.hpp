#include "../include/CAN_interface.hpp"
namespace CANDBC {
CAN_Signal_FLOAT GenAmps = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT FrontFanAmps = MakeSignalSigned(float, 16, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT RearFanAmps = MakeSignalSigned(float, 24, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT FrontPumpAmps = MakeSignalSigned(float, 32, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT RearPumpAmps = MakeSignalSigned(float, 40, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT GenAmps = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT FrontFanAmps = MakeSignalSigned(float, 16, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT RearFanAmps = MakeSignalSigned(float, 24, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT FrontPumpAmps = MakeSignalSigned(float, 32, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT RearPumpAmps = MakeSignalSigned(float, 40, 8, 0.01, 0.0, True);

RX_CAN_Message(5) PdmCurrent{DriveBus, 0x2A1, GenAmps, FrontFanAmps, RearFanAmps, FrontPumpAmps, RearPumpAmps};

CAN_Signal_FLOAT BatVolt = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_BOOL BatVoltWarning = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_FLOAT BatVolt = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_BOOL BatVoltWarning = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);

RX_CAN_Message(2) PdmBatVolt{DriveBus, 0x2A2, BatVolt, BatVoltWarning};

CAN_Signal_INT16 Rpm = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 MotorCurrent = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 DcVoltage = MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True);
CAN_Signal_INT16 DcCurrent = MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True);
CAN_Signal_INT16 Rpm = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 MotorCurrent = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 DcVoltage = MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True);
CAN_Signal_INT16 DcCurrent = MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True);

RX_CAN_Message(4) InverterMotorStatus{DriveBus, 0x281, Rpm, MotorCurrent, DcVoltage, DcCurrent};

CAN_Signal_INT16 IgbtTemp = MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True);
CAN_Signal_INT16 MotorTemp = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 IgbtTemp = MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True);
CAN_Signal_INT16 MotorTemp = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);

RX_CAN_Message(2) InverterTempStatus{DriveBus, 0x282, IgbtTemp, MotorTemp};

CAN_Signal_UINT32 AhCharged = MakeSignal(uint32_t, 32, 32, 0.0001, 0.0);
CAN_Signal_UINT32 AhCharged = MakeSignal(uint32_t, 32, 32, 0.0001, 0.0);

RX_CAN_Message(1) InverterCurrentDraw{DriveBus, nan, AhCharged};

CAN_Signal_UINT32 WhDrawn = MakeSignal(uint32_t, 0, 32, 0.001, 0.0);
CAN_Signal_UINT32 WhCharged = MakeSignal(uint32_t, 32, 32, 0.001, 0.0);
CAN_Signal_UINT32 WhDrawn = MakeSignal(uint32_t, 0, 32, 0.001, 0.0);
CAN_Signal_UINT32 WhCharged = MakeSignal(uint32_t, 32, 32, 0.001, 0.0);

RX_CAN_Message(2) InverterPowerDraw{DriveBus, 0x284, WhDrawn, WhCharged};

CAN_Signal_UINT8 FaultCode = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FaultCode = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) InverterFaultStatus{DriveBus, 0x280, FaultCode};

CAN_Signal_INT32 SetCurrent = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);
CAN_Signal_INT32 SetCurrent = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);

RX_CAN_Message(1) EcuSetCurrent{DriveBus, 0x200, SetCurrent};

CAN_Signal_INT32 SetCurrentBrake = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);
CAN_Signal_INT32 SetCurrentBrake = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);

RX_CAN_Message(1) EcuSetCurrentBrake{DriveBus, 0x201, SetCurrentBrake};

CAN_Signal_INT16 Apps1Throttle = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 Apps2Throttle = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_INT16 Apps1Throttle = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 Apps2Throttle = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);

RX_CAN_Message(2) EcuThrottle{DriveBus, 0x202, Apps1Throttle, Apps2Throttle};

CAN_Signal_INT16 FrontBrakePressure = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 RearBrakePressure = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_BOOL BrakePressed = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);
CAN_Signal_INT16 FrontBrakePressure = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 RearBrakePressure = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_BOOL BrakePressed = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);

RX_CAN_Message(3) EcuBrake{DriveBus, 0x203, FrontBrakePressure, RearBrakePressure, BrakePressed};

CAN_Signal_BOOL ImplausibilityPresent = MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True);
CAN_Signal_BOOL AppssDisagreementImp = MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True);
CAN_Signal_BOOL BppcImp = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_BOOL BrakeInvalidImp = MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True);
CAN_Signal_BOOL AppssInvalidImp = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);
CAN_Signal_BOOL ImplausibilityPresent = MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True);
CAN_Signal_BOOL AppssDisagreementImp = MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True);
CAN_Signal_BOOL BppcImp = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_BOOL BrakeInvalidImp = MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True);
CAN_Signal_BOOL AppssInvalidImp = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);

RX_CAN_Message(5) EcuImplausibility{DriveBus, 0x204, ImplausibilityPresent, AppssDisagreementImp, BppcImp, BrakeInvalidImp, AppssInvalidImp};

CAN_Signal_UINT8 BmsCommand = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsCommand = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) EcuBmsCommandMessage{DriveBus, 0x205, BmsCommand};

CAN_Signal_UINT8 DriveState = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 DriveState = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) EcuDriveStatus{DriveBus, 0x206, DriveState};

CAN_Signal_BOOL ActiveAeroState = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_INT16 ActiveAeroPosition = MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True);
CAN_Signal_BOOL ActiveAeroState = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_INT16 ActiveAeroPosition = MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True);

RX_CAN_Message(2) EcuActiveAeroCommand{DriveBus, 0x208, ActiveAeroState, ActiveAeroPosition};

CAN_Signal_UINT8 FrontPumpDutyCycle = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 RearPumpDutyCycle = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontFanDutyCycle = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 RearPumpDutyCycle = MakeSignal(uint8_t, 24, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontPumpDutyCycle = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 RearPumpDutyCycle = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontFanDutyCycle = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 RearPumpDutyCycle = MakeSignal(uint8_t, 24, 8, 1.0, 0.0);

RX_CAN_Message(4) EcuPumpFanCommand{DriveBus, 0x209, FrontPumpDutyCycle, RearPumpDutyCycle, FrontFanDutyCycle, RearPumpDutyCycle};

CAN_Signal_UINT8 AccelLutIdResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 AccelLutIdResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) EcuLutResponse{DriveBus, 0x20A, AccelLutIdResponse};

CAN_Signal_BOOL IgbtTempLimiting = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL BatteryTempLimiting = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL MotorTempLimiting = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL IgbtTempLimiting = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL BatteryTempLimiting = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL MotorTempLimiting = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);

RX_CAN_Message(3) EcuTempLimitingStatus{DriveBus, 0x20B, IgbtTempLimiting, BatteryTempLimiting, MotorTempLimiting};

CAN_Signal_UINT8 TorqueStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 TorqueStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) EcuTorqueStatus{DriveBus, 0x20C, TorqueStatus};

CAN_Signal_UINT8 EcuEnableResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsEnableResponse = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 PdmEnableResponse = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 EcuEnableResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsEnableResponse = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 PdmEnableResponse = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) CmRequestDrivetrain{DriveBus, 0x490, EcuEnableResponse, BmsEnableResponse, PdmEnableResponse};

CAN_Signal_UINT8 DynamicsEnableResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontEnableResponse = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 TelemetryEnableResponse = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 DynamicsEnableResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontEnableResponse = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 TelemetryEnableResponse = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) CmRequestDaq{DriveBus, 0x491, DynamicsEnableResponse, FrontEnableResponse, TelemetryEnableResponse};

CAN_Signal_UINT8 BlEnableResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BrEnableResponse = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FlEnableResponse = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrEnableResponse = MakeSignal(uint8_t, 24, 8, 1.0, 0.0);
CAN_Signal_UINT8 BlEnableResponse = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BrEnableResponse = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FlEnableResponse = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrEnableResponse = MakeSignal(uint8_t, 24, 8, 1.0, 0.0);

RX_CAN_Message(4) CmRequestWheel{DriveBus, 0x492, BlEnableResponse, BrEnableResponse, FlEnableResponse, FrEnableResponse};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseEcu{DriveBus, 0x590, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseBms{DriveBus, 0x591, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponsePdm{DriveBus, 0x592, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseDynamics{DriveBus, 0x593, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseFront{DriveBus, 0x594, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseTelemetry{DriveBus, 0x595, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseBl{DriveBus, 0x596, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseBr{DriveBus, 0x597, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseFl{DriveBus, 0x598, Counter};

CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 Counter = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) CmResponseFr{DriveBus, 0x599, Counter};

CAN_Signal_UINT8 EcuStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsStatus = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 PdmStatus = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 EcuStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BmsStatus = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 PdmStatus = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) CmNodeStatusDrivetrain{DriveBus, 0x192, EcuStatus, BmsStatus, PdmStatus};

CAN_Signal_UINT8 DynamicsStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontStatus = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 TelemetryStatus = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 DynamicsStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrontStatus = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 TelemetryStatus = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) CmNodeStatusDaq{DriveBus, 0x193, DynamicsStatus, FrontStatus, TelemetryStatus};

CAN_Signal_UINT8 BlStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BrStatus = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FlStatus = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrStatus = MakeSignal(uint8_t, 24, 8, 1.0, 0.0);
CAN_Signal_UINT8 BlStatus = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 BrStatus = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 FlStatus = MakeSignal(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 FrStatus = MakeSignal(uint8_t, 24, 8, 1.0, 0.0);

RX_CAN_Message(4) CmNodeStatusWheel{DriveBus, 0x194, BlStatus, BrStatus, FlStatus, FrStatus};

CAN_Signal_UNSIGNED_FLOAT MaxDischargeCurrent = MakeSignal(unsigned_float, 0, 12, 0.1, 0.0);
CAN_Signal_UNSIGNED_FLOAT MaxRegenCurrent = MakeSignal(unsigned_float, 12, 12, 0.1, 0.0);
CAN_Signal_UNSIGNED_FLOAT BatteryVoltage = MakeSignal(unsigned_float, 24, 16, 0.01, 0.0);
CAN_Signal_UNSIGNED_FLOAT BatteryTemperature = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT BatteryCurrent = MakeSignal(unsigned_float, 48, 16, 0.01, -100.0);
CAN_Signal_UNSIGNED_FLOAT MaxDischargeCurrent = MakeSignal(unsigned_float, 0, 12, 0.1, 0.0);
CAN_Signal_UNSIGNED_FLOAT MaxRegenCurrent = MakeSignal(unsigned_float, 12, 12, 0.1, 0.0);
CAN_Signal_UNSIGNED_FLOAT BatteryVoltage = MakeSignal(unsigned_float, 24, 16, 0.01, 0.0);
CAN_Signal_UNSIGNED_FLOAT BatteryTemperature = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT BatteryCurrent = MakeSignal(unsigned_float, 48, 16, 0.01, -100.0);

RX_CAN_Message(5) BmsSoe{DriveBus, 0x150, MaxDischargeCurrent, MaxRegenCurrent, BatteryVoltage, BatteryTemperature, BatteryCurrent};

CAN_Signal_BOOL FaultSummary = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL UndervoltageFault = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvervoltageFault = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL UndertemperatureFault = MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvertemperatureFault = MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvercurrentFault = MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True);
CAN_Signal_BOOL ExternalKillFault = MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OpenWireFault = MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OpenWireTempFault = MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True);
CAN_Signal_BOOL PecFault = MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True);
CAN_Signal_UINT8 TotalPecFailures = MakeSignal(uint8_t, 10, 8, 1.0, 0.0);
CAN_Signal_BOOL FaultSummary = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL UndervoltageFault = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvervoltageFault = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL UndertemperatureFault = MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvertemperatureFault = MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OvercurrentFault = MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True);
CAN_Signal_BOOL ExternalKillFault = MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OpenWireFault = MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True);
CAN_Signal_BOOL OpenWireTempFault = MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True);
CAN_Signal_BOOL PecFault = MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True);
CAN_Signal_UINT8 TotalPecFailures = MakeSignal(uint8_t, 10, 8, 1.0, 0.0);

RX_CAN_Message(11) BmsFaults{DriveBus, 0x151, FaultSummary, UndervoltageFault, OvervoltageFault, UndertemperatureFault, OvertemperatureFault, OvercurrentFault, ExternalKillFault, OpenWireFault, OpenWireTempFault, PecFault, TotalPecFailures};

CAN_Signal_UINT8 BmsState = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 ImdState = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UNSIGNED_FLOAT MaxCellTemp = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT MinCellTemp = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT MaxCellVoltage = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT MinCellVoltage = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT BmsSoc = MakeSignal(unsigned_float, 48, 8, 0.004, 0.0);
CAN_Signal_UINT8 BmsState = MakeSignal(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 ImdState = MakeSignal(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UNSIGNED_FLOAT MaxCellTemp = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT MinCellTemp = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT MaxCellVoltage = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT MinCellVoltage = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT BmsSoc = MakeSignal(unsigned_float, 48, 8, 0.004, 0.0);

RX_CAN_Message(7) BmsStatus{DriveBus, 0x152, BmsState, ImdState, MaxCellTemp, MinCellTemp, MaxCellVoltage, MinCellVoltage, BmsSoc};

CAN_Signal_UNSIGNED_FLOAT CellV0 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV1 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV2 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV3 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV4 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV5 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV6 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset0 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV0 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV1 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV2 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV3 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV4 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV5 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV6 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset0 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages0{DriveBus, 0x153, CellV0, CellV1, CellV2, CellV3, CellV4, CellV5, CellV6, CellOcvOffset0};

CAN_Signal_UNSIGNED_FLOAT CellV7 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV8 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV9 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV10 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV11 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV12 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV13 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset1 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV7 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV8 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV9 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV10 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV11 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV12 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV13 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset1 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages1{DriveBus, 0x154, CellV7, CellV8, CellV9, CellV10, CellV11, CellV12, CellV13, CellOcvOffset1};

CAN_Signal_UNSIGNED_FLOAT CellV14 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV15 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV16 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV17 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV18 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV19 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV20 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset2 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV14 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV15 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV16 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV17 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV18 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV19 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV20 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset2 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages2{DriveBus, 0x155, CellV14, CellV15, CellV16, CellV17, CellV18, CellV19, CellV20, CellOcvOffset2};

CAN_Signal_UNSIGNED_FLOAT CellV21 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV22 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV23 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV24 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV25 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV26 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV27 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset3 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV21 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV22 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV23 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV24 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV25 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV26 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV27 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset3 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages3{DriveBus, 0x156, CellV21, CellV22, CellV23, CellV24, CellV25, CellV26, CellV27, CellOcvOffset3};

CAN_Signal_UNSIGNED_FLOAT CellV28 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV29 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV30 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV31 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV32 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV33 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV34 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset4 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV28 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV29 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV30 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV31 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV32 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV33 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV34 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset4 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages4{DriveBus, 0x157, CellV28, CellV29, CellV30, CellV31, CellV32, CellV33, CellV34, CellOcvOffset4};

CAN_Signal_UNSIGNED_FLOAT CellV35 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV36 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV37 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV38 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV39 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV40 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV41 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset5 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV35 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV36 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV37 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV38 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV39 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV40 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV41 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset5 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages5{DriveBus, 0x158, CellV35, CellV36, CellV37, CellV38, CellV39, CellV40, CellV41, CellOcvOffset5};

CAN_Signal_UNSIGNED_FLOAT CellV42 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV43 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV44 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV45 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV46 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV47 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV48 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset6 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV42 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV43 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV44 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV45 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV46 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV47 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV48 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset6 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages6{DriveBus, 0x159, CellV42, CellV43, CellV44, CellV45, CellV46, CellV47, CellV48, CellOcvOffset6};

CAN_Signal_UNSIGNED_FLOAT CellV49 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV50 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV51 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV52 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV53 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV54 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV55 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset7 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV49 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV50 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV51 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV52 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV53 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV54 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV55 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset7 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages7{DriveBus, 0x15A, CellV49, CellV50, CellV51, CellV52, CellV53, CellV54, CellV55, CellOcvOffset7};

CAN_Signal_UNSIGNED_FLOAT CellV56 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV57 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV58 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV59 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV60 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV61 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV62 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset8 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV56 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV57 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV58 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV59 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV60 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV61 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV62 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset8 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages8{DriveBus, 0x15B, CellV56, CellV57, CellV58, CellV59, CellV60, CellV61, CellV62, CellOcvOffset8};

CAN_Signal_UNSIGNED_FLOAT CellV63 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV64 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV65 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV66 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV67 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV68 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV69 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset9 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV63 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV64 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV65 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV66 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV67 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV68 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV69 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset9 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages9{DriveBus, 0x15C, CellV63, CellV64, CellV65, CellV66, CellV67, CellV68, CellV69, CellOcvOffset9};

CAN_Signal_UNSIGNED_FLOAT CellV70 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV71 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV72 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV73 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV74 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV75 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV76 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset10 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV70 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV71 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV72 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV73 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV74 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV75 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV76 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset10 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages10{DriveBus, 0x15D, CellV70, CellV71, CellV72, CellV73, CellV74, CellV75, CellV76, CellOcvOffset10};

CAN_Signal_UNSIGNED_FLOAT CellV77 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV78 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV79 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV80 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV81 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV82 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV83 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset11 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV77 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV78 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV79 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV80 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV81 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV82 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV83 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset11 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages11{DriveBus, 0x15E, CellV77, CellV78, CellV79, CellV80, CellV81, CellV82, CellV83, CellOcvOffset11};

CAN_Signal_UNSIGNED_FLOAT CellV84 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV85 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV86 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV87 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV88 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV89 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV90 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset12 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV84 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV85 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV86 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV87 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV88 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV89 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV90 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset12 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages12{DriveBus, 0x15F, CellV84, CellV85, CellV86, CellV87, CellV88, CellV89, CellV90, CellOcvOffset12};

CAN_Signal_UNSIGNED_FLOAT CellV91 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV92 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV93 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV94 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV95 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV96 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV97 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset13 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV91 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV92 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV93 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV94 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV95 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV96 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV97 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset13 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages13{DriveBus, 0x160, CellV91, CellV92, CellV93, CellV94, CellV95, CellV96, CellV97, CellOcvOffset13};

CAN_Signal_UNSIGNED_FLOAT CellV98 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV99 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV100 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV101 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV102 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV103 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV104 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset14 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV98 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV99 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV100 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV101 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV102 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV103 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV104 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset14 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages14{DriveBus, 0x161, CellV98, CellV99, CellV100, CellV101, CellV102, CellV103, CellV104, CellOcvOffset14};

CAN_Signal_UNSIGNED_FLOAT CellV105 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV106 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV107 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV108 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV109 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV110 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV111 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset15 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV105 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV106 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV107 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV108 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV109 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV110 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV111 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset15 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages15{DriveBus, 0x162, CellV105, CellV106, CellV107, CellV108, CellV109, CellV110, CellV111, CellOcvOffset15};

CAN_Signal_UNSIGNED_FLOAT CellV112 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV113 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV114 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV115 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV116 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV117 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV118 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset16 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV112 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV113 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV114 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV115 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV116 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV117 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV118 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset16 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages16{DriveBus, 0x163, CellV112, CellV113, CellV114, CellV115, CellV116, CellV117, CellV118, CellOcvOffset16};

CAN_Signal_UNSIGNED_FLOAT CellV119 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV120 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV121 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV122 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV123 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV124 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV125 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset17 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV119 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV120 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV121 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV122 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV123 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV124 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV125 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset17 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages17{DriveBus, 0x164, CellV119, CellV120, CellV121, CellV122, CellV123, CellV124, CellV125, CellOcvOffset17};

CAN_Signal_UNSIGNED_FLOAT CellV126 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV127 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV128 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV129 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV130 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV131 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV132 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset18 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV126 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV127 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV128 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV129 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV130 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV131 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV132 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset18 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages18{DriveBus, 0x165, CellV126, CellV127, CellV128, CellV129, CellV130, CellV131, CellV132, CellOcvOffset18};

CAN_Signal_UNSIGNED_FLOAT CellV133 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV134 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV135 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV136 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV137 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV138 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV139 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset19 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);
CAN_Signal_UNSIGNED_FLOAT CellV133 = MakeSignal(unsigned_float, 0, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV134 = MakeSignal(unsigned_float, 8, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV135 = MakeSignal(unsigned_float, 16, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV136 = MakeSignal(unsigned_float, 24, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV137 = MakeSignal(unsigned_float, 32, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV138 = MakeSignal(unsigned_float, 40, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellV139 = MakeSignal(unsigned_float, 48, 8, 0.012, 2.0);
CAN_Signal_UNSIGNED_FLOAT CellOcvOffset19 = MakeSignal(unsigned_float, 56, 8, 0.004, 0.0);

RX_CAN_Message(8) BmsVoltages19{DriveBus, 0x166, CellV133, CellV134, CellV135, CellV136, CellV137, CellV138, CellV139, CellOcvOffset19};

CAN_Signal_UNSIGNED_FLOAT CellT0 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT1 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT2 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT3 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT4 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT5 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT6 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT7 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT0 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT1 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT2 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT3 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT4 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT5 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT6 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT7 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures0{DriveBus, 0x167, CellT0, CellT1, CellT2, CellT3, CellT4, CellT5, CellT6, CellT7};

CAN_Signal_UNSIGNED_FLOAT CellT8 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT9 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT10 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT11 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT12 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT13 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT14 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT15 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT8 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT9 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT10 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT11 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT12 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT13 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT14 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT15 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures1{DriveBus, 0x168, CellT8, CellT9, CellT10, CellT11, CellT12, CellT13, CellT14, CellT15};

CAN_Signal_UNSIGNED_FLOAT CellT16 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT17 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT18 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT19 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT20 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT21 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT22 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT23 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT16 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT17 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT18 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT19 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT20 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT21 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT22 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT23 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures2{DriveBus, 0x169, CellT16, CellT17, CellT18, CellT19, CellT20, CellT21, CellT22, CellT23};

CAN_Signal_UNSIGNED_FLOAT CellT24 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT25 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT26 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT27 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT28 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT29 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT30 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT31 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT24 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT25 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT26 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT27 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT28 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT29 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT30 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT31 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures3{DriveBus, 0x16A, CellT24, CellT25, CellT26, CellT27, CellT28, CellT29, CellT30, CellT31};

CAN_Signal_UNSIGNED_FLOAT CellT32 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT33 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT34 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT35 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT36 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT37 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT38 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT39 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT32 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT33 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT34 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT35 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT36 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT37 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT38 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT39 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures4{DriveBus, 0x16B, CellT32, CellT33, CellT34, CellT35, CellT36, CellT37, CellT38, CellT39};

CAN_Signal_UNSIGNED_FLOAT CellT40 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT41 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT42 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT43 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT44 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT45 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT46 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT47 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT40 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT41 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT42 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT43 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT44 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT45 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT46 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT47 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures5{DriveBus, 0x16C, CellT40, CellT41, CellT42, CellT43, CellT44, CellT45, CellT46, CellT47};

CAN_Signal_UNSIGNED_FLOAT CellT48 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT49 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT50 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT51 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT52 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT53 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT54 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT55 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT48 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT49 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT50 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT51 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT52 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT53 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT54 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT55 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures6{DriveBus, 0x16D, CellT48, CellT49, CellT50, CellT51, CellT52, CellT53, CellT54, CellT55};

CAN_Signal_UNSIGNED_FLOAT CellT56 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT57 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT58 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT59 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT60 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT61 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT62 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT63 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT56 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT57 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT58 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT59 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT60 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT61 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT62 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT63 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures7{DriveBus, 0x16E, CellT56, CellT57, CellT58, CellT59, CellT60, CellT61, CellT62, CellT63};

CAN_Signal_UNSIGNED_FLOAT CellT64 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT65 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT66 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT67 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT68 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT69 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT70 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT71 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT64 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT65 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT66 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT67 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT68 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT69 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT70 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT71 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures8{DriveBus, 0x16F, CellT64, CellT65, CellT66, CellT67, CellT68, CellT69, CellT70, CellT71};

CAN_Signal_UNSIGNED_FLOAT CellT72 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT73 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT74 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT75 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT76 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT77 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT78 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT79 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT72 = MakeSignal(unsigned_float, 0, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT73 = MakeSignal(unsigned_float, 8, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT74 = MakeSignal(unsigned_float, 16, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT75 = MakeSignal(unsigned_float, 24, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT76 = MakeSignal(unsigned_float, 32, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT77 = MakeSignal(unsigned_float, 40, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT78 = MakeSignal(unsigned_float, 48, 8, 1.0, -40.0);
CAN_Signal_UNSIGNED_FLOAT CellT79 = MakeSignal(unsigned_float, 56, 8, 1.0, -40.0);

RX_CAN_Message(8) BmsTemperatures9{DriveBus, 0x170, CellT72, CellT73, CellT74, CellT75, CellT76, CellT77, CellT78, CellT79};

CAN_Signal_UINT64 ControllerError = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 ControllerError = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) Can2usbControllerError{DriveBus, 0x004, ControllerError};

CAN_Signal_UINT64 ControllerErrorNack = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 ControllerErrorNack = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) Can2usbControllerErrorNackError{DriveBus, 0x024, ControllerErrorNack};

CAN_Signal_UINT64 ControllerErrorProtocolViolation = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 ControllerErrorProtocolViolation = MakeSignal(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) Can2usbControllerErrorProtocolViolation{DriveBus, 0x00C, ControllerErrorProtocolViolation};

}