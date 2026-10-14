#include "PokemonPlayer.h"

PokemonPlayer::PokemonPlayer() :
    Pokemon()
{

}

PokemonPlayer::PokemonPlayer(float speed) :
    Pokemon(speed)
{
    positionOnGrid.setX(5);
    positionOnGrid.setY(5);
}

void PokemonPlayer::initPositionOnScreen(const Map& map, const QSize& size)
{
    positionOnScreen = map.conversionIsometric(positionOnGrid.x(), positionOnGrid.y(), size);
}

void PokemonPlayer::setNextPositionOnScreen(int dx,
                                    int dy,
                                    const Map& map,
                                    const QSize& size)
{
    // the player can't move if they're already moving
    if(isMoving)
        return;

    positionOnGrid += QPoint(dx, dy);
    nextPositionOnScreen = map.conversionIsometric(positionOnGrid.x(),
                                                   positionOnGrid.y(),
                                                   size);
    isMoving = true;
    //qDebug() << positionOnGrid;
}

void PokemonPlayer::update(float dt, const Map& map, const QSize& size)
{
    if(!positionInitialized)
    {
        initPositionOnScreen(map, size);
        positionInitialized = true;
    }

    // nothing to update
    if(!isMoving)
        return;

    QVector2D direction(nextPositionOnScreen.x() - positionOnScreen.x(),
                        nextPositionOnScreen.y() - positionOnScreen.y());

    // sqrt costs a lot, so I calculate the square
    qreal distanceSquare = direction.x() * direction.x() + direction.y() * direction.y();

    // comparing square...
    if(distanceSquare <= speed * speed * dt * dt)
    {
        positionOnScreen = nextPositionOnScreen;
        isMoving = false;
        return;
    }

    direction.normalize();
    positionOnScreen += QPointF(direction.x(), direction.y()) * speed * dt;
}























