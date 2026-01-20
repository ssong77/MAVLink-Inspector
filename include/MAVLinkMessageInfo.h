#ifndef MAVLINKMESSAGEINFO_H
#define MAVLINKMESSAGEINFO_H

#include <QString>
#include <QMap>
#include <stdint.h>  // uint32_t 정의

// Forward declarations
struct __mavlink_message;
typedef struct __mavlink_message mavlink_message_t;

class MAVLinkMessageInfo
{
public:
    static QString getMessageName(uint32_t msgid);
    static QString formatMessageContent(const mavlink_message_t& msg);
    
private:
    static void initMessageNames();
    static QMap<uint32_t, QString> s_messageNames;
    static bool s_initialized;
};

#endif // MAVLINKMESSAGEINFO_H