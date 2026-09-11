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
    float speed; // passer à float plus tard
    float pv;
    int atk;
    int def;
    int atkSpe;
    int defSpe;

    // Current position : QPointF or just float x float y ?
    QPointF position;

public:
    Pokemon();
    Pokemon(float beginX, float beginY, float s);
    ~Pokemon();
    void update();
    float getX() const;
    float getY() const;
};

#endif // POKEMON_H
