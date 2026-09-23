#ifndef TRAINERENEMY_H
#define TRAINERENEMY_H

#include "PokemonEnemy.h"
#include "Map.h"

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

    void update(float dt,
                const Map& map,
                const QSize& size);

    // Methods related to pokemons
    PokemonEnemy* getPokemonEnemy(unsigned int numPkmn) const;
    unsigned int getNbPokemon() const;
    void addPokemon(float speed);

    // Methods related to paths
    void addInPath(unsigned int numPkmn,
                   unsigned int x,
                   unsigned int y);
    const QPoint* getPathPoint(unsigned int numPkmn, unsigned int numPoint) const;
    unsigned int getPathSize(unsigned int numPkmn) const;
    void printPath(unsigned int numPkmn);
};

#endif // TRAINERENEMY_H
