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
/*
const QPoint* Player::getPokemonPositionOnGrid() const
{
    if(currentPkmn < team.size())
        return team[currentPkmn]->getPositionOnGrid();
    return nullptr;
}*/

PokemonPlayer* Player::getCurrentPokemon() const
{
    if(currentPkmn < team.size())
        return team[currentPkmn].get();
    return nullptr;
}

void Player::setNextPositionOnScreen(int dx, int dy,
                                     const Map& map,
                                     const QSize& size)
{
    if(currentPkmn < team.size())
        team[currentPkmn]->setNextPositionOnScreen(dx, dy, map, size);
}

void Player::update(float dt, const Map& map, const QSize& size)
{
    if(currentPkmn < team.size())
        team[currentPkmn]->update(dt, map, size); //PokemonPlayer::update()
}