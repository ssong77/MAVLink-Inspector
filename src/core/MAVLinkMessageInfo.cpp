#include "MAVLinkMessageInfo.h"
#include "common/mavlink.h"

QMap<uint32_t, QString> MAVLinkMessageInfo::s_messageNames;
bool MAVLinkMessageInfo::s_initialized = false;

void MAVLinkMessageInfo::initMessageNames()
{
    if (s_initialized) return;
    
    // 주요 메시지들 매핑
    s_messageNames[MAVLINK_MSG_ID_HEARTBEAT] = "HEARTBEAT";
    s_messageNames[MAVLINK_MSG_ID_SYS_STATUS] = "SYS_STATUS";
    s_messageNames[MAVLINK_MSG_ID_SYSTEM_TIME] = "SYSTEM_TIME";
    s_messageNames[MAVLINK_MSG_ID_PING] = "PING";
    s_messageNames[MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL] = "CHANGE_OPERATOR_CONTROL";
    s_messageNames[MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK] = "CHANGE_OPERATOR_CONTROL_ACK";
    s_messageNames[MAVLINK_MSG_ID_AUTH_KEY] = "AUTH_KEY";
    s_messageNames[MAVLINK_MSG_ID_LINK_NODE_STATUS] = "LINK_NODE_STATUS";
    s_messageNames[MAVLINK_MSG_ID_SET_MODE] = "SET_MODE";
    s_messageNames[MAVLINK_MSG_ID_PARAM_REQUEST_READ] = "PARAM_REQUEST_READ";
    s_messageNames[MAVLINK_MSG_ID_PARAM_REQUEST_LIST] = "PARAM_REQUEST_LIST";
    s_messageNames[MAVLINK_MSG_ID_PARAM_VALUE] = "PARAM_VALUE";
    s_messageNames[MAVLINK_MSG_ID_PARAM_SET] = "PARAM_SET";
    s_messageNames[MAVLINK_MSG_ID_GPS_RAW_INT] = "GPS_RAW_INT";
    s_messageNames[MAVLINK_MSG_ID_GPS_STATUS] = "GPS_STATUS";
    s_messageNames[MAVLINK_MSG_ID_SCALED_IMU] = "SCALED_IMU";
    s_messageNames[MAVLINK_MSG_ID_RAW_IMU] = "RAW_IMU";
    s_messageNames[MAVLINK_MSG_ID_RAW_PRESSURE] = "RAW_PRESSURE";
    s_messageNames[MAVLINK_MSG_ID_SCALED_PRESSURE] = "SCALED_PRESSURE";
    s_messageNames[MAVLINK_MSG_ID_ATTITUDE] = "ATTITUDE";
    s_messageNames[MAVLINK_MSG_ID_ATTITUDE_QUATERNION] = "ATTITUDE_QUATERNION";
    s_messageNames[MAVLINK_MSG_ID_LOCAL_POSITION_NED] = "LOCAL_POSITION_NED";
    s_messageNames[MAVLINK_MSG_ID_GLOBAL_POSITION_INT] = "GLOBAL_POSITION_INT";
    s_messageNames[MAVLINK_MSG_ID_RC_CHANNELS_SCALED] = "RC_CHANNELS_SCALED";
    s_messageNames[MAVLINK_MSG_ID_RC_CHANNELS_RAW] = "RC_CHANNELS_RAW";
    s_messageNames[MAVLINK_MSG_ID_SERVO_OUTPUT_RAW] = "SERVO_OUTPUT_RAW";
    s_messageNames[MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST] = "MISSION_REQUEST_PARTIAL_LIST";
    s_messageNames[MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST] = "MISSION_WRITE_PARTIAL_LIST";
    s_messageNames[MAVLINK_MSG_ID_MISSION_ITEM] = "MISSION_ITEM";
    s_messageNames[MAVLINK_MSG_ID_MISSION_REQUEST] = "MISSION_REQUEST";
    s_messageNames[MAVLINK_MSG_ID_MISSION_SET_CURRENT] = "MISSION_SET_CURRENT";
    s_messageNames[MAVLINK_MSG_ID_MISSION_CURRENT] = "MISSION_CURRENT";
    s_messageNames[MAVLINK_MSG_ID_MISSION_REQUEST_LIST] = "MISSION_REQUEST_LIST";
    s_messageNames[MAVLINK_MSG_ID_MISSION_COUNT] = "MISSION_COUNT";
    s_messageNames[MAVLINK_MSG_ID_MISSION_CLEAR_ALL] = "MISSION_CLEAR_ALL";
    s_messageNames[MAVLINK_MSG_ID_MISSION_ITEM_REACHED] = "MISSION_ITEM_REACHED";
    s_messageNames[MAVLINK_MSG_ID_MISSION_ACK] = "MISSION_ACK";
    s_messageNames[MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN] = "SET_GPS_GLOBAL_ORIGIN";
    s_messageNames[MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN] = "GPS_GLOBAL_ORIGIN";
    s_messageNames[MAVLINK_MSG_ID_PARAM_MAP_RC] = "PARAM_MAP_RC";
    s_messageNames[MAVLINK_MSG_ID_MISSION_REQUEST_INT] = "MISSION_REQUEST_INT";
    s_messageNames[MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA] = "SAFETY_SET_ALLOWED_AREA";
    s_messageNames[MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA] = "SAFETY_ALLOWED_AREA";
    s_messageNames[MAVLINK_MSG_ID_ATTITUDE_QUATERNION_COV] = "ATTITUDE_QUATERNION_COV";
    s_messageNames[MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT] = "NAV_CONTROLLER_OUTPUT";
    s_messageNames[MAVLINK_MSG_ID_GLOBAL_POSITION_INT_COV] = "GLOBAL_POSITION_INT_COV";
    s_messageNames[MAVLINK_MSG_ID_LOCAL_POSITION_NED_COV] = "LOCAL_POSITION_NED_COV";
    s_messageNames[MAVLINK_MSG_ID_RC_CHANNELS] = "RC_CHANNELS";
    s_messageNames[MAVLINK_MSG_ID_REQUEST_DATA_STREAM] = "REQUEST_DATA_STREAM";
    s_messageNames[MAVLINK_MSG_ID_DATA_STREAM] = "DATA_STREAM";
    s_messageNames[MAVLINK_MSG_ID_MANUAL_CONTROL] = "MANUAL_CONTROL";
    s_messageNames[MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE] = "RC_CHANNELS_OVERRIDE";
    s_messageNames[MAVLINK_MSG_ID_MISSION_ITEM_INT] = "MISSION_ITEM_INT";
    s_messageNames[MAVLINK_MSG_ID_VFR_HUD] = "VFR_HUD";
    s_messageNames[MAVLINK_MSG_ID_COMMAND_INT] = "COMMAND_INT";
    s_messageNames[MAVLINK_MSG_ID_COMMAND_LONG] = "COMMAND_LONG";
    s_messageNames[MAVLINK_MSG_ID_COMMAND_ACK] = "COMMAND_ACK";
    s_messageNames[MAVLINK_MSG_ID_MANUAL_SETPOINT] = "MANUAL_SETPOINT";
    s_messageNames[MAVLINK_MSG_ID_SET_ATTITUDE_TARGET] = "SET_ATTITUDE_TARGET";
    s_messageNames[MAVLINK_MSG_ID_ATTITUDE_TARGET] = "ATTITUDE_TARGET";
    s_messageNames[MAVLINK_MSG_ID_SET_POSITION_TARGET_LOCAL_NED] = "SET_POSITION_TARGET_LOCAL_NED";
    s_messageNames[MAVLINK_MSG_ID_POSITION_TARGET_LOCAL_NED] = "POSITION_TARGET_LOCAL_NED";
    s_messageNames[MAVLINK_MSG_ID_SET_POSITION_TARGET_GLOBAL_INT] = "SET_POSITION_TARGET_GLOBAL_INT";
    s_messageNames[MAVLINK_MSG_ID_POSITION_TARGET_GLOBAL_INT] = "POSITION_TARGET_GLOBAL_INT";
    s_messageNames[MAVLINK_MSG_ID_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET] = "LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET";
    s_messageNames[MAVLINK_MSG_ID_HIL_STATE] = "HIL_STATE";
    s_messageNames[MAVLINK_MSG_ID_HIL_CONTROLS] = "HIL_CONTROLS";
    s_messageNames[MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW] = "HIL_RC_INPUTS_RAW";
    s_messageNames[MAVLINK_MSG_ID_HIL_ACTUATOR_CONTROLS] = "HIL_ACTUATOR_CONTROLS";
    s_messageNames[MAVLINK_MSG_ID_OPTICAL_FLOW] = "OPTICAL_FLOW";
    s_messageNames[MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE] = "GLOBAL_VISION_POSITION_ESTIMATE";
    s_messageNames[MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE] = "VISION_POSITION_ESTIMATE";
    s_messageNames[MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE] = "VISION_SPEED_ESTIMATE";
    s_messageNames[MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE] = "VICON_POSITION_ESTIMATE";
    s_messageNames[MAVLINK_MSG_ID_HIGHRES_IMU] = "HIGHRES_IMU";
    s_messageNames[MAVLINK_MSG_ID_OPTICAL_FLOW_RAD] = "OPTICAL_FLOW_RAD";
    s_messageNames[MAVLINK_MSG_ID_HIL_SENSOR] = "HIL_SENSOR";
    s_messageNames[MAVLINK_MSG_ID_SIM_STATE] = "SIM_STATE";
    s_messageNames[MAVLINK_MSG_ID_RADIO_STATUS] = "RADIO_STATUS";
    s_messageNames[MAVLINK_MSG_ID_FILE_TRANSFER_PROTOCOL] = "FILE_TRANSFER_PROTOCOL";
    s_messageNames[MAVLINK_MSG_ID_TIMESYNC] = "TIMESYNC";
    s_messageNames[MAVLINK_MSG_ID_CAMERA_TRIGGER] = "CAMERA_TRIGGER";
    s_messageNames[MAVLINK_MSG_ID_HIL_GPS] = "HIL_GPS";
    s_messageNames[MAVLINK_MSG_ID_HIL_OPTICAL_FLOW] = "HIL_OPTICAL_FLOW";
    s_messageNames[MAVLINK_MSG_ID_HIL_STATE_QUATERNION] = "HIL_STATE_QUATERNION";
    s_messageNames[MAVLINK_MSG_ID_SCALED_IMU2] = "SCALED_IMU2";
    s_messageNames[MAVLINK_MSG_ID_LOG_REQUEST_LIST] = "LOG_REQUEST_LIST";
    s_messageNames[MAVLINK_MSG_ID_LOG_ENTRY] = "LOG_ENTRY";
    s_messageNames[MAVLINK_MSG_ID_LOG_REQUEST_DATA] = "LOG_REQUEST_DATA";
    s_messageNames[MAVLINK_MSG_ID_LOG_DATA] = "LOG_DATA";
    s_messageNames[MAVLINK_MSG_ID_LOG_ERASE] = "LOG_ERASE";
    s_messageNames[MAVLINK_MSG_ID_LOG_REQUEST_END] = "LOG_REQUEST_END";
    s_messageNames[MAVLINK_MSG_ID_GPS_INJECT_DATA] = "GPS_INJECT_DATA";
    s_messageNames[MAVLINK_MSG_ID_GPS2_RAW] = "GPS2_RAW";
    s_messageNames[MAVLINK_MSG_ID_POWER_STATUS] = "POWER_STATUS";
    s_messageNames[MAVLINK_MSG_ID_SERIAL_CONTROL] = "SERIAL_CONTROL";
    s_messageNames[MAVLINK_MSG_ID_GPS_RTK] = "GPS_RTK";
    s_messageNames[MAVLINK_MSG_ID_GPS2_RTK] = "GPS2_RTK";
    s_messageNames[MAVLINK_MSG_ID_SCALED_IMU3] = "SCALED_IMU3";
    s_messageNames[MAVLINK_MSG_ID_DATA_TRANSMISSION_HANDSHAKE] = "DATA_TRANSMISSION_HANDSHAKE";
    s_messageNames[MAVLINK_MSG_ID_ENCAPSULATED_DATA] = "ENCAPSULATED_DATA";
    s_messageNames[MAVLINK_MSG_ID_DISTANCE_SENSOR] = "DISTANCE_SENSOR";
    s_messageNames[MAVLINK_MSG_ID_TERRAIN_REQUEST] = "TERRAIN_REQUEST";
    s_messageNames[MAVLINK_MSG_ID_TERRAIN_DATA] = "TERRAIN_DATA";
    s_messageNames[MAVLINK_MSG_ID_TERRAIN_CHECK] = "TERRAIN_CHECK";
    s_messageNames[MAVLINK_MSG_ID_TERRAIN_REPORT] = "TERRAIN_REPORT";
    s_messageNames[MAVLINK_MSG_ID_SCALED_PRESSURE2] = "SCALED_PRESSURE2";
    s_messageNames[MAVLINK_MSG_ID_ATT_POS_MOCAP] = "ATT_POS_MOCAP";
    s_messageNames[MAVLINK_MSG_ID_SET_ACTUATOR_CONTROL_TARGET] = "SET_ACTUATOR_CONTROL_TARGET";
    s_messageNames[MAVLINK_MSG_ID_ACTUATOR_CONTROL_TARGET] = "ACTUATOR_CONTROL_TARGET";
    s_messageNames[MAVLINK_MSG_ID_ALTITUDE] = "ALTITUDE";
    s_messageNames[MAVLINK_MSG_ID_RESOURCE_REQUEST] = "RESOURCE_REQUEST";
    s_messageNames[MAVLINK_MSG_ID_SCALED_PRESSURE3] = "SCALED_PRESSURE3";
    s_messageNames[MAVLINK_MSG_ID_FOLLOW_TARGET] = "FOLLOW_TARGET";
    s_messageNames[MAVLINK_MSG_ID_CONTROL_SYSTEM_STATE] = "CONTROL_SYSTEM_STATE";
    s_messageNames[MAVLINK_MSG_ID_BATTERY_STATUS] = "BATTERY_STATUS";
    s_messageNames[MAVLINK_MSG_ID_AUTOPILOT_VERSION] = "AUTOPILOT_VERSION";
    s_messageNames[MAVLINK_MSG_ID_LANDING_TARGET] = "LANDING_TARGET";
    s_messageNames[MAVLINK_MSG_ID_ESTIMATOR_STATUS] = "ESTIMATOR_STATUS";
    s_messageNames[MAVLINK_MSG_ID_WIND_COV] = "WIND_COV";
    s_messageNames[MAVLINK_MSG_ID_GPS_INPUT] = "GPS_INPUT";
    s_messageNames[MAVLINK_MSG_ID_GPS_RTCM_DATA] = "GPS_RTCM_DATA";
    s_messageNames[MAVLINK_MSG_ID_HIGH_LATENCY] = "HIGH_LATENCY";
    s_messageNames[MAVLINK_MSG_ID_HIGH_LATENCY2] = "HIGH_LATENCY2";
    s_messageNames[MAVLINK_MSG_ID_VIBRATION] = "VIBRATION";
    s_messageNames[MAVLINK_MSG_ID_HOME_POSITION] = "HOME_POSITION";
    s_messageNames[MAVLINK_MSG_ID_SET_HOME_POSITION] = "SET_HOME_POSITION";
    s_messageNames[MAVLINK_MSG_ID_MESSAGE_INTERVAL] = "MESSAGE_INTERVAL";
    s_messageNames[MAVLINK_MSG_ID_EXTENDED_SYS_STATE] = "EXTENDED_SYS_STATE";
    s_messageNames[MAVLINK_MSG_ID_ADSB_VEHICLE] = "ADSB_VEHICLE";
    s_messageNames[MAVLINK_MSG_ID_COLLISION] = "COLLISION";
    s_messageNames[MAVLINK_MSG_ID_V2_EXTENSION] = "V2_EXTENSION";
    s_messageNames[MAVLINK_MSG_ID_MEMORY_VECT] = "MEMORY_VECT";
    s_messageNames[MAVLINK_MSG_ID_DEBUG_VECT] = "DEBUG_VECT";
    s_messageNames[MAVLINK_MSG_ID_NAMED_VALUE_FLOAT] = "NAMED_VALUE_FLOAT";
    s_messageNames[MAVLINK_MSG_ID_NAMED_VALUE_INT] = "NAMED_VALUE_INT";
    s_messageNames[MAVLINK_MSG_ID_STATUSTEXT] = "STATUSTEXT";
    s_messageNames[MAVLINK_MSG_ID_DEBUG] = "DEBUG";
    s_messageNames[MAVLINK_MSG_ID_SETUP_SIGNING] = "SETUP_SIGNING";
    s_messageNames[MAVLINK_MSG_ID_BUTTON_CHANGE] = "BUTTON_CHANGE";
    s_messageNames[MAVLINK_MSG_ID_PLAY_TUNE] = "PLAY_TUNE";
    s_messageNames[MAVLINK_MSG_ID_CAMERA_INFORMATION] = "CAMERA_INFORMATION";
    s_messageNames[MAVLINK_MSG_ID_CAMERA_SETTINGS] = "CAMERA_SETTINGS";
    s_messageNames[MAVLINK_MSG_ID_STORAGE_INFORMATION] = "STORAGE_INFORMATION";
    s_messageNames[MAVLINK_MSG_ID_CAMERA_CAPTURE_STATUS] = "CAMERA_CAPTURE_STATUS";
    s_messageNames[MAVLINK_MSG_ID_CAMERA_IMAGE_CAPTURED] = "CAMERA_IMAGE_CAPTURED";
    s_messageNames[MAVLINK_MSG_ID_FLIGHT_INFORMATION] = "FLIGHT_INFORMATION";
    s_messageNames[MAVLINK_MSG_ID_MOUNT_ORIENTATION] = "MOUNT_ORIENTATION";
    s_messageNames[MAVLINK_MSG_ID_LOGGING_DATA] = "LOGGING_DATA";
    s_messageNames[MAVLINK_MSG_ID_LOGGING_DATA_ACKED] = "LOGGING_DATA_ACKED";
    s_messageNames[MAVLINK_MSG_ID_LOGGING_ACK] = "LOGGING_ACK";
    s_messageNames[MAVLINK_MSG_ID_VIDEO_STREAM_INFORMATION] = "VIDEO_STREAM_INFORMATION";
    s_messageNames[MAVLINK_MSG_ID_VIDEO_STREAM_STATUS] = "VIDEO_STREAM_STATUS";
    s_messageNames[MAVLINK_MSG_ID_WIFI_CONFIG_AP] = "WIFI_CONFIG_AP";
    s_messageNames[MAVLINK_MSG_ID_PROTOCOL_VERSION] = "PROTOCOL_VERSION";
    s_messageNames[MAVLINK_MSG_ID_UAVCAN_NODE_STATUS] = "UAVCAN_NODE_STATUS";
    s_messageNames[MAVLINK_MSG_ID_UAVCAN_NODE_INFO] = "UAVCAN_NODE_INFO";
    s_messageNames[MAVLINK_MSG_ID_OBSTACLE_DISTANCE] = "OBSTACLE_DISTANCE";
    s_messageNames[MAVLINK_MSG_ID_ODOMETRY] = "ODOMETRY";
    
    s_initialized = true;
}

QString MAVLinkMessageInfo::getMessageName(uint32_t msgid)
{
    initMessageNames();
    
    if (s_messageNames.contains(msgid)) {
        return s_messageNames[msgid];
    }
    
    return QString("UNKNOWN_%1").arg(msgid);
}

QString MAVLinkMessageInfo::formatMessageContent(const mavlink_message_t& msg)
{
    QString content = QString("sys=%1 comp=%2 seq=%3")
        .arg(msg.sysid)
        .arg(msg.compid)
        .arg(msg.seq);
    
    // 메시지별 추가 정보 (주요 메시지들만)
    switch(msg.msgid) {
        case MAVLINK_MSG_ID_HEARTBEAT: {
            mavlink_heartbeat_t hb;
            mavlink_msg_heartbeat_decode(&msg, &hb);
            content += QString(" | type=%1 autopilot=%2 mode=%3")
                .arg(hb.type)
                .arg(hb.autopilot)
                .arg(hb.custom_mode);
            break;
        }
        case MAVLINK_MSG_ID_ATTITUDE: {
            mavlink_attitude_t att;
            mavlink_msg_attitude_decode(&msg, &att);
            content += QString(" | roll=%.2f pitch=%.2f yaw=%.2f")
                .arg(att.roll * 57.2958) // rad to deg
                .arg(att.pitch * 57.2958)
                .arg(att.yaw * 57.2958);
            break;
        }
        case MAVLINK_MSG_ID_GLOBAL_POSITION_INT: {
            mavlink_global_position_int_t pos;
            mavlink_msg_global_position_int_decode(&msg, &pos);
            content += QString(" | lat=%.6f lon=%.6f alt=%.1fm")
                .arg(pos.lat / 1e7)
                .arg(pos.lon / 1e7)
                .arg(pos.alt / 1000.0);
            break;
        }
        case MAVLINK_MSG_ID_STATUSTEXT: {
            mavlink_statustext_t st;
            mavlink_msg_statustext_decode(&msg, &st);
            content += QString(" | severity=%1 text=%2")
                .arg(st.severity)
                .arg(QString::fromLatin1(st.text, 50));
            break;
        }
        // 더 많은 메시지 타입 추가 가능
    }
    
    return content;
}