#include "Player.h"
#define NB_POKEMON_MAX 6

Player::Player() :
    currentPkmn(0)
{
    addPokemon(3.0);
}

void Player::addPokemon(float speed)
{
    if(team.size() < NB_POKEMON_MAX)
        team.push_back(std::make_unique<PokemonPlayer>(speed));
}

const QPoint* Player::getPokemonPositionOnGrid() const
{
    if(currentPkmn < team.size())
        return team[currentPkmn]->getPositionOnGrid();
    return nullptr;
}

void Player::movePokemonOnGrid(int dx, int dy)
{
    if(currentPkmn < team.size())
        team[currentPkmn]->move(dx, dy);
}