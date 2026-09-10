#ifndef TRAINERENEMY_H
#define TRAINERENEMY_H

#include "PokemonEnemy.h"

#include <vector>
#include <QPoint>

class TrainerEnemy
{
private:
    std::vector<PokemonEnemy*> team;

public:
    TrainerEnemy();
    ~TrainerEnemy();
    void update();
    PokemonEnemy* getPokemonEnemy(unsigned int numPkmn) const;
    unsigned int getNbPokemon() const;
    void addPokemon(int x,
                    int y,
                    int speed);
};

#endif // TRAINERENEMY_H
