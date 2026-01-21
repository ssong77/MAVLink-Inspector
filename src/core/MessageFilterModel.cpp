#include "MessageFilterModel.h"

MessageFilterModel::MessageFilterModel(QObject *parent)
    : QObject(parent)
    , m_showHeartbeat(true)
    , m_showAttitude(true)
    , m_showPosition(true)
    , m_showGPS(true)
    , m_showIMU(true)
    , m_showRC(true)
    , m_showCommand(true)
    , m_showOther(true)
{
}

void MessageFilterModel::setShowHeartbeat(bool show)
{
    if (m_showHeartbeat != show) {
        m_showHeartbeat = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowAttitude(bool show)
{
    if (m_showAttitude != show) {
        m_showAttitude = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowPosition(bool show)
{
    if (m_showPosition != show) {
        m_showPosition = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowGPS(bool show)
{
    if (m_showGPS != show) {
        m_showGPS = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowIMU(bool show)
{
    if (m_showIMU != show) {
        m_showIMU = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowRC(bool show)
{
    if (m_showRC != show) {
        m_showRC = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowCommand(bool show)
{
    if (m_showCommand != show) {
        m_showCommand = show;
        emit filterChanged();
    }
}

void MessageFilterModel::setShowOther(bool show)
{
    if (m_showOther != show) {
        m_showOther = show;
        emit filterChanged();
    }
}

QString MessageFilterModel::getMessageCategory(const QString& messageType) const
{
    if (messageType == "HEARTBEAT") {
        return "heartbeat";
    } else if (messageType.contains("ATTITUDE") || messageType.contains("QUATERNION")) {
        return "attitude";
    } else if (messageType.contains("POSITION") || messageType.contains("LOCAL_POSITION") || 
               messageType.contains("GLOBAL_POSITION")) {
        return "position";
    } else if (messageType.contains("GPS")) {
        return "gps";
    } else if (messageType.contains("IMU") || messageType.contains("SCALED_PRESSURE") ||
               messageType.contains("RAW_PRESSURE")) {
        return "imu";
    } else if (messageType.contains("RC_CHANNELS") || messageType.contains("MANUAL_CONTROL") ||
               messageType.contains("SERVO")) {
        return "rc";
    } else if (messageType.contains("COMMAND")) {
        return "command";
    } else {
        return "other";
    }
}

bool MessageFilterModel::shouldShowMessage(const QString& messageType) const
{
    QString category = getMessageCategory(messageType);
    
    if (category == "heartbeat") return m_showHeartbeat;
    if (category == "attitude") return m_showAttitude;
    if (category == "position") return m_showPosition;
    if (category == "gps") return m_showGPS;
    if (category == "imu") return m_showIMU;
    if (category == "rc") return m_showRC;
    if (category == "command") return m_showCommand;
    return m_showOther;
}

void MessageFilterModel::clearAll()
{
    m_showHeartbeat = false;
    m_showAttitude = false;
    m_showPosition = false;
    m_showGPS = false;
    m_showIMU = false;
    m_showRC = false;
    m_showCommand = false;
    m_showOther = false;
    emit filterChanged();
}

void MessageFilterModel::selectAll()
{
    m_showHeartbeat = true;
    m_showAttitude = true;
    m_showPosition = true;
    m_showGPS = true;
    m_showIMU = true;
    m_showRC = true;
    m_showCommand = true;
    m_showOther = true;
    emit filterChanged();
}