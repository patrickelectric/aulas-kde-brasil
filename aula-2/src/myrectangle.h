#pragma once

#include <QQuickPaintedItem>

namespace MyRectangleNamespace {
    Q_NAMESPACE
    enum MyRectangleColors {
        Pink = 0,
        Blue,
        Red,
        White,
        Black,
        Unknown,
    };
    Q_ENUM_NS(MyRectangleColors)
};

class MyRectangle : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(MyRectangleNamespace::MyRectangleColors colorNS READ colorNS WRITE setColorNS NOTIFY colorNSChanged)

public:
    MyRectangle(QQuickItem *parent = nullptr);

    void setColor(QString color);
    QString color();

    void setColorNS(MyRectangleNamespace::MyRectangleColors colorNS);
    MyRectangleNamespace::MyRectangleColors colorNS();

    void paint(QPainter *painter);

signals:
    void colorChanged();
    void colorNSChanged();

private:
    QString _color;
    MyRectangleNamespace::MyRectangleColors _colorNS;
};
