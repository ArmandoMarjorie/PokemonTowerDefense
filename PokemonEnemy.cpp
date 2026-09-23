#include "PokemonEnemy.h"

#include <QDebug>

PokemonEnemy::PokemonEnemy() :
    Pokemon(), currentPoint(0)
{

}

PokemonEnemy::PokemonEnemy(float s) :
    Pokemon(s), currentPoint(0)
{

}

void PokemonEnemy::initPositionOnScreen(const Map& map, const QSize& size)
{
    if(path.empty())
        return;
    QPoint* firstPoint = path[0].get();
    positionOnScreen = map.conversionIsometric(firstPoint->x(), firstPoint->y(), size);
}

PokemonEnemy::~PokemonEnemy()
{

}

void PokemonEnemy::addInPath(unsigned int x, unsigned int y)
{
    path.push_back(std::make_unique<QPoint>(x, y));
}

const QPoint* PokemonEnemy::getPathPoint(unsigned int numPoint) const
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

void PokemonEnemy::update(float dt,
                          const Map& map,
                          const QSize& size,
                          unsigned int numPkmn,
                          bool debug)
{
    if(!positionInitialized && !path.empty())
    {
        QPoint* startPoint = path[currentPoint].get();

        positionOnScreen = map.conversionIsometric(
            startPoint->x(),
            startPoint->y(),
            size);

        positionInitialized = true;
    }

    // no next point
    if(currentPoint+1 >= path.size())
        return;

    QPoint* nextPoint = path[currentPoint+1].get();
    QPointF nextPositionScreen = map.conversionIsometric(nextPoint->x(), nextPoint->y(), size);


    QVector2D direction(nextPositionScreen.x() - positionOnScreen.x(),
                        nextPositionScreen.y() - positionOnScreen.y());

    // sqrt costs a lot, so I calculate the square
    qreal distanceSquare = direction.x() * direction.x() + direction.y() * direction.y();

    // comparing square...
    if(distanceSquare <= speed * speed * dt * dt)
    {
        positionOnScreen = nextPositionScreen;
        currentPoint++;
        if(debug)
            qDebug() << "Position[" << numPkmn << "]: " << positionOnScreen ;
        return;
    }

    direction.normalize();
    positionOnScreen += QPointF(direction.x(), direction.y()) * speed * dt;

    if(debug)
        qDebug() << "Position[" << numPkmn << "]: " << positionOnScreen ;
}