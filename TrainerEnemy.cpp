#include "TrainerEnemy.h"

#define NB_POKEMON_MAX 6

TrainerEnemy::TrainerEnemy()
{
    addPokemon(100, 100, 1);
    addPokemon(200, 200, 2);
    addPokemon(300, 300, 3);
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

void TrainerEnemy::addPokemon(int x,
                              int y,
                              int speed)
{
    if(team.size() < NB_POKEMON_MAX)
        team.push_back(std::make_unique<PokemonEnemy>(x, y, speed));
}

void TrainerEnemy::update()
{
    for (unsigned int i=0; i<team.size(); ++i)
        team[i]->update(); //Pokemon::update()
}