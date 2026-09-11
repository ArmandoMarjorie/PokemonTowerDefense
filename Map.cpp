#include "Map.h"

Map::Map() :
    topLeft(400, 100), topRight(700, 250), bottomRight(400, 400), bottomLeft(100, 250)
{

}

Map::~Map()
{
}

void Map::draw(QPainter& painter, const QSize &size) const
{
    QPolygonF polygon;

    polygon << topLeft << topRight << bottomRight << bottomLeft;

    painter.drawPolygon(polygon);
}