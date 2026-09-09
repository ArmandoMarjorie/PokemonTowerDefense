#include "PokemonEnemy.h"

PokemonEnemy::PokemonEnemy() :
    x(100),
    y(100),
    speed(1.0)
{

}

PokemonEnemy::PokemonEnemy(int beginX, int beginY, float s) :
    x(beginX),
    y(beginY),
    speed(s)
{

}

PokemonEnemy::~PokemonEnemy()
{

}

void PokemonEnemy::update()
{
    x += speed;
}
int PokemonEnemy::getX() const
{
    return x;
}
int PokemonEnemy::getY() const
{
    return y;
}