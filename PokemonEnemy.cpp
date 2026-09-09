#include "PokemonEnemy.h"

PokemonEnemy::PokemonEnemy() :
    Pokemon()
{

}

PokemonEnemy::PokemonEnemy(int beginX, int beginY, int s) :
    Pokemon(beginX, beginY, s)
{

}

PokemonEnemy::~PokemonEnemy()
{

}

/*
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
*/