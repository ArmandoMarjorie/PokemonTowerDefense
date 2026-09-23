#ifndef MAP_H
#define MAP_H

#include <QPointF>
#include <QPainter>
#include <QSize>

class Map
{
private:
    // number of tiles forming the grid
    unsigned int width; // row
    unsigned int height; // col

    // Size of tiles
    unsigned int tileWidth;
    unsigned int tileHeight;

    QPointF conversionIsometric(unsigned int x, unsigned int y, const QSize& size) const;

public:
    Map();
    ~Map();

    void draw(QPainter& painter, const QSize& size) const;
};

#endif // MAP_H
