#ifndef TRAINERENEMY_H
#define TRAINERENEMY_H

#include "PokemonEnemy.h"

#include <vector>
#include <QPoint>

class TrainerEnemy
{
private:
    std::string name = "";
    std::vector<std::unique_ptr<PokemonEnemy>> team;

public:
    TrainerEnemy();
    ~TrainerEnemy();
    void update(float dt);
    PokemonEnemy* getPokemonEnemy(unsigned int numPkmn) const;
    unsigned int getNbPokemon() const;
    void addPokemon(float x,
                    float y,
                    float speed);
    void addInPath(unsigned int numPkmn,
                   float x,
                   float y);
};

#endif // TRAINERENEMY_H
