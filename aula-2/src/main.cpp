#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

#include "myrectangle.h"
#include "mylogger.h"

int main(int argc, char *argv[]) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQuickStyle::setStyle("Material");

    qInstallMessageHandler(MyLogger::self()->messageHandler);

    //MyRectangle
    qmlRegisterType<MyRectangle>("MyRectangle", 1, 0, "MyRectangle");

    //MyRectangleColor
    qmlRegisterUncreatableMetaObject(
        MyRectangleNamespace::staticMetaObject,
        "MyRectangleNamespace", 1, 0,
        "MyRectangleNamespace",
        "Aulas KDE Brasil"
    );

    MyLogger::self()->sayMyName();

    //MyLogger
    qmlRegisterSingletonType<MyLogger>("MyLogger", 1, 0, "MyLogger", MyLogger::self()->provider);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine appEngine("qrc:/main.qml");

    return app.exec();
}
