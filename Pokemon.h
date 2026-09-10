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
    int lvl;
    int speed; // passer à float plus tard
    float pv;
    int atk;
    int def;
    int atkSpe;
    int defSpe;

    // Current position : QPoint or just int x int y ?
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
