#ifndef POKEMONENEMY_H
#define POKEMONENEMY_H

#include "Pokemon.h"

#include <QPoint>
#include <QVector2D>
#include <vector>
#include <memory>

class PokemonEnemy : public Pokemon
{
private:
    std::vector<std::unique_ptr<QPointF>> path;
    unsigned int currentPoint; // current index in vector path

public:
    PokemonEnemy();
    PokemonEnemy(float beginX, float beginY, float s);
    ~PokemonEnemy();


    void addInPath(float x, float y);
    const QPointF* getPathPoint(unsigned int numPoint) const;
    unsigned int getPathSize() const;
    void printPath(); // for debugging purpose


    void update(float dt, unsigned int numPkmn=0, bool debug=false);
};

#endif // POKEMONENEMY_H
