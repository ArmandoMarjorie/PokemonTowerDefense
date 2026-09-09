#include "Pokemon.h"

Pokemon::Pokemon() :
    speed(1.0)
{
    position.setX(100);
    position.setY(100);
}

Pokemon::Pokemon(int beginX, int beginY, int s) :
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
    position.setX(position.x() + speed);
    //x += speed;
}

int Pokemon::getX() const
{
    return position.x();
}

int Pokemon::getY() const
{
    return position.y();
}