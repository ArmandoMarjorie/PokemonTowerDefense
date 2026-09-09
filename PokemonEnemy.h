#ifndef POKEMONENEMY_H
#define POKEMONENEMY_H

#include "Pokemon.h"

#include <QPoint>
#include <vector>

class PokemonEnemy : public Pokemon
{
private:
    std::vector<QPoint> path;
public:
    PokemonEnemy();
    PokemonEnemy(int beginX, int beginY, int s);
    ~PokemonEnemy();
    /*
    void update();
    int getX() const;
    int getY() const;
    */
};

#endif // POKEMONENEMY_H
