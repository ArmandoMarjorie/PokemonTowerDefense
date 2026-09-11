#include "Game.h"

Game::Game()
{
    trainerEnemy = std::make_unique<TrainerEnemy>();
}

Game::~Game()
{

}

float Game::getPokemonEnemyX(unsigned int numPkmn) const
{
    return trainerEnemy->getPokemonEnemy(numPkmn)->getX();
}

float Game::getPokemonEnemyY(unsigned int numPkmn) const
{
    return trainerEnemy->getPokemonEnemy(numPkmn)->getY();
}

unsigned int Game::getNbPokemonEnemy() const
{
    return trainerEnemy->getNbPokemon();
}

void Game::update(float dt)
{
    trainerEnemy->update(dt);
}

