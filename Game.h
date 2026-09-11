#ifndef GAME_H
#define GAME_H

#include "TrainerEnemy.h"

class Game
{
private:
    std::unique_ptr<TrainerEnemy> trainerEnemy = nullptr;

public:
    Game();
    ~Game();

    void update(float dt);

    const QPointF& getPokemonEnemyPosition(unsigned int numPkmn) const;
    float getPokemonEnemyX(unsigned int numPkmn) const;
    float getPokemonEnemyY(unsigned int numPkmn) const;
    unsigned int getNbPokemonEnemy() const;

    const QPointF* getEnemyPathPoint(unsigned int numPkmn, unsigned int numPoint) const;
    unsigned int getPathSize(unsigned int numPkmn) const;
    void printPath(unsigned int numPkmn);
};

#endif // GAME_H
