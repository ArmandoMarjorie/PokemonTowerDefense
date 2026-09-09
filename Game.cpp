#include "Game.h"

Game::Game()
{
    trainerEnemy = new TrainerEnemy();
}

Game::~Game()
{
    delete trainerEnemy;
    trainerEnemy = nullptr;
}

int Game::getPokemonEnemyX(unsigned int numPkmn) const
{
    return trainerEnemy->getPokemonEnemy(numPkmn)->getX();
}

int Game::getPokemonEnemyY(unsigned int numPkmn) const
{
    return trainerEnemy->getPokemonEnemy(numPkmn)->getY();
}

unsigned int Game::getNbPokemonEnemy() const
{
    return trainerEnemy->getNbPokemon();
}

void Game::update()
{
    trainerEnemy->update();
}

