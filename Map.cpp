#include "Map.h"

Map::Map() :
    width(10), height(10), tileWidth(40), tileHeight(30)
{

}

Map::~Map()
{
}

void Map::draw(QPainter& painter, const QSize &size) const
{
    QPointF center = conversionIsometric(0, 0, size);

    QPolygonF tile;

    tile << QPointF(center.x(), center.y() - tileHeight * 0.5)
         << QPointF(center.x() + tileWidth * 0.5, center.y())
         << QPointF(center.x(), center.y() + tileHeight * 0.5)
         << QPointF(center.x() - tileWidth * 0.5, center.y());

    painter.drawPolygon(tile);
}

QPointF Map::conversionIsometric(unsigned int x, unsigned int y, const QSize& size) const
{
    qreal offsetX = size.width() * 0.5;
    qreal offsetY = size.height() * 0.5 - (height * tileHeight * 0.5);

    qreal isoX = offsetX + (x-y) * tileWidth * 0.5;
    qreal isoY = offsetY + (x+y) * tileHeight * 0.5;

    return QPointF(isoX, isoY);
}