#include <QJSEngine>
#include <QObject>
#include <QQmlEngine>
#include <QStringList>


class MyLogger : public QObject {
    Q_OBJECT

    Q_PROPERTY(QStringList model READ model NOTIFY modelChanged)

public:
    ~MyLogger() = default;

    static MyLogger* self();

    Q_INVOKABLE void sayMyName();

    static QObject* provider(QQmlEngine *engine, QJSEngine *scriptEngine);

    QStringList model();

    static void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    void logMsg(QString msg);

signals:
    void modelChanged();

private:
    MyLogger(QObject *parent = nullptr);
    QStringList _list;
};
