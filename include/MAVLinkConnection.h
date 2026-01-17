#ifndef MAVLINKCONNECTION_H
#define MAVLINKCONNECTION_H

#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>

class MAVLinkConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connectedChanged)
    Q_PROPERTY(int messageCount READ messageCount NOTIFY messageCountChanged)

public:
    explicit MAVLinkConnection(QObject *parent = nullptr);
    ~MAVLinkConnection();

    bool isConnected() const { return m_connected; }
    int messageCount() const { return m_messageCount; }

public slots:
    void connectUDP(quint16 port);
    void disconnect();

signals:
    void connectedChanged();
    void messageCountChanged();
    void messageReceived(QString timestamp, QString type, QString content);

private slots:
    void onReadyRead();

private:
    QUdpSocket* m_socket;
    bool m_connected;
    int m_messageCount;
};

#endif // MAVLINKCONNECTION_H