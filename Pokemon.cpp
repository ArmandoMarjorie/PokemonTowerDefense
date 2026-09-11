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
    //position.setX(position.x() + speed);
    //x += speed;
}

float Pokemon::getX() const
{
    return position.x();
}

float Pokemon::getY() const
{
    return position.y();
}