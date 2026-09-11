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
    float getPokemonEnemyX(unsigned int numPkmn) const;
    float getPokemonEnemyY(unsigned int numPkmn) const;
    unsigned int getNbPokemonEnemy() const;
};

#endif // GAME_H
