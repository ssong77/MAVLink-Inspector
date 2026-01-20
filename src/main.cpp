#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QFile file("E:/MAV/debug.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);
        out << QDateTime::currentDateTime().toString("hh:mm:ss.zzz") << " ";
        
        switch (type) {
        case QtDebugMsg: out << "DEBUG: "; break;
        case QtWarningMsg: out << "WARNING: "; break;
        case QtCriticalMsg: out << "CRITICAL: "; break;
        case QtFatalMsg: out << "FATAL: "; break;
        default: out << "INFO: "; break;
        }
        
        out << msg << "\n";
        file.close();
    }
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(messageHandler);
    
    qDebug() << "Starting application...";
    
    QGuiApplication app(argc, argv);
    
    qDebug() << "Creating QML engine...";
    QQmlApplicationEngine engine;
    
    qDebug() << "Loading QML...";
    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    
    if (engine.rootObjects().isEmpty()) {
        qCritical() << "FAILED TO LOAD QML";
        return -1;
    }
    
    qDebug() << "QML LOADED SUCCESSFULLY";
    qDebug() << "Entering event loop...";

    return app.exec();
}