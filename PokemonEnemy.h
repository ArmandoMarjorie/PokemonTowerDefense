#ifndef POKEMONENEMY_H
#define POKEMONENEMY_H

#include "Pokemon.h"

#include <QPoint>
#include <vector>
#include <memory>

class PokemonEnemy : public Pokemon
{
private:
    std::vector<std::unique_ptr<QPoint>> path;
public:
    PokemonEnemy();
    PokemonEnemy(int beginX, int beginY, int s);
    ~PokemonEnemy();
    void addInPath(int x, int y);
};

#endif // POKEMONENEMY_H
