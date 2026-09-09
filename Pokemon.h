#ifndef POKEMON_H
#define POKEMON_H

#include "PokemonType.h"

#include <QPoint>
#include <string>

class Pokemon
{
protected:
    std::string name = "";
    PokemonType type; // use like this: type = PokemonType::GRASS;

    // Statistiques
    int speed; // passer à float plus tard
    float pv;
    int level;
    int statAttack;
    int statDefense;

    // Current position
    QPoint position;

public:
    Pokemon();
    Pokemon(int beginX, int beginY, int s);
    ~Pokemon();
    void update();
    int getX() const;
    int getY() const;
};

#endif // POKEMON_H
