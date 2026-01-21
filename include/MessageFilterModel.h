#ifndef MESSAGEFILTERMODEL_H
#define MESSAGEFILTERMODEL_H

#include <QObject>
#include <QSet>
#include <QString>

class MessageFilterModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool showHeartbeat READ showHeartbeat WRITE setShowHeartbeat NOTIFY filterChanged)
    Q_PROPERTY(bool showAttitude READ showAttitude WRITE setShowAttitude NOTIFY filterChanged)
    Q_PROPERTY(bool showPosition READ showPosition WRITE setShowPosition NOTIFY filterChanged)
    Q_PROPERTY(bool showGPS READ showGPS WRITE setShowGPS NOTIFY filterChanged)
    Q_PROPERTY(bool showIMU READ showIMU WRITE setShowIMU NOTIFY filterChanged)
    Q_PROPERTY(bool showRC READ showRC WRITE setShowRC NOTIFY filterChanged)
    Q_PROPERTY(bool showCommand READ showCommand WRITE setShowCommand NOTIFY filterChanged)
    Q_PROPERTY(bool showOther READ showOther WRITE setShowOther NOTIFY filterChanged)

public:
    explicit MessageFilterModel(QObject *parent = nullptr);
    
    bool showHeartbeat() const { return m_showHeartbeat; }
    bool showAttitude() const { return m_showAttitude; }
    bool showPosition() const { return m_showPosition; }
    bool showGPS() const { return m_showGPS; }
    bool showIMU() const { return m_showIMU; }
    bool showRC() const { return m_showRC; }
    bool showCommand() const { return m_showCommand; }
    bool showOther() const { return m_showOther; }
    
    void setShowHeartbeat(bool show);
    void setShowAttitude(bool show);
    void setShowPosition(bool show);
    void setShowGPS(bool show);
    void setShowIMU(bool show);
    void setShowRC(bool show);
    void setShowCommand(bool show);
    void setShowOther(bool show);
    
    Q_INVOKABLE bool shouldShowMessage(const QString& messageType) const;
    Q_INVOKABLE void clearAll();
    Q_INVOKABLE void selectAll();

signals:
    void filterChanged();

private:
    bool m_showHeartbeat;
    bool m_showAttitude;
    bool m_showPosition;
    bool m_showGPS;
    bool m_showIMU;
    bool m_showRC;
    bool m_showCommand;
    bool m_showOther;
    
    QString getMessageCategory(const QString& messageType) const;
};

#endif // MESSAGEFILTERMODEL_H