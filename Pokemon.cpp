#include "Pokemon.h"

Pokemon::Pokemon() :
    speed(1.0)
{
    position.setX(100.0);
    position.setY(100.0);
}

Pokemon::Pokemon(float beginX, float beginY, float s) :
    speed(s)
{
    position.setX(beginX);
    position.setY(beginY);
}

Pokemon::~Pokemon()
{

}

void Pokemon::update()
{

}

const QPointF& Pokemon::getPosition() const
{
    return position;
}

float Pokemon::getX() const
{
    return position.x();
}

float Pokemon::getY() const
{
    return position.y();
}