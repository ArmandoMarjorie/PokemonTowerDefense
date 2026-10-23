#ifndef TRAINERENEMY_H
#define TRAINERENEMY_H

#include "PokemonEnemy.h"
#include "Map.h"

#include <vector>
#include <QPoint>

//! Trainer Enemy class.
/*!
    This class represents the current enemy.
    The enemy has a team of Pokemon Enemy.
*/

class TrainerEnemy
{
private:
    std::string name = ""; /*!< The enemy's name. */
    std::vector<std::unique_ptr<PokemonEnemy>> team; /*!< The enemy's pokemons. */

public:
    //! Default constructor. TODO: better constructor.
    TrainerEnemy();

    //! Updates the position of each enemy's pokemons on screen.
    //! Calls PokemonEnemy::update().
    /*!
        \param dt Delta time.
        \param map Map object to use conversionIsometric().
        \param size Windows' size to apply the isometric projection.
    */
    void update(float dt,
                const Map& map,
                const QSize& size);

    /* ============= Methods related to pokemons ============= */

    //! Get the number "numPkmn" pokemon of the enemy.
    /*!
        \param numPkmn Pokemon's index in the team vector.
        \return Pointer of the pokemon.
    */
    PokemonEnemy* getPokemonEnemy(unsigned int numPkmn) const;

    //! Get the number of pokemons of the enemy.
    /*!
        \return Number of pokemons of the enemy.
    */
    unsigned int getNbPokemon() const;

    //! Add a pokemon to the enemy's team.
    /*!
        \param speed Pokemon's speed. TODO: add all other stats.
    */
    void addPokemon(float speed);

    /* ============= Methods related to paths ============= */

    //! Add a cell point to the path of the numPkmn pokemon.
    //! No isometric view. Only cell of the grid. Ex: (2,3).
    /*!
        \param numPkmn Pokemon's index in the team vector.
        \param x x element of the new point.
        \param y y element of the new point.
    */
    void addInPath(unsigned int numPkmn,
                   unsigned int x,
                   unsigned int y);

    //! Get the cell point number "numPoint" of the numPkmn pokemon.
    //! No isometric view. Only cell of the grid. Ex: (2,3).
    /*!
        \param numPkmn Pokemon's index in the team vector.
        \param numPoint Index of the point in the path vector.
        \return Pointer of the cell point.
    */
    const QPoint* getPathPoint(unsigned int numPkmn, unsigned int numPoint) const;

    //! Get the lenght of the numPkmn pokemon's path.
    //! (e.g. number of cell points in the path vector).
    /*!
        \param numPkmn Pokemon's index in the team vector.
        \return Lenght of the numPkmn pokemon's path.
    */
    unsigned int getPathSize(unsigned int numPkmn) const;

    //! Print each cell points from the numPkmn pokemon's path.
    //! Only for tests. TODO: move this in an unit test.
    /*!
        \param numPkmn Pokemon's index in the team vector.
    */
    void printPath(unsigned int numPkmn);
};

#endif // TRAINERENEMY_H
