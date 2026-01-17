#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "MAVLinkConnection.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    
    app.setOrganizationName("MAVLinkInspector");
    app.setApplicationName("MAVLink Inspector");
    app.setApplicationVersion("0.1.0");

    // MAVLink 연결 객체 생성
    MAVLinkConnection mavlink;

    QQmlApplicationEngine engine;
    
    // QML에서 접근 가능하도록 등록
    engine.rootContext()->setContextProperty("mavlink", &mavlink);
    
    const QUrl url(QStringLiteral("qrc:/MAVLinkInspector/Main.qml"));
    
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection
    );
    
    engine.load(url);

    return app.exec();
}
