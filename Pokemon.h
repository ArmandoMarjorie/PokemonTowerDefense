#ifndef POKEMON_H
#define POKEMON_H

#include "PokemonType.h"
#include "Map.h"

#include <QPoint>
#include <string>

class Pokemon
{
protected:
    std::string name = "";
    PokemonType type; // use like this: type = PokemonType::GRASS;

    // Statistiques
    int lvl;
    float speed;
    float pv;
    int atk;
    int def;
    int atkSpe;
    int defSpe;

    // Current position on screen (with isometric projection)
    QPointF positionOnScreen;

    //todo: use it in PokemonEnemy
    QPointF nextPositionOnScreen; /*!< Target position when the pokemon moves, with isometric projection. */

    bool positionInitialized = false;

public:
    Pokemon();
    Pokemon(float s);
    ~Pokemon();
    void update();
    const QPointF& getPosition() const;
    void initPosition(const Map& map, const QSize& size);
    qreal getX() const;
    qreal getY() const;
};

#endif // POKEMON_H
