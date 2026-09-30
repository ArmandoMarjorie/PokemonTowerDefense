#include "GameWidget.h"

#include <QPainter>
#include <QDebug>

GameWidget::GameWidget(QWidget* parent)
    : QWidget{parent}
{
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

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
    game->update(dt, *map.get(), size());
    update(); // fct from QWidget. Calls paintEvent
}

void GameWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    map->drawGrid(painter, this->size());


    unsigned int nbPokemonEnemy = game->getNbPokemonEnemy();
    for(unsigned int numPkmn=0; numPkmn<nbPokemonEnemy; ++numPkmn)
    {
        // Draw circles representing pokemons
        const QPointF& position = game->getPokemonEnemyPosition(numPkmn);
        painter.drawEllipse(position,10,10);

        // Draw each paths
        /*
        unsigned int nbPoints = game->getPathSize(numPkmn);
        for (unsigned int i=0; i+1<nbPoints; ++i)
        {
            const QPoint* p1 = game->getEnemyPathPoint(numPkmn, i);
            const QPoint* p2 = game->getEnemyPathPoint(numPkmn, i+1);

            if(p1 != nullptr && p2 != nullptr)
                painter.drawLine(*p1, *p2);
        }
        */
        //game->printPath(numPkmn);
    }
}

void GameWidget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        // déplacement vers le haut
        case Qt::Key_Z:
            qDebug() << "Z";
            game->movePlayerPokemonOnGrid(0, -1);
            break;

        // déplacement vers le bas
        case Qt::Key_S:
            qDebug() << "S";
            game->movePlayerPokemonOnGrid(0, 1);
            break;

        // déplacement vers la gauche
        case Qt::Key_Q:
            //qDebug() << "Q";
            game->movePlayerPokemonOnGrid(-1, 0);
            break;

        // déplacement vers la droite
        case Qt::Key_D:
            qDebug() << "D";
            game->movePlayerPokemonOnGrid(1, 0);
            break;

        default:
            qDebug() << event->key();
            break;
    }

    update();
}


/*
void GameWidget::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Clic en :" << event->position();
    clickPosition = event->position().toPoint();
    update();
}
*/