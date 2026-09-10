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
    void update();
    int getPokemonEnemyX(unsigned int numPkmn) const;
    int getPokemonEnemyY(unsigned int numPkmn) const;
    unsigned int getNbPokemonEnemy() const;
};

#endif // GAME_H
