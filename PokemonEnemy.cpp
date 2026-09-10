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

void PokemonEnemy::addInPath(int x, int y)
{
    path.push_back(std::make_unique<QPoint>(x, y));
}