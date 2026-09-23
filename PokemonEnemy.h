#ifndef POKEMONENEMY_H
#define POKEMONENEMY_H

#include "Pokemon.h"
#include "Map.h"

#include <QPoint>
#include <QVector2D>
#include <vector>
#include <memory>

class PokemonEnemy : public Pokemon
{
private:
    std::vector<std::unique_ptr<QPoint>> path; // contains tiles coordinates
    unsigned int currentPoint; // current index in vector path
    bool positionInitialized = false;

public:
    PokemonEnemy();
    PokemonEnemy(float s);
    ~PokemonEnemy();


    void addInPath(unsigned int x, unsigned int y);
    const QPoint* getPathPoint(unsigned int numPoint) const;
    unsigned int getPathSize() const;
    void printPath(); // for debugging purpose
    void initPositionOnScreen(const Map& map, const QSize& size);

    void update(float dt,
                const Map& map,
                const QSize& size,
                unsigned int numPkmn=0,
                bool debug=false);
};

#endif // POKEMONENEMY_H
