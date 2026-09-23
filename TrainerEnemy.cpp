#include "TrainerEnemy.h"

#include <QDebug>

#define NB_POKEMON_MAX 6

TrainerEnemy::TrainerEnemy()
{
    addPokemon(5.0);
    addInPath(0,0,0);
    addInPath(0,0,1);
    addInPath(0,0,2);

    addPokemon(10.0);
    addInPath(1,5,5);
    addInPath(1,6,5);
    addInPath(1,7,5);
    addInPath(1,7,4);
    addInPath(1,7,3);
    addInPath(1,8,3);
    addInPath(1,9,3);
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
    if(numPkmn < team.size())
        return team[numPkmn].get();
    return nullptr;
}

void TrainerEnemy::addPokemon(float speed)
{
    if(team.size() < NB_POKEMON_MAX)
        team.push_back(std::make_unique<PokemonEnemy>(speed));
}

void TrainerEnemy::addInPath(unsigned int numPkmn, unsigned int x, unsigned int y)
{
    if(numPkmn < team.size())
        team[numPkmn]->addInPath(x, y);
}

const QPoint* TrainerEnemy::getPathPoint(unsigned int numPkmn, unsigned int numPoint) const
{
    if(numPkmn < team.size())
        return team[numPkmn]->getPathPoint(numPoint);
    return nullptr;
}

unsigned int TrainerEnemy::getPathSize(unsigned int numPkmn) const
{
    if(numPkmn < team.size())
        return team[numPkmn]->getPathSize();
    return 0;
}

void TrainerEnemy::printPath(unsigned int numPkmn)
{
    if(numPkmn < team.size())
    {
        qDebug() << "PATH NUM:" << numPkmn << "\n";
        team[numPkmn]->printPath();
    }
    else
        qDebug() << "Pokemon NUM:" << numPkmn << " does not exist.\n";
}

void TrainerEnemy::update(float dt,
                          const Map& map,
                          const QSize& size)
{
    for (unsigned int numPkmn=0; numPkmn<team.size(); ++numPkmn)
    {
        team[numPkmn]->update(dt, map, size); //PokemonEnemy::update()
    }
}







