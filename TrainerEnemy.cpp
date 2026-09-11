#include "TrainerEnemy.h"

#include <QDebug>

#define NB_POKEMON_MAX 6

TrainerEnemy::TrainerEnemy()
{
    addPokemon(100, 100, 45.0);
    addInPath(0,100,100);
    addInPath(0,300,100);
    addInPath(0,300,300);

    addPokemon(0, 200, 60.0);
    addInPath(1,0,200);
    addInPath(1,200,200);
    addInPath(1,200,400);
}

TrainerEnemy::~TrainerEnemy()
{

}

unsigned int TrainerEnemy::getNbPokemon() const
{
    return team.size();
}

PokemonEnemy* TrainerEnemy::getPokemonEnemy(unsigned int numPkmn) const
{
    if(!team.empty() && numPkmn < team.size())
        return team[numPkmn].get();
    return nullptr;
}

void TrainerEnemy::addPokemon(float x,
                              float y,
                              float speed)
{
    if(team.size() < NB_POKEMON_MAX)
        team.push_back(std::make_unique<PokemonEnemy>(x, y, speed));
}

void TrainerEnemy::addInPath(unsigned int numPkmn, float x, float y)
{
    if(!team.empty() && numPkmn < team.size())
        team[numPkmn]->addInPath(x, y);
}

const QPointF* TrainerEnemy::getPathPoint(unsigned int numPkmn, unsigned int numPoint) const
{
    if(!team.empty() && numPkmn < team.size())
        return team[numPkmn]->getPathPoint(numPoint);
    return nullptr;
}

unsigned int TrainerEnemy::getPathSize(unsigned int numPkmn) const
{
    if(!team.empty() && numPkmn < team.size())
        return team[numPkmn]->getPathSize();
    return 0;
}

void TrainerEnemy::printPath(unsigned int numPkmn)
{
    if(!team.empty() && numPkmn < team.size())
    {
        qDebug() << "PATH NUM:" << numPkmn << "\n";
        team[numPkmn]->printPath();
    }
    else
        qDebug() << "Pokemon NUM:" << numPkmn << " does not exist.\n";
}

void TrainerEnemy::update(float dt)
{
    for (unsigned int i=0; i<team.size(); ++i)
        team[i]->update(dt); //PokemonEnemy::update()
}