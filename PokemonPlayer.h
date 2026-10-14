#ifndef POKEMONPLAYER_H
#define POKEMONPLAYER_H

#include "Pokemon.h"

#include <string>
#include <QDebug>
#include <QVector2D>

//! Pokemon Player class.
/*!
    This class represents a pokemon belonging to the player.
    It differs from the Pokemon Enemy class, as this pokemon does not
    have a path nor an AI.
*/

class PokemonPlayer  : public Pokemon
{
private:
    std::string surname = ""; /*!< The player can give a surname to their pokemon. */
    QPoint positionOnGrid; /*!< Position on grid (cell number, ex: (4,5)).
                                NO isometric projection.
                                Equivalent of path in PokemonEnemy. */
    bool isMoving = false; /*!< Controls the player: they can't move if they're already moving. */

public:
    //! Default constructor.
    PokemonPlayer();
    //! A constructor.
    /*!
        TODO: init pokemon with a file.
    */
    PokemonPlayer(float speed);

    //! Updates the position on screen.
    /*!
        \param dt Delta time.
        \param map Map object to use conversionIsometric().
        \param size Windows' size to apply the isometric projection.
    */
    void update(float dt, const Map &map, const QSize &size);

    //! Initializes the position on screen from the position on grid: applies the isometric projection.
    /*!
        \param map Map object to use conversionIsometric().
        \param size Windows' size to apply the isometric projection.
    */
    void initPositionOnScreen(const Map& map, const QSize& size);

    //! Set the next position on screen (where the player wants to go) and applies the isometric projection.
    /*!
        \param dx Direction on the x axis.
        \param dy Direction on the y axis.
        \param map Map object to use conversionIsometric().
        \param size Windows' size to apply the isometric projection.
    */
    void setNextPositionOnScreen(int dx,
                                 int dy,
                                 const Map& map,
                                 const QSize& size);
};

#endif // POKEMONPLAYER_H
