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

const QPoint* PokemonPlayer::getPositionOnGrid() const
{
    return &positionOnGrid;
}

void PokemonPlayer::setNextPositionOnScreen(unsigned int dx,
                                    unsigned int dy,
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

void PokemonPlayer::update(float dt)
{

}























