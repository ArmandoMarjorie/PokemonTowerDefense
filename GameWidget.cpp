#include "GameWidget.h"

#include <QPainter>
#include <QDebug>

GameWidget::GameWidget(QWidget* parent)
    : QWidget{parent}
{
    timer = new QTimer(this);
    game = std::make_unique<Game>();
    map = std::make_unique<Map>();
    //clickPosition = QPoint(-100, -100);

    connect(timer, &QTimer::timeout, this, &GameWidget::updateGame);

    elapsedTimer.start();
    timer->start(16);
}

GameWidget::~GameWidget()
{
}

void GameWidget::updateGame()
{
    float dt = elapsedTimer.restart() / 1000.0;
    game->update(dt);
    update(); // fct from QWidget. Calls paintEvent
}

void GameWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    map->drawGrid(painter, this->size());

    /*
    unsigned int nbPokemonEnemy = game->getNbPokemonEnemy();
    for(unsigned int numPkmn=0; numPkmn<nbPokemonEnemy; ++numPkmn)
    {
        // Draw circles representing pokemons
        const QPointF& position = game->getPokemonEnemyPosition(numPkmn);
        painter.drawEllipse(position,50,50);

        // Draw each paths
        unsigned int nbPoints = game->getPathSize(numPkmn);
        for (unsigned int i=0; i+1<nbPoints; ++i)
        {
            const QPointF* p1 = game->getEnemyPathPoint(numPkmn, i);
            const QPointF* p2 = game->getEnemyPathPoint(numPkmn, i+1);

            if(p1 != nullptr && p2 != nullptr)
                painter.drawLine(*p1, *p2);
        }

        //game->printPath(numPkmn);
    }
    */
}
/*
void GameWidget::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Clic en :" << event->position();
    clickPosition = event->position().toPoint();
    update();
}
*/