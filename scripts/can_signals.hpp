MakeSignalSigned(float, 0, 16, 0.01, 0.0, True) GenAmps;
MakeSignalSigned(float, 16, 8, 0.01, 0.0, True) FrontFanAmps;
MakeSignalSigned(float, 24, 8, 0.01, 0.0, True) RearFanAmps;
MakeSignalSigned(float, 32, 8, 0.01, 0.0, True) FrontPumpAmps;
MakeSignalSigned(float, 40, 8, 0.01, 0.0, True) RearPumpAmps;
MakeSignalSigned(float, 0, 16, 0.01, 0.0, True) GenAmps;
MakeSignalSigned(float, 16, 8, 0.01, 0.0, True) FrontFanAmps;
MakeSignalSigned(float, 24, 8, 0.01, 0.0, True) RearFanAmps;
MakeSignalSigned(float, 32, 8, 0.01, 0.0, True) FrontPumpAmps;
MakeSignalSigned(float, 40, 8, 0.01, 0.0, True) RearPumpAmps;

CANRXMessage<5> PdmCurrent{DriveBus, 0x2A1, GenAmps, FrontFanAmps, RearFanAmps, FrontPumpAmps, RearPumpAmps};

MakeSignalSigned(float, 0, 16, 0.01, 0.0, True) BatVolt;
MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True) BatVoltWarning;
MakeSignalSigned(float, 0, 16, 0.01, 0.0, True) BatVolt;
MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True) BatVoltWarning;

CANRXMessage<2> PdmBatVolt{DriveBus, 0x2A2, BatVolt, BatVoltWarning};

MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True) Rpm;
MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True) MotorCurrent;
MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True) DcVoltage;
MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True) DcCurrent;
MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True) Rpm;
MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True) MotorCurrent;
MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True) DcVoltage;
MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True) DcCurrent;

CANRXMessage<4> InverterMotorStatus{DriveBus, 0x281, Rpm, MotorCurrent, DcVoltage, DcCurrent};

MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True) IgbtTemp;
MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True) MotorTemp;
MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True) IgbtTemp;
MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True) MotorTemp;

CANRXMessage<2> InverterTempStatus{DriveBus, 0x282, IgbtTemp, MotorTemp};

MakeSignal(uint32_t, 32, 32, 0.0001, 0.0) AhCharged;
MakeSignal(uint32_t, 32, 32, 0.0001, 0.0) AhCharged;

CANRXMessage<1> InverterCurrentDraw{DriveBus, nan, AhCharged};

MakeSignal(uint32_t, 0, 32, 0.001, 0.0) WhDrawn;
MakeSignal(uint32_t, 32, 32, 0.001, 0.0) WhCharged;
MakeSignal(uint32_t, 0, 32, 0.001, 0.0) WhDrawn;
MakeSignal(uint32_t, 32, 32, 0.001, 0.0) WhCharged;

CANRXMessage<2> InverterPowerDraw{DriveBus, 0x284, WhDrawn, WhCharged};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) FaultCode;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) FaultCode;

CANRXMessage<1> InverterFaultStatus{DriveBus, 0x280, FaultCode};

MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True) SetCurrent;
MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True) SetCurrent;

CANRXMessage<1> EcuSetCurrent{DriveBus, 0x200, SetCurrent};

MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True) SetCurrentBrake;
MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True) SetCurrentBrake;

CANRXMessage<1> EcuSetCurrentBrake{DriveBus, 0x201, SetCurrentBrake};

MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True) Apps1Throttle;
MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True) Apps2Throttle;
MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True) Apps1Throttle;
MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True) Apps2Throttle;

CANRXMessage<2> EcuThrottle{DriveBus, 0x202, Apps1Throttle, Apps2Throttle};

MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True) FrontBrakePressure;
MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True) RearBrakePressure;
MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True) BrakePressed;
MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True) FrontBrakePressure;
MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True) RearBrakePressure;
MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True) BrakePressed;

CANRXMessage<3> EcuBrake{DriveBus, 0x203, FrontBrakePressure, RearBrakePressure, BrakePressed};

MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True) ImplausibilityPresent;
MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True) AppssDisagreementImp;
MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True) BppcImp;
MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True) BrakeInvalidImp;
MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True) AppssInvalidImp;
MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True) ImplausibilityPresent;
MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True) AppssDisagreementImp;
MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True) BppcImp;
MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True) BrakeInvalidImp;
MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True) AppssInvalidImp;

CANRXMessage<5> EcuImplausibility{DriveBus, 0x204, ImplausibilityPresent, AppssDisagreementImp, BppcImp, BrakeInvalidImp, AppssInvalidImp};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BmsCommand;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BmsCommand;

CANRXMessage<1> EcuBmsCommandMessage{DriveBus, 0x205, BmsCommand};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) DriveState;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) DriveState;

CANRXMessage<1> EcuDriveStatus{DriveBus, 0x206, DriveState};

MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True) ActiveAeroState;
MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True) ActiveAeroPosition;
MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True) ActiveAeroState;
MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True) ActiveAeroPosition;

CANRXMessage<2> EcuActiveAeroCommand{DriveBus, 0x208, ActiveAeroState, ActiveAeroPosition};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) FrontPumpDutyCycle;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) RearPumpDutyCycle;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) FrontFanDutyCycle;
MakeSignal(uint8_t, 24, 8, 1.0, 0.0) RearPumpDutyCycle;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) FrontPumpDutyCycle;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) RearPumpDutyCycle;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) FrontFanDutyCycle;
MakeSignal(uint8_t, 24, 8, 1.0, 0.0) RearPumpDutyCycle;

CANRXMessage<4> EcuPumpFanCommand{DriveBus, 0x209, FrontPumpDutyCycle, RearPumpDutyCycle, FrontFanDutyCycle, RearPumpDutyCycle};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) AccelLutIdResponse;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) AccelLutIdResponse;

CANRXMessage<1> EcuLutResponse{DriveBus, 0x20A, AccelLutIdResponse};

MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True) IgbtTempLimiting;
MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True) BatteryTempLimiting;
MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True) MotorTempLimiting;
MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True) IgbtTempLimiting;
MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True) BatteryTempLimiting;
MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True) MotorTempLimiting;

CANRXMessage<3> EcuTempLimitingStatus{DriveBus, 0x20B, IgbtTempLimiting, BatteryTempLimiting, MotorTempLimiting};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) TorqueStatus;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) TorqueStatus;

CANRXMessage<1> EcuTorqueStatus{DriveBus, 0x20C, TorqueStatus};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) EcuEnableResponse;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BmsEnableResponse;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) PdmEnableResponse;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) EcuEnableResponse;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BmsEnableResponse;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) PdmEnableResponse;

CANRXMessage<3> CmRequestDrivetrain{DriveBus, 0x490, EcuEnableResponse, BmsEnableResponse, PdmEnableResponse};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) DynamicsEnableResponse;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) FrontEnableResponse;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) TelemetryEnableResponse;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) DynamicsEnableResponse;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) FrontEnableResponse;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) TelemetryEnableResponse;

CANRXMessage<3> CmRequestDaq{DriveBus, 0x491, DynamicsEnableResponse, FrontEnableResponse, TelemetryEnableResponse};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BlEnableResponse;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BrEnableResponse;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) FlEnableResponse;
MakeSignal(uint8_t, 24, 8, 1.0, 0.0) FrEnableResponse;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BlEnableResponse;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BrEnableResponse;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) FlEnableResponse;
MakeSignal(uint8_t, 24, 8, 1.0, 0.0) FrEnableResponse;

CANRXMessage<4> CmRequestWheel{DriveBus, 0x492, BlEnableResponse, BrEnableResponse, FlEnableResponse, FrEnableResponse};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseEcu{DriveBus, 0x590, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseBms{DriveBus, 0x591, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponsePdm{DriveBus, 0x592, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseDynamics{DriveBus, 0x593, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseFront{DriveBus, 0x594, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseTelemetry{DriveBus, 0x595, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseBl{DriveBus, 0x596, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseBr{DriveBus, 0x597, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseFl{DriveBus, 0x598, Counter};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) Counter;

CANRXMessage<1> CmResponseFr{DriveBus, 0x599, Counter};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) EcuStatus;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BmsStatus;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) PdmStatus;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) EcuStatus;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BmsStatus;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) PdmStatus;

CANRXMessage<3> CmNodeStatusDrivetrain{DriveBus, 0x192, EcuStatus, BmsStatus, PdmStatus};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) DynamicsStatus;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) FrontStatus;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) TelemetryStatus;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) DynamicsStatus;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) FrontStatus;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) TelemetryStatus;

CANRXMessage<3> CmNodeStatusDaq{DriveBus, 0x193, DynamicsStatus, FrontStatus, TelemetryStatus};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BlStatus;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BrStatus;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) FlStatus;
MakeSignal(uint8_t, 24, 8, 1.0, 0.0) FrStatus;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BlStatus;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) BrStatus;
MakeSignal(uint8_t, 16, 8, 1.0, 0.0) FlStatus;
MakeSignal(uint8_t, 24, 8, 1.0, 0.0) FrStatus;

CANRXMessage<4> CmNodeStatusWheel{DriveBus, 0x194, BlStatus, BrStatus, FlStatus, FrStatus};

MakeSignal(unsigned_float, 0, 12, 0.1, 0.0) MaxDischargeCurrent;
MakeSignal(unsigned_float, 12, 12, 0.1, 0.0) MaxRegenCurrent;
MakeSignal(unsigned_float, 24, 16, 0.01, 0.0) BatteryVoltage;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) BatteryTemperature;
MakeSignal(unsigned_float, 48, 16, 0.01, -100.0) BatteryCurrent;
MakeSignal(unsigned_float, 0, 12, 0.1, 0.0) MaxDischargeCurrent;
MakeSignal(unsigned_float, 12, 12, 0.1, 0.0) MaxRegenCurrent;
MakeSignal(unsigned_float, 24, 16, 0.01, 0.0) BatteryVoltage;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) BatteryTemperature;
MakeSignal(unsigned_float, 48, 16, 0.01, -100.0) BatteryCurrent;

CANRXMessage<5> BmsSoe{DriveBus, 0x150, MaxDischargeCurrent, MaxRegenCurrent, BatteryVoltage, BatteryTemperature, BatteryCurrent};

MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True) FaultSummary;
MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True) UndervoltageFault;
MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True) OvervoltageFault;
MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True) UndertemperatureFault;
MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True) OvertemperatureFault;
MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True) OvercurrentFault;
MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True) ExternalKillFault;
MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True) OpenWireFault;
MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True) OpenWireTempFault;
MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True) PecFault;
MakeSignal(uint8_t, 10, 8, 1.0, 0.0) TotalPecFailures;
MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True) FaultSummary;
MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True) UndervoltageFault;
MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True) OvervoltageFault;
MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True) UndertemperatureFault;
MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True) OvertemperatureFault;
MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True) OvercurrentFault;
MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True) ExternalKillFault;
MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True) OpenWireFault;
MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True) OpenWireTempFault;
MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True) PecFault;
MakeSignal(uint8_t, 10, 8, 1.0, 0.0) TotalPecFailures;

CANRXMessage<11> BmsFaults{DriveBus, 0x151, FaultSummary, UndervoltageFault, OvervoltageFault, UndertemperatureFault, OvertemperatureFault, OvercurrentFault, ExternalKillFault, OpenWireFault, OpenWireTempFault, PecFault, TotalPecFailures};

MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BmsState;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) ImdState;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) MaxCellTemp;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) MinCellTemp;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) MaxCellVoltage;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) MinCellVoltage;
MakeSignal(unsigned_float, 48, 8, 0.004, 0.0) BmsSoc;
MakeSignal(uint8_t, 0, 8, 1.0, 0.0) BmsState;
MakeSignal(uint8_t, 8, 8, 1.0, 0.0) ImdState;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) MaxCellTemp;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) MinCellTemp;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) MaxCellVoltage;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) MinCellVoltage;
MakeSignal(unsigned_float, 48, 8, 0.004, 0.0) BmsSoc;

CANRXMessage<7> BmsStatus{DriveBus, 0x152, BmsState, ImdState, MaxCellTemp, MinCellTemp, MaxCellVoltage, MinCellVoltage, BmsSoc};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV0;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV1;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV2;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV3;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV4;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV5;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV6;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset0;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV0;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV1;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV2;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV3;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV4;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV5;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV6;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset0;

CANRXMessage<8> BmsVoltages0{DriveBus, 0x153, CellV0, CellV1, CellV2, CellV3, CellV4, CellV5, CellV6, CellOcvOffset0};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV7;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV8;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV9;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV10;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV11;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV12;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV13;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset1;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV7;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV8;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV9;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV10;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV11;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV12;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV13;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset1;

CANRXMessage<8> BmsVoltages1{DriveBus, 0x154, CellV7, CellV8, CellV9, CellV10, CellV11, CellV12, CellV13, CellOcvOffset1};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV14;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV15;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV16;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV17;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV18;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV19;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV20;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset2;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV14;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV15;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV16;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV17;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV18;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV19;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV20;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset2;

CANRXMessage<8> BmsVoltages2{DriveBus, 0x155, CellV14, CellV15, CellV16, CellV17, CellV18, CellV19, CellV20, CellOcvOffset2};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV21;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV22;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV23;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV24;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV25;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV26;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV27;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset3;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV21;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV22;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV23;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV24;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV25;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV26;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV27;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset3;

CANRXMessage<8> BmsVoltages3{DriveBus, 0x156, CellV21, CellV22, CellV23, CellV24, CellV25, CellV26, CellV27, CellOcvOffset3};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV28;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV29;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV30;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV31;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV32;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV33;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV34;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset4;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV28;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV29;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV30;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV31;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV32;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV33;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV34;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset4;

CANRXMessage<8> BmsVoltages4{DriveBus, 0x157, CellV28, CellV29, CellV30, CellV31, CellV32, CellV33, CellV34, CellOcvOffset4};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV35;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV36;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV37;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV38;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV39;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV40;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV41;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset5;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV35;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV36;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV37;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV38;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV39;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV40;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV41;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset5;

CANRXMessage<8> BmsVoltages5{DriveBus, 0x158, CellV35, CellV36, CellV37, CellV38, CellV39, CellV40, CellV41, CellOcvOffset5};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV42;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV43;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV44;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV45;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV46;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV47;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV48;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset6;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV42;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV43;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV44;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV45;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV46;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV47;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV48;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset6;

CANRXMessage<8> BmsVoltages6{DriveBus, 0x159, CellV42, CellV43, CellV44, CellV45, CellV46, CellV47, CellV48, CellOcvOffset6};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV49;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV50;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV51;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV52;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV53;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV54;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV55;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset7;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV49;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV50;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV51;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV52;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV53;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV54;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV55;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset7;

CANRXMessage<8> BmsVoltages7{DriveBus, 0x15A, CellV49, CellV50, CellV51, CellV52, CellV53, CellV54, CellV55, CellOcvOffset7};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV56;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV57;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV58;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV59;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV60;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV61;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV62;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset8;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV56;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV57;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV58;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV59;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV60;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV61;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV62;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset8;

CANRXMessage<8> BmsVoltages8{DriveBus, 0x15B, CellV56, CellV57, CellV58, CellV59, CellV60, CellV61, CellV62, CellOcvOffset8};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV63;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV64;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV65;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV66;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV67;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV68;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV69;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset9;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV63;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV64;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV65;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV66;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV67;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV68;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV69;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset9;

CANRXMessage<8> BmsVoltages9{DriveBus, 0x15C, CellV63, CellV64, CellV65, CellV66, CellV67, CellV68, CellV69, CellOcvOffset9};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV70;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV71;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV72;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV73;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV74;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV75;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV76;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset10;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV70;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV71;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV72;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV73;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV74;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV75;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV76;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset10;

CANRXMessage<8> BmsVoltages10{DriveBus, 0x15D, CellV70, CellV71, CellV72, CellV73, CellV74, CellV75, CellV76, CellOcvOffset10};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV77;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV78;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV79;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV80;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV81;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV82;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV83;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset11;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV77;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV78;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV79;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV80;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV81;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV82;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV83;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset11;

CANRXMessage<8> BmsVoltages11{DriveBus, 0x15E, CellV77, CellV78, CellV79, CellV80, CellV81, CellV82, CellV83, CellOcvOffset11};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV84;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV85;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV86;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV87;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV88;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV89;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV90;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset12;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV84;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV85;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV86;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV87;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV88;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV89;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV90;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset12;

CANRXMessage<8> BmsVoltages12{DriveBus, 0x15F, CellV84, CellV85, CellV86, CellV87, CellV88, CellV89, CellV90, CellOcvOffset12};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV91;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV92;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV93;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV94;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV95;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV96;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV97;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset13;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV91;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV92;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV93;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV94;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV95;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV96;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV97;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset13;

CANRXMessage<8> BmsVoltages13{DriveBus, 0x160, CellV91, CellV92, CellV93, CellV94, CellV95, CellV96, CellV97, CellOcvOffset13};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV98;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV99;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV100;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV101;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV102;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV103;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV104;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset14;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV98;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV99;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV100;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV101;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV102;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV103;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV104;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset14;

CANRXMessage<8> BmsVoltages14{DriveBus, 0x161, CellV98, CellV99, CellV100, CellV101, CellV102, CellV103, CellV104, CellOcvOffset14};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV105;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV106;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV107;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV108;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV109;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV110;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV111;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset15;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV105;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV106;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV107;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV108;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV109;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV110;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV111;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset15;

CANRXMessage<8> BmsVoltages15{DriveBus, 0x162, CellV105, CellV106, CellV107, CellV108, CellV109, CellV110, CellV111, CellOcvOffset15};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV112;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV113;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV114;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV115;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV116;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV117;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV118;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset16;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV112;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV113;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV114;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV115;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV116;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV117;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV118;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset16;

CANRXMessage<8> BmsVoltages16{DriveBus, 0x163, CellV112, CellV113, CellV114, CellV115, CellV116, CellV117, CellV118, CellOcvOffset16};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV119;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV120;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV121;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV122;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV123;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV124;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV125;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset17;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV119;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV120;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV121;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV122;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV123;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV124;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV125;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset17;

CANRXMessage<8> BmsVoltages17{DriveBus, 0x164, CellV119, CellV120, CellV121, CellV122, CellV123, CellV124, CellV125, CellOcvOffset17};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV126;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV127;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV128;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV129;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV130;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV131;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV132;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset18;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV126;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV127;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV128;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV129;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV130;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV131;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV132;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset18;

CANRXMessage<8> BmsVoltages18{DriveBus, 0x165, CellV126, CellV127, CellV128, CellV129, CellV130, CellV131, CellV132, CellOcvOffset18};

MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV133;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV134;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV135;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV136;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV137;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV138;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV139;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset19;
MakeSignal(unsigned_float, 0, 8, 0.012, 2.0) CellV133;
MakeSignal(unsigned_float, 8, 8, 0.012, 2.0) CellV134;
MakeSignal(unsigned_float, 16, 8, 0.012, 2.0) CellV135;
MakeSignal(unsigned_float, 24, 8, 0.012, 2.0) CellV136;
MakeSignal(unsigned_float, 32, 8, 0.012, 2.0) CellV137;
MakeSignal(unsigned_float, 40, 8, 0.012, 2.0) CellV138;
MakeSignal(unsigned_float, 48, 8, 0.012, 2.0) CellV139;
MakeSignal(unsigned_float, 56, 8, 0.004, 0.0) CellOcvOffset19;

CANRXMessage<8> BmsVoltages19{DriveBus, 0x166, CellV133, CellV134, CellV135, CellV136, CellV137, CellV138, CellV139, CellOcvOffset19};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT0;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT1;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT2;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT3;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT4;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT5;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT6;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT7;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT0;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT1;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT2;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT3;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT4;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT5;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT6;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT7;

CANRXMessage<8> BmsTemperatures0{DriveBus, 0x167, CellT0, CellT1, CellT2, CellT3, CellT4, CellT5, CellT6, CellT7};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT8;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT9;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT10;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT11;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT12;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT13;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT14;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT15;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT8;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT9;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT10;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT11;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT12;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT13;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT14;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT15;

CANRXMessage<8> BmsTemperatures1{DriveBus, 0x168, CellT8, CellT9, CellT10, CellT11, CellT12, CellT13, CellT14, CellT15};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT16;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT17;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT18;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT19;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT20;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT21;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT22;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT23;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT16;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT17;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT18;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT19;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT20;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT21;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT22;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT23;

CANRXMessage<8> BmsTemperatures2{DriveBus, 0x169, CellT16, CellT17, CellT18, CellT19, CellT20, CellT21, CellT22, CellT23};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT24;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT25;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT26;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT27;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT28;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT29;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT30;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT31;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT24;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT25;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT26;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT27;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT28;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT29;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT30;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT31;

CANRXMessage<8> BmsTemperatures3{DriveBus, 0x16A, CellT24, CellT25, CellT26, CellT27, CellT28, CellT29, CellT30, CellT31};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT32;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT33;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT34;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT35;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT36;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT37;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT38;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT39;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT32;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT33;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT34;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT35;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT36;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT37;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT38;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT39;

CANRXMessage<8> BmsTemperatures4{DriveBus, 0x16B, CellT32, CellT33, CellT34, CellT35, CellT36, CellT37, CellT38, CellT39};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT40;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT41;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT42;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT43;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT44;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT45;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT46;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT47;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT40;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT41;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT42;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT43;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT44;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT45;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT46;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT47;

CANRXMessage<8> BmsTemperatures5{DriveBus, 0x16C, CellT40, CellT41, CellT42, CellT43, CellT44, CellT45, CellT46, CellT47};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT48;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT49;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT50;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT51;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT52;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT53;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT54;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT55;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT48;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT49;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT50;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT51;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT52;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT53;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT54;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT55;

CANRXMessage<8> BmsTemperatures6{DriveBus, 0x16D, CellT48, CellT49, CellT50, CellT51, CellT52, CellT53, CellT54, CellT55};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT56;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT57;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT58;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT59;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT60;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT61;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT62;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT63;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT56;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT57;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT58;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT59;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT60;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT61;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT62;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT63;

CANRXMessage<8> BmsTemperatures7{DriveBus, 0x16E, CellT56, CellT57, CellT58, CellT59, CellT60, CellT61, CellT62, CellT63};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT64;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT65;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT66;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT67;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT68;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT69;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT70;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT71;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT64;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT65;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT66;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT67;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT68;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT69;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT70;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT71;

CANRXMessage<8> BmsTemperatures8{DriveBus, 0x16F, CellT64, CellT65, CellT66, CellT67, CellT68, CellT69, CellT70, CellT71};

MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT72;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT73;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT74;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT75;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT76;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT77;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT78;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT79;
MakeSignal(unsigned_float, 0, 8, 1.0, -40.0) CellT72;
MakeSignal(unsigned_float, 8, 8, 1.0, -40.0) CellT73;
MakeSignal(unsigned_float, 16, 8, 1.0, -40.0) CellT74;
MakeSignal(unsigned_float, 24, 8, 1.0, -40.0) CellT75;
MakeSignal(unsigned_float, 32, 8, 1.0, -40.0) CellT76;
MakeSignal(unsigned_float, 40, 8, 1.0, -40.0) CellT77;
MakeSignal(unsigned_float, 48, 8, 1.0, -40.0) CellT78;
MakeSignal(unsigned_float, 56, 8, 1.0, -40.0) CellT79;

CANRXMessage<8> BmsTemperatures9{DriveBus, 0x170, CellT72, CellT73, CellT74, CellT75, CellT76, CellT77, CellT78, CellT79};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) ControllerError;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) ControllerError;

CANRXMessage<1> Can2usbControllerError{DriveBus, 0x004, ControllerError};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) ControllerErrorNack;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) ControllerErrorNack;

CANRXMessage<1> Can2usbControllerErrorNackError{DriveBus, 0x024, ControllerErrorNack};

MakeSignal(uint64_t, 0, 64, 1.0, 0.0) ControllerErrorProtocolViolation;
MakeSignal(uint64_t, 0, 64, 1.0, 0.0) ControllerErrorProtocolViolation;

CANRXMessage<1> Can2usbControllerErrorProtocolViolation{DriveBus, 0x00C, ControllerErrorProtocolViolation};

