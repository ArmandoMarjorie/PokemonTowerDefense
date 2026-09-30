#ifndef POKEMONPLAYER_H
#define POKEMONPLAYER_H

#include "Pokemon.h"

#include <string>
#include <QDebug>

class PokemonPlayer  : public Pokemon
{
private:
    std::string surname = "";
    QPoint positionOnGrid;

public:
    PokemonPlayer();
    PokemonPlayer(float speed);
    void move(int dx, int dy);
    const QPoint* getPositionOnGrid() const;
};

#endif // POKEMONPLAYER_H
