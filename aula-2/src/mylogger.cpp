#include "mylogger.h"

#include <QDebug>

MyLogger::MyLogger(QObject *parent)
    : QObject(parent)
    , _list({"Start logger!"})
{

}

MyLogger* MyLogger::self()
{
    static MyLogger* self = new MyLogger();
    return self;
}

void MyLogger::sayMyName()
{
    qDebug() << "MyLogger";
}

QStringList MyLogger::model()
{
    return _list;
}

void MyLogger::messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString localMsg = msg.toLocal8Bit();
    QString file = context.file ? QString(context.file) : QString();
    QString function = context.function ? QString(context.function) : QString();

    MyLogger::self()->logMsg(QString("file: %1 (%2): %3").arg(file).arg(function).arg(localMsg));
}

void MyLogger::logMsg(QString msg)
{
    _list.append(msg);
    emit modelChanged();
}

QObject* MyLogger::provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return self();
}
