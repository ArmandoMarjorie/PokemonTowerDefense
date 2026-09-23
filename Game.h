#ifndef GAME_H
#define GAME_H

#include "TrainerEnemy.h"
#include "Map.h"

class Game
{
private:
    std::unique_ptr<TrainerEnemy> trainerEnemy = nullptr;

public:
    Game();
    ~Game();

    void update(float dt, const Map &map, const QSize& size);

    const QPointF& getPokemonEnemyPosition(unsigned int numPkmn) const;
    float getPokemonEnemyX(unsigned int numPkmn) const;
    float getPokemonEnemyY(unsigned int numPkmn) const;
    unsigned int getNbPokemonEnemy() const;

    const QPoint* getEnemyPathPoint(unsigned int numPkmn, unsigned int numPoint) const;
    unsigned int getPathSize(unsigned int numPkmn) const;
    void printPath(unsigned int numPkmn);
};

#endif // GAME_H
