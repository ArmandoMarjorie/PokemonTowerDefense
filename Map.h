#ifndef MAP_H
#define MAP_H

#include <QPointF>
#include <QPainter>
#include <QSize>

class Map
{
private:
    QPointF topLeft;
    QPointF topRight;
    QPointF bottomLeft;
    QPointF bottomRight;

public:
    Map();
    ~Map();

    void draw(QPainter& painter, const QSize& size) const;
};

#endif // MAP_H
