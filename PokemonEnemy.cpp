#include "PokemonEnemy.h"

#include <QDebug>

PokemonEnemy::PokemonEnemy() :
    Pokemon(), currentPoint(0)
{

}

PokemonEnemy::PokemonEnemy(float beginX, float beginY, float s) :
    Pokemon(beginX, beginY, s), currentPoint(0)
{

}

PokemonEnemy::~PokemonEnemy()
{

}

void PokemonEnemy::addInPath(float x, float y)
{
    path.push_back(std::make_unique<QPointF>(x, y));
}

const QPointF* PokemonEnemy::getPathPoint(unsigned int numPoint) const
{
    return path[numPoint].get();
}

unsigned int PokemonEnemy::getPathSize() const
{
    return path.size();
}

void PokemonEnemy::printPath()
{
    for(unsigned int i=0; i<path.size(); ++i)
    {
        qDebug() << "Point " << i << ": (" << path[i]->x() << ", " << path[i]->y() << ")\n";
    }
}

void PokemonEnemy::update(float dt, unsigned int numPkmn, bool debug)
{
    // no next point
    if(currentPoint+1 >= path.size())
        return;

    QPointF* nextPoint = path[currentPoint+1].get();

    QVector2D direction(nextPoint->x() - position.x(),
                        nextPoint->y() - position.y());

    // sqrt costs a lot, so I calculate the square
    float distanceSquare = direction.x() * direction.x() + direction.y() * direction.y();

    // comparing square...
    if(distanceSquare <= speed * speed * dt * dt)
    {
        position = *nextPoint;
        currentPoint++;
        if(debug)
            qDebug() << "Position[" << numPkmn << "]: " << position ;
        return;
    }

    direction.normalize();
    position += QPointF(direction.x(), direction.y()) * speed * dt;

    if(debug)
        qDebug() << "Position[" << numPkmn << "]: " << position ;
}