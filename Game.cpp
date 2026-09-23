#include "Game.h"

Game::Game()
{
    trainerEnemy = std::make_unique<TrainerEnemy>();
}

Game::~Game()
{

}

const QPointF& Game::getPokemonEnemyPosition(unsigned int numPkmn) const
{
    return trainerEnemy->getPokemonEnemy(numPkmn)->getPosition();
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

const QPoint* Game::getEnemyPathPoint(unsigned int numPkmn, unsigned int numPoint) const
{
    return trainerEnemy->getPathPoint(numPkmn, numPoint);
}

unsigned int Game::getPathSize(unsigned int numPkmn) const
{
    return trainerEnemy->getPathSize(numPkmn);
}

void Game::printPath(unsigned int numPkmn)
{
    trainerEnemy->printPath(numPkmn);
}

void Game::update(float dt,
                  const Map& map,
                  const QSize& size)
{
    trainerEnemy->update(dt, map, size);
}

