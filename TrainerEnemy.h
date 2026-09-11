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

    // Methods relating to pokemons
    PokemonEnemy* getPokemonEnemy(unsigned int numPkmn) const;
    unsigned int getNbPokemon() const;
    void addPokemon(float x,
                    float y,
                    float speed);

    // Methods relating to paths
    void addInPath(unsigned int numPkmn,
                   float x,
                   float y);
    const QPointF* getPathPoint(unsigned int numPkmn, unsigned int numPoint) const;
    unsigned int getPathSize(unsigned int numPkmn) const;
    void printPath(unsigned int numPkmn);
};

#endif // TRAINERENEMY_H
