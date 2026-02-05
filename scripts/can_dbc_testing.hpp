#include "CAN_interface.cpp"
namespace CANDBC {
CAN_Signal_FLOAT gen_amps = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT front_fan_amps = MakeSignalSigned(float, 16, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT rear_fan_amps = MakeSignalSigned(float, 24, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT front_pump_amps = MakeSignalSigned(float, 32, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT rear_pump_amps = MakeSignalSigned(float, 40, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT gen_amps = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT front_fan_amps = MakeSignalSigned(float, 16, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT rear_fan_amps = MakeSignalSigned(float, 24, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT front_pump_amps = MakeSignalSigned(float, 32, 8, 0.01, 0.0, True);
CAN_Signal_FLOAT rear_pump_amps = MakeSignalSigned(float, 40, 8, 0.01, 0.0, True);

RX_CAN_Message(5) pdm_current{drive_bus, 0x2A1, gen_amps, front_fan_amps, rear_fan_amps, front_pump_amps, rear_pump_amps};

CAN_Signal_FLOAT bat_volt = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_BOOL bat_volt_warning = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_FLOAT bat_volt = MakeSignalSigned(float, 0, 16, 0.01, 0.0, True);
CAN_Signal_BOOL bat_volt_warning = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);

RX_CAN_Message(2) pdm_bat_volt{drive_bus, 0x2A2, bat_volt, bat_volt_warning};

CAN_Signal_INT16 rpm = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 motor_current = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 dc_voltage = MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True);
CAN_Signal_INT16 dc_current = MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True);
CAN_Signal_INT16 rpm = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 motor_current = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 dc_voltage = MakeSignalSigned(int16_t, 32, 16, 0.1, 0.0, True);
CAN_Signal_INT16 dc_current = MakeSignalSigned(int16_t, 48, 16, 0.1, 0.0, True);

RX_CAN_Message(4) inverter_motor_status{drive_bus, 0x281, rpm, motor_current, dc_voltage, dc_current};

CAN_Signal_INT16 igbt_temp = MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True);
CAN_Signal_INT16 motor_temp = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);
CAN_Signal_INT16 igbt_temp = MakeSignalSigned(int16_t, 0, 16, 0.1, 0.0, True);
CAN_Signal_INT16 motor_temp = MakeSignalSigned(int16_t, 16, 16, 0.1, 0.0, True);

RX_CAN_Message(2) inverter_temp_status{drive_bus, 0x282, igbt_temp, motor_temp};

CAN_Signal_UINT32 ah_charged = MakeSignalExp(uint32_t, 32, 32, 0.0001, 0.0);
CAN_Signal_UINT32 ah_charged = MakeSignalExp(uint32_t, 32, 32, 0.0001, 0.0);

RX_CAN_Message(1) inverter_current_draw{drive_bus, nan, ah_charged};

CAN_Signal_UINT32 wh_drawn = MakeSignalExp(uint32_t, 0, 32, 0.001, 0.0);
CAN_Signal_UINT32 wh_charged = MakeSignalExp(uint32_t, 32, 32, 0.001, 0.0);
CAN_Signal_UINT32 wh_drawn = MakeSignalExp(uint32_t, 0, 32, 0.001, 0.0);
CAN_Signal_UINT32 wh_charged = MakeSignalExp(uint32_t, 32, 32, 0.001, 0.0);

RX_CAN_Message(2) inverter_power_draw{drive_bus, 0x284, wh_drawn, wh_charged};

CAN_Signal_UINT8 fault_code = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 fault_code = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) inverter_fault_status{drive_bus, 0x280, fault_code};

CAN_Signal_INT32 set_current = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);
CAN_Signal_INT32 set_current = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);

RX_CAN_Message(1) ecu_set_current{drive_bus, 0x200, set_current};

CAN_Signal_INT32 set_current_brake = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);
CAN_Signal_INT32 set_current_brake = MakeSignalSigned(int32_t, 0, 32, 0.001, 0.0, True);

RX_CAN_Message(1) ecu_set_current_brake{drive_bus, 0x201, set_current_brake};

CAN_Signal_INT16 apps1_throttle = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 apps2_throttle = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_INT16 apps1_throttle = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 apps2_throttle = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);

RX_CAN_Message(2) ecu_throttle{drive_bus, 0x202, apps1_throttle, apps2_throttle};

CAN_Signal_INT16 front_brake_pressure = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 rear_brake_pressure = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_BOOL brake_pressed = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);
CAN_Signal_INT16 front_brake_pressure = MakeSignalSigned(int16_t, 0, 16, 1.0, 0.0, True);
CAN_Signal_INT16 rear_brake_pressure = MakeSignalSigned(int16_t, 16, 16, 1.0, 0.0, True);
CAN_Signal_BOOL brake_pressed = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);

RX_CAN_Message(3) ecu_brake{drive_bus, 0x203, front_brake_pressure, rear_brake_pressure, brake_pressed};

CAN_Signal_BOOL implausibility_present = MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True);
CAN_Signal_BOOL appss_disagreement_imp = MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True);
CAN_Signal_BOOL bppc_imp = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_BOOL brake_invalid_imp = MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True);
CAN_Signal_BOOL appss_invalid_imp = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);
CAN_Signal_BOOL implausibility_present = MakeSignalSigned(bool, 0, 8, 1.0, 0.0, True);
CAN_Signal_BOOL appss_disagreement_imp = MakeSignalSigned(bool, 8, 8, 1.0, 0.0, True);
CAN_Signal_BOOL bppc_imp = MakeSignalSigned(bool, 16, 8, 1.0, 0.0, True);
CAN_Signal_BOOL brake_invalid_imp = MakeSignalSigned(bool, 24, 8, 1.0, 0.0, True);
CAN_Signal_BOOL appss_invalid_imp = MakeSignalSigned(bool, 32, 8, 1.0, 0.0, True);

RX_CAN_Message(5) ecu_implausibility{drive_bus, 0x204, implausibility_present, appss_disagreement_imp, bppc_imp, brake_invalid_imp, appss_invalid_imp};

CAN_Signal_UINT8 bms_command = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 bms_command = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) ecu_bms_command_message{drive_bus, 0x205, bms_command};

CAN_Signal_UINT8 drive_state = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 drive_state = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) ecu_drive_status{drive_bus, 0x206, drive_state};

CAN_Signal_BOOL active_aero_state = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_INT16 active_aero_position = MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True);
CAN_Signal_BOOL active_aero_state = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_INT16 active_aero_position = MakeSignalSigned(int16_t, 1, 16, 1.0, 0.0, True);

RX_CAN_Message(2) ecu_active_aero_command{drive_bus, 0x208, active_aero_state, active_aero_position};

CAN_Signal_UINT8 front_pump_duty_cycle = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 rear_pump_duty_cycle = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_fan_duty_cycle = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 rear_pump_duty_cycle = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_pump_duty_cycle = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 rear_pump_duty_cycle = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_fan_duty_cycle = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 rear_pump_duty_cycle = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);

RX_CAN_Message(4) ecu_pump_fan_command{drive_bus, 0x209, front_pump_duty_cycle, rear_pump_duty_cycle, front_fan_duty_cycle, rear_pump_duty_cycle};

CAN_Signal_UINT8 accel_lut_id_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 accel_lut_id_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) ecu_lut_response{drive_bus, 0x20A, accel_lut_id_response};

CAN_Signal_BOOL igbt_temp_limiting = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL battery_temp_limiting = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL motor_temp_limiting = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL igbt_temp_limiting = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL battery_temp_limiting = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL motor_temp_limiting = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);

RX_CAN_Message(3) ecu_temp_limiting_status{drive_bus, 0x20B, igbt_temp_limiting, battery_temp_limiting, motor_temp_limiting};

CAN_Signal_UINT8 torque_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 torque_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);

RX_CAN_Message(1) ecu_torque_status{drive_bus, 0x20C, torque_status};

CAN_Signal_UINT8 ecu_enable_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 bms_enable_response = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 pdm_enable_response = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 ecu_enable_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 bms_enable_response = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 pdm_enable_response = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) cm_request_drivetrain{drive_bus, 0x490, ecu_enable_response, bms_enable_response, pdm_enable_response};

CAN_Signal_UINT8 dynamics_enable_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_enable_response = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 telemetry_enable_response = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 dynamics_enable_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_enable_response = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 telemetry_enable_response = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) cm_request_daq{drive_bus, 0x491, dynamics_enable_response, front_enable_response, telemetry_enable_response};

CAN_Signal_UINT8 bl_enable_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 br_enable_response = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 fl_enable_response = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 fr_enable_response = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);
CAN_Signal_UINT8 bl_enable_response = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 br_enable_response = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 fl_enable_response = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 fr_enable_response = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);

RX_CAN_Message(4) cm_request_wheel{drive_bus, 0x492, bl_enable_response, br_enable_response, fl_enable_response, fr_enable_response};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_ecu{drive_bus, 0x590, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_bms{drive_bus, 0x591, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_pdm{drive_bus, 0x592, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_dynamics{drive_bus, 0x593, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_front{drive_bus, 0x594, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_telemetry{drive_bus, 0x595, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_bl{drive_bus, 0x596, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_br{drive_bus, 0x597, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_fl{drive_bus, 0x598, counter};

CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 counter = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) cm_response_fr{drive_bus, 0x599, counter};

CAN_Signal_UINT8 ecu_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 bms_status = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 pdm_status = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 ecu_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 bms_status = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 pdm_status = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) cm_node_status_drivetrain{drive_bus, 0x192, ecu_status, bms_status, pdm_status};

CAN_Signal_UINT8 dynamics_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_status = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 telemetry_status = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 dynamics_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 front_status = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 telemetry_status = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);

RX_CAN_Message(3) cm_node_status_daq{drive_bus, 0x193, dynamics_status, front_status, telemetry_status};

CAN_Signal_UINT8 bl_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 br_status = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 fl_status = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 fr_status = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);
CAN_Signal_UINT8 bl_status = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 br_status = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_UINT8 fl_status = MakeSignalExp(uint8_t, 16, 8, 1.0, 0.0);
CAN_Signal_UINT8 fr_status = MakeSignalExp(uint8_t, 24, 8, 1.0, 0.0);

RX_CAN_Message(4) cm_node_status_wheel{drive_bus, 0x194, bl_status, br_status, fl_status, fr_status};

CAN_Signal_FLOAT max_discharge_current = MakeSignalSigned(float, 0, 12, 0.1, 0.0, True);
CAN_Signal_FLOAT max_regen_current = MakeSignalSigned(float, 12, 12, 0.1, 0.0, True);
CAN_Signal_FLOAT battery_voltage = MakeSignalSigned(float, 24, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT battery_temperature = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT battery_current = MakeSignalSigned(float, 48, 16, 0.01, -100.0, True);
CAN_Signal_FLOAT max_discharge_current = MakeSignalSigned(float, 0, 12, 0.1, 0.0, True);
CAN_Signal_FLOAT max_regen_current = MakeSignalSigned(float, 12, 12, 0.1, 0.0, True);
CAN_Signal_FLOAT battery_voltage = MakeSignalSigned(float, 24, 16, 0.01, 0.0, True);
CAN_Signal_FLOAT battery_temperature = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT battery_current = MakeSignalSigned(float, 48, 16, 0.01, -100.0, True);

RX_CAN_Message(5) bms_soe{drive_bus, 0x150, max_discharge_current, max_regen_current, battery_voltage, battery_temperature, battery_current};

CAN_Signal_BOOL fault_summary = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL undervoltage_fault = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL overvoltage_fault = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL undertemperature_fault = MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True);
CAN_Signal_BOOL overtemperature_fault = MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True);
CAN_Signal_BOOL overcurrent_fault = MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True);
CAN_Signal_BOOL external_kill_fault = MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True);
CAN_Signal_BOOL open_wire_fault = MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True);
CAN_Signal_BOOL open_wire_temp_fault = MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True);
CAN_Signal_BOOL pec_fault = MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True);
CAN_Signal_UINT8 total_pec_failures = MakeSignalExp(uint8_t, 10, 8, 1.0, 0.0);
CAN_Signal_BOOL fault_summary = MakeSignalSigned(bool, 0, 1, 1.0, 0.0, True);
CAN_Signal_BOOL undervoltage_fault = MakeSignalSigned(bool, 1, 1, 1.0, 0.0, True);
CAN_Signal_BOOL overvoltage_fault = MakeSignalSigned(bool, 2, 1, 1.0, 0.0, True);
CAN_Signal_BOOL undertemperature_fault = MakeSignalSigned(bool, 3, 1, 1.0, 0.0, True);
CAN_Signal_BOOL overtemperature_fault = MakeSignalSigned(bool, 4, 1, 1.0, 0.0, True);
CAN_Signal_BOOL overcurrent_fault = MakeSignalSigned(bool, 5, 1, 1.0, 0.0, True);
CAN_Signal_BOOL external_kill_fault = MakeSignalSigned(bool, 6, 1, 1.0, 0.0, True);
CAN_Signal_BOOL open_wire_fault = MakeSignalSigned(bool, 7, 1, 1.0, 0.0, True);
CAN_Signal_BOOL open_wire_temp_fault = MakeSignalSigned(bool, 8, 1, 1.0, 0.0, True);
CAN_Signal_BOOL pec_fault = MakeSignalSigned(bool, 9, 1, 1.0, 0.0, True);
CAN_Signal_UINT8 total_pec_failures = MakeSignalExp(uint8_t, 10, 8, 1.0, 0.0);

RX_CAN_Message(11) bms_faults{drive_bus, 0x151, fault_summary, undervoltage_fault, overvoltage_fault, undertemperature_fault, overtemperature_fault, overcurrent_fault, external_kill_fault, open_wire_fault, open_wire_temp_fault, pec_fault, total_pec_failures};

CAN_Signal_UINT8 bms_state = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 imd_state = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_FLOAT max_cell_temp = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT min_cell_temp = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT max_cell_voltage = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT min_cell_voltage = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT bms_soc = MakeSignalSigned(float, 48, 8, 0.004, 0.0, True);
CAN_Signal_UINT8 bms_state = MakeSignalExp(uint8_t, 0, 8, 1.0, 0.0);
CAN_Signal_UINT8 imd_state = MakeSignalExp(uint8_t, 8, 8, 1.0, 0.0);
CAN_Signal_FLOAT max_cell_temp = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT min_cell_temp = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT max_cell_voltage = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT min_cell_voltage = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT bms_soc = MakeSignalSigned(float, 48, 8, 0.004, 0.0, True);

RX_CAN_Message(7) bms_status{drive_bus, 0x152, bms_state, imd_state, max_cell_temp, min_cell_temp, max_cell_voltage, min_cell_voltage, bms_soc};

CAN_Signal_FLOAT cell_v_0 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_1 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_2 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_3 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_4 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_5 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_6 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_0 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_0 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_1 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_2 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_3 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_4 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_5 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_6 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_0 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_0{drive_bus, 0x153, cell_v_0, cell_v_1, cell_v_2, cell_v_3, cell_v_4, cell_v_5, cell_v_6, cell_ocv_offset_0};

CAN_Signal_FLOAT cell_v_7 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_8 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_9 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_10 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_11 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_12 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_13 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_1 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_7 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_8 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_9 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_10 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_11 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_12 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_13 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_1 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_1{drive_bus, 0x154, cell_v_7, cell_v_8, cell_v_9, cell_v_10, cell_v_11, cell_v_12, cell_v_13, cell_ocv_offset_1};

CAN_Signal_FLOAT cell_v_14 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_15 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_16 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_17 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_18 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_19 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_20 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_2 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_14 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_15 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_16 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_17 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_18 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_19 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_20 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_2 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_2{drive_bus, 0x155, cell_v_14, cell_v_15, cell_v_16, cell_v_17, cell_v_18, cell_v_19, cell_v_20, cell_ocv_offset_2};

CAN_Signal_FLOAT cell_v_21 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_22 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_23 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_24 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_25 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_26 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_27 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_3 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_21 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_22 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_23 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_24 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_25 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_26 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_27 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_3 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_3{drive_bus, 0x156, cell_v_21, cell_v_22, cell_v_23, cell_v_24, cell_v_25, cell_v_26, cell_v_27, cell_ocv_offset_3};

CAN_Signal_FLOAT cell_v_28 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_29 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_30 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_31 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_32 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_33 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_34 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_4 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_28 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_29 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_30 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_31 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_32 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_33 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_34 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_4 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_4{drive_bus, 0x157, cell_v_28, cell_v_29, cell_v_30, cell_v_31, cell_v_32, cell_v_33, cell_v_34, cell_ocv_offset_4};

CAN_Signal_FLOAT cell_v_35 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_36 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_37 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_38 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_39 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_40 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_41 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_5 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_35 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_36 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_37 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_38 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_39 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_40 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_41 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_5 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_5{drive_bus, 0x158, cell_v_35, cell_v_36, cell_v_37, cell_v_38, cell_v_39, cell_v_40, cell_v_41, cell_ocv_offset_5};

CAN_Signal_FLOAT cell_v_42 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_43 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_44 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_45 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_46 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_47 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_48 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_6 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_42 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_43 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_44 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_45 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_46 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_47 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_48 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_6 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_6{drive_bus, 0x159, cell_v_42, cell_v_43, cell_v_44, cell_v_45, cell_v_46, cell_v_47, cell_v_48, cell_ocv_offset_6};

CAN_Signal_FLOAT cell_v_49 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_50 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_51 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_52 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_53 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_54 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_55 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_7 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_49 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_50 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_51 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_52 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_53 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_54 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_55 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_7 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_7{drive_bus, 0x15A, cell_v_49, cell_v_50, cell_v_51, cell_v_52, cell_v_53, cell_v_54, cell_v_55, cell_ocv_offset_7};

CAN_Signal_FLOAT cell_v_56 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_57 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_58 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_59 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_60 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_61 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_62 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_8 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_56 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_57 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_58 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_59 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_60 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_61 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_62 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_8 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_8{drive_bus, 0x15B, cell_v_56, cell_v_57, cell_v_58, cell_v_59, cell_v_60, cell_v_61, cell_v_62, cell_ocv_offset_8};

CAN_Signal_FLOAT cell_v_63 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_64 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_65 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_66 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_67 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_68 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_69 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_9 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_63 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_64 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_65 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_66 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_67 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_68 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_69 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_9 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_9{drive_bus, 0x15C, cell_v_63, cell_v_64, cell_v_65, cell_v_66, cell_v_67, cell_v_68, cell_v_69, cell_ocv_offset_9};

CAN_Signal_FLOAT cell_v_70 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_71 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_72 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_73 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_74 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_75 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_76 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_10 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_70 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_71 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_72 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_73 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_74 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_75 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_76 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_10 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_10{drive_bus, 0x15D, cell_v_70, cell_v_71, cell_v_72, cell_v_73, cell_v_74, cell_v_75, cell_v_76, cell_ocv_offset_10};

CAN_Signal_FLOAT cell_v_77 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_78 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_79 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_80 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_81 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_82 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_83 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_11 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_77 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_78 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_79 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_80 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_81 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_82 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_83 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_11 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_11{drive_bus, 0x15E, cell_v_77, cell_v_78, cell_v_79, cell_v_80, cell_v_81, cell_v_82, cell_v_83, cell_ocv_offset_11};

CAN_Signal_FLOAT cell_v_84 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_85 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_86 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_87 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_88 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_89 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_90 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_12 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_84 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_85 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_86 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_87 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_88 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_89 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_90 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_12 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_12{drive_bus, 0x15F, cell_v_84, cell_v_85, cell_v_86, cell_v_87, cell_v_88, cell_v_89, cell_v_90, cell_ocv_offset_12};

CAN_Signal_FLOAT cell_v_91 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_92 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_93 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_94 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_95 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_96 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_97 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_13 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_91 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_92 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_93 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_94 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_95 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_96 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_97 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_13 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_13{drive_bus, 0x160, cell_v_91, cell_v_92, cell_v_93, cell_v_94, cell_v_95, cell_v_96, cell_v_97, cell_ocv_offset_13};

CAN_Signal_FLOAT cell_v_98 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_99 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_100 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_101 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_102 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_103 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_104 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_14 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_98 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_99 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_100 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_101 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_102 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_103 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_104 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_14 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_14{drive_bus, 0x161, cell_v_98, cell_v_99, cell_v_100, cell_v_101, cell_v_102, cell_v_103, cell_v_104, cell_ocv_offset_14};

CAN_Signal_FLOAT cell_v_105 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_106 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_107 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_108 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_109 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_110 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_111 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_15 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_105 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_106 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_107 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_108 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_109 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_110 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_111 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_15 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_15{drive_bus, 0x162, cell_v_105, cell_v_106, cell_v_107, cell_v_108, cell_v_109, cell_v_110, cell_v_111, cell_ocv_offset_15};

CAN_Signal_FLOAT cell_v_112 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_113 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_114 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_115 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_116 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_117 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_118 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_16 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_112 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_113 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_114 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_115 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_116 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_117 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_118 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_16 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_16{drive_bus, 0x163, cell_v_112, cell_v_113, cell_v_114, cell_v_115, cell_v_116, cell_v_117, cell_v_118, cell_ocv_offset_16};

CAN_Signal_FLOAT cell_v_119 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_120 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_121 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_122 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_123 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_124 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_125 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_17 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_119 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_120 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_121 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_122 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_123 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_124 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_125 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_17 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_17{drive_bus, 0x164, cell_v_119, cell_v_120, cell_v_121, cell_v_122, cell_v_123, cell_v_124, cell_v_125, cell_ocv_offset_17};

CAN_Signal_FLOAT cell_v_126 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_127 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_128 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_129 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_130 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_131 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_132 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_18 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_126 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_127 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_128 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_129 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_130 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_131 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_132 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_18 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_18{drive_bus, 0x165, cell_v_126, cell_v_127, cell_v_128, cell_v_129, cell_v_130, cell_v_131, cell_v_132, cell_ocv_offset_18};

CAN_Signal_FLOAT cell_v_133 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_134 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_135 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_136 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_137 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_138 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_139 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_19 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);
CAN_Signal_FLOAT cell_v_133 = MakeSignalSigned(float, 0, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_134 = MakeSignalSigned(float, 8, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_135 = MakeSignalSigned(float, 16, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_136 = MakeSignalSigned(float, 24, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_137 = MakeSignalSigned(float, 32, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_138 = MakeSignalSigned(float, 40, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_v_139 = MakeSignalSigned(float, 48, 8, 0.012, 2.0, True);
CAN_Signal_FLOAT cell_ocv_offset_19 = MakeSignalSigned(float, 56, 8, 0.004, 0.0, True);

RX_CAN_Message(8) bms_voltages_19{drive_bus, 0x166, cell_v_133, cell_v_134, cell_v_135, cell_v_136, cell_v_137, cell_v_138, cell_v_139, cell_ocv_offset_19};

CAN_Signal_FLOAT cell_t_0 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_1 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_2 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_3 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_4 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_5 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_6 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_7 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_0 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_1 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_2 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_3 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_4 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_5 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_6 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_7 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_0{drive_bus, 0x167, cell_t_0, cell_t_1, cell_t_2, cell_t_3, cell_t_4, cell_t_5, cell_t_6, cell_t_7};

CAN_Signal_FLOAT cell_t_8 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_9 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_10 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_11 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_12 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_13 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_14 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_15 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_8 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_9 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_10 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_11 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_12 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_13 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_14 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_15 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_1{drive_bus, 0x168, cell_t_8, cell_t_9, cell_t_10, cell_t_11, cell_t_12, cell_t_13, cell_t_14, cell_t_15};

CAN_Signal_FLOAT cell_t_16 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_17 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_18 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_19 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_20 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_21 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_22 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_23 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_16 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_17 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_18 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_19 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_20 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_21 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_22 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_23 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_2{drive_bus, 0x169, cell_t_16, cell_t_17, cell_t_18, cell_t_19, cell_t_20, cell_t_21, cell_t_22, cell_t_23};

CAN_Signal_FLOAT cell_t_24 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_25 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_26 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_27 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_28 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_29 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_30 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_31 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_24 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_25 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_26 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_27 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_28 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_29 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_30 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_31 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_3{drive_bus, 0x16A, cell_t_24, cell_t_25, cell_t_26, cell_t_27, cell_t_28, cell_t_29, cell_t_30, cell_t_31};

CAN_Signal_FLOAT cell_t_32 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_33 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_34 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_35 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_36 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_37 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_38 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_39 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_32 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_33 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_34 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_35 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_36 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_37 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_38 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_39 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_4{drive_bus, 0x16B, cell_t_32, cell_t_33, cell_t_34, cell_t_35, cell_t_36, cell_t_37, cell_t_38, cell_t_39};

CAN_Signal_FLOAT cell_t_40 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_41 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_42 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_43 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_44 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_45 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_46 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_47 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_40 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_41 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_42 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_43 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_44 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_45 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_46 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_47 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_5{drive_bus, 0x16C, cell_t_40, cell_t_41, cell_t_42, cell_t_43, cell_t_44, cell_t_45, cell_t_46, cell_t_47};

CAN_Signal_FLOAT cell_t_48 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_49 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_50 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_51 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_52 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_53 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_54 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_55 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_48 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_49 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_50 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_51 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_52 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_53 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_54 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_55 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_6{drive_bus, 0x16D, cell_t_48, cell_t_49, cell_t_50, cell_t_51, cell_t_52, cell_t_53, cell_t_54, cell_t_55};

CAN_Signal_FLOAT cell_t_56 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_57 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_58 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_59 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_60 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_61 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_62 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_63 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_56 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_57 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_58 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_59 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_60 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_61 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_62 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_63 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_7{drive_bus, 0x16E, cell_t_56, cell_t_57, cell_t_58, cell_t_59, cell_t_60, cell_t_61, cell_t_62, cell_t_63};

CAN_Signal_FLOAT cell_t_64 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_65 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_66 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_67 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_68 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_69 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_70 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_71 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_64 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_65 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_66 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_67 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_68 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_69 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_70 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_71 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_8{drive_bus, 0x16F, cell_t_64, cell_t_65, cell_t_66, cell_t_67, cell_t_68, cell_t_69, cell_t_70, cell_t_71};

CAN_Signal_FLOAT cell_t_72 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_73 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_74 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_75 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_76 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_77 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_78 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_79 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_72 = MakeSignalSigned(float, 0, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_73 = MakeSignalSigned(float, 8, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_74 = MakeSignalSigned(float, 16, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_75 = MakeSignalSigned(float, 24, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_76 = MakeSignalSigned(float, 32, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_77 = MakeSignalSigned(float, 40, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_78 = MakeSignalSigned(float, 48, 8, 1.0, -40.0, True);
CAN_Signal_FLOAT cell_t_79 = MakeSignalSigned(float, 56, 8, 1.0, -40.0, True);

RX_CAN_Message(8) bms_temperatures_9{drive_bus, 0x170, cell_t_72, cell_t_73, cell_t_74, cell_t_75, cell_t_76, cell_t_77, cell_t_78, cell_t_79};

CAN_Signal_UINT64 controller_error = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 controller_error = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) can2usb_controller_error{drive_bus, 0x004, controller_error};

CAN_Signal_UINT64 controller_error_nack = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 controller_error_nack = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) can2usb_controller_error_nack_error{drive_bus, 0x024, controller_error_nack};

CAN_Signal_UINT64 controller_error_protocol_violation = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);
CAN_Signal_UINT64 controller_error_protocol_violation = MakeSignalExp(uint64_t, 0, 64, 1.0, 0.0);

RX_CAN_Message(1) can2usb_controller_error_protocol_violation{drive_bus, 0x00C, controller_error_protocol_violation};

}