#include "myrectangle.h"
#include <QDebug>
#include <QPainter>

MyRectangle::MyRectangle(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , _color({"Blue"})
{
    update();
}

void MyRectangle::paint(QPainter *painter)
{
    painter->fillRect(0 , 0, width(), height(), _color);
    update();
}

void MyRectangle::setColor(QString color)
{
    if(_color == color) {
        qDebug() << "Color is already in use!";
        return;
    }

    _color = color;
    emit colorChanged();
}

QString MyRectangle::color()
{
    return {};
}

void MyRectangle::setColorNS(MyRectangleNamespace::MyRectangleColors colorNS)
{
    if(_colorNS == colorNS) {
        qDebug() << "Color is already in use!";
        return;
    }

    _colorNS = colorNS;
    emit colorNSChanged();

    static QStringList colors {
        "pink",
        "blue",
        "red",
        "white",
        "black",
        "0x123456"
    };
    setColor(colors[_colorNS]);
}

MyRectangleNamespace::MyRectangleColors MyRectangle::colorNS()
{
    return _colorNS;
}
