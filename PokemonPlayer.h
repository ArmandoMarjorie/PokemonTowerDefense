#ifndef POKEMONPLAYER_H
#define POKEMONPLAYER_H

#include "Pokemon.h"

#include <string>
#include <QDebug>
#include <QVector2D>

class PokemonPlayer  : public Pokemon
{
private:
    std::string surname = "";

    // equivalent of path in PokemonEnemy.
    // Position on grid (cell number), NO isometric projection.
    QPoint positionOnGrid;

    QPointF nextPositionOnScreen;

    bool isMoving = false;

public:
    PokemonPlayer();
    PokemonPlayer(float speed);

    void update(float dt);

    void setNextPositionOnScreen(unsigned int dx,
                                 unsigned int dy,
                                 const Map& map,
                                 const QSize& size);
    const QPoint* getPositionOnGrid() const;
};

#endif // POKEMONPLAYER_H
