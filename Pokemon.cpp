#include "Pokemon.h"

Pokemon::Pokemon() :
    speed(1.0)
{
}

Pokemon::Pokemon(float s) :
    speed(s)
{
}

Pokemon::~Pokemon()
{

}

void Pokemon::update()
{

}

const QPointF& Pokemon::getPosition() const
{
    return positionOnScreen;
}

qreal Pokemon::getX() const
{
    return positionOnScreen.x();
}

qreal Pokemon::getY() const
{
    return positionOnScreen.y();
}