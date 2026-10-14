#ifndef PLAYER_H
#define PLAYER_H

#include "PokemonPlayer.h"

#include <vector>
#include <QPoint>

class Player
{
private:
    std::string name = "";
    std::vector<std::unique_ptr<PokemonPlayer>> team;
    unsigned int currentPkmn;

public:
    Player();
    PokemonPlayer* getCurrentPokemon() const;
    void addPokemon(float speed);
    //const QPoint* getPokemonPositionOnGrid() const;
    //void movePokemonOnGrid(int dx, int dy);
    void setNextPositionOnScreen(int dx, int dy,
                                const Map& map,
                                const QSize& size);
    void update(float dt, const Map& map, const QSize& size);
};

#endif // PLAYER_H
