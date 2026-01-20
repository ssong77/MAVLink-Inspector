#include "MAVLinkConnection.h"
#include <QDateTime>
#include <QDebug>

// MAVLink 헤더
#include "mavlink.h"
#include "MAVLinkMessageInfo.h"

MAVLinkConnection::MAVLinkConnection(QObject *parent)
    : QObject(parent)
    , m_socket(nullptr)
    , m_connected(false)
    , m_messageCount(0)
{
}

MAVLinkConnection::~MAVLinkConnection()
{
    disconnect();
}

void MAVLinkConnection::connectUDP(quint16 port)
{
    if (m_socket) {
        disconnect();
    }

    m_socket = new QUdpSocket(this);
    
    if (m_socket->bind(QHostAddress::Any, port)) {
        connect(m_socket, &QUdpSocket::readyRead, 
                this, &MAVLinkConnection::onReadyRead);
        
        m_connected = true;
        emit connectedChanged();
        
        qDebug() << "UDP socket bound to port" << port;
    } else {
        qWarning() << "Failed to bind UDP socket to port" << port;
        delete m_socket;
        m_socket = nullptr;
    }
}

void MAVLinkConnection::disconnect()
{
    if (m_socket) {
        m_socket->close();
        delete m_socket;
        m_socket = nullptr;
        
        m_connected = false;
        emit connectedChanged();
        
        qDebug() << "Disconnected";
    }
}

void MAVLinkConnection::onReadyRead()
{
    while (m_socket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_socket->pendingDatagramSize());
        
        QHostAddress sender;
        quint16 senderPort;
        
        m_socket->readDatagram(datagram.data(), datagram.size(), 
                               &sender, &senderPort);
        
        // MAVLink 메시지 파싱
        mavlink_message_t msg;
        mavlink_status_t status;
        
        for (int i = 0; i < datagram.size(); i++) {
            uint8_t c = datagram[i];
            

        if (mavlink_parse_char(MAVLINK_COMM_0, c, &msg, &status)) {
            m_messageCount++;
            emit messageCountChanged();
            
            QString timestamp = QDateTime::currentDateTime()
                .toString("hh:mm:ss.zzz");
            
            // 메시지 이름 가져오기
            QString type = MAVLinkMessageInfo::getMessageName(msg.msgid);
            
            // 상세 정보 포맷팅
            QString content = MAVLinkMessageInfo::formatMessageContent(msg);
            
            emit messageReceived(timestamp, type, content);
        }
    }
}
}