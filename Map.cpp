#include "Map.h"

Map::Map() :
    width(10), height(10), tileWidth(64), tileHeight(32)
{

}

Map::~Map()
{
}

void Map::drawGrid(QPainter& painter, const QSize &size) const
{
    for(unsigned int x=0; x<width; ++x)
    {
        for(unsigned int y=0; y<height; ++y)
        {
            QPointF centerTile = conversionIsometric(x, y, size);
            QPolygonF tile;

            tile << QPointF(centerTile.x(), centerTile.y() - tileHeight * 0.5)
                 << QPointF(centerTile.x() + tileWidth * 0.5, centerTile.y())
                 << QPointF(centerTile.x(), centerTile.y() + tileHeight * 0.5)
                 << QPointF(centerTile.x() - tileWidth * 0.5, centerTile.y());

            painter.drawPolygon(tile);
        }
    }
}

QPointF Map::conversionIsometric(unsigned int x,
                                 unsigned int y,
                                 const QSize &size) const
{
    // Grid's center
    qreal offsetX = (width-1) * 0.5;
    qreal offsetY = (height-1) * 0.5;

    //qreal isoX = offsetX + (x-y) * tileWidth * 0.5;
    //qreal isoY = offsetY + (x+y) * tileHeight * 0.5;
    qreal isoX = size.width() * 0.5 + (x-offsetX-(y-offsetY)) * tileWidth * 0.5;
    qreal isoY = size.height() * 0.5 + (x-offsetX+(y-offsetY)) * tileHeight * 0.5;

    return QPointF(isoX, isoY);
}