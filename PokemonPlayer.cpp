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

void PokemonPlayer::move(int dx, int dy)
{
    positionOnGrid += QPoint(dx, dy);
    qDebug() << positionOnGrid;
}
