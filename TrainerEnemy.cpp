#include "TrainerEnemy.h"

#define NB_POKEMON_MAX 6

TrainerEnemy::TrainerEnemy()
{
    team.push_back(new PokemonEnemy(200,200,3));
    team.push_back(new PokemonEnemy(300,300,2));
}

TrainerEnemy::~TrainerEnemy()
{
    for (unsigned int i=0; i<team.size(); ++i)
    {
        delete team[i];
        team[i] = nullptr;
    }
    team.clear();
}

unsigned int TrainerEnemy::getNbPokemon() const
{
    return team.size();
}

PokemonEnemy* TrainerEnemy::getPokemonEnemy(unsigned int numPkmn) const
{
    if(!team.empty() && numPkmn < team.size())
        return team[numPkmn];
    return nullptr;
}

void TrainerEnemy::addPokemon()
{
    if(team.size() < NB_POKEMON_MAX)
        team.push_back(new PokemonEnemy());
}

void TrainerEnemy::update()
{
    for (unsigned int i=0; i<team.size(); ++i)
        team[i]->update();
}