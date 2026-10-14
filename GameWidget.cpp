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


    // Draw circles representing all pokemon ennemies
    unsigned int nbPokemonEnemy = game->getNbPokemonEnemy();
    for(unsigned int numPkmn=0; numPkmn<nbPokemonEnemy; ++numPkmn)
    {
        const QPointF& position = game->getPokemonEnemyPosition(numPkmn);
        painter.drawEllipse(position,10,10);
    }

    // Draw the pokemon player
    /*
    const QPoint* gridPosition = game->getPlayerPositionOnGrid();

    QPointF position = map->conversionIsometric(gridPosition->x(),
                                                gridPosition->y(),
                                                this->size());
    */
    const QPointF& playerPosition = game->getPlayerPosition();
    painter.drawEllipse(playerPosition, 15, 15);
}

void GameWidget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
        // déplacement vers le haut
        case Qt::Key_Z:
            qDebug() << "Z";
            game->setPlayerNextPositionOnScreen(0, -1, *map.get(), size());
            break;

        // déplacement vers le bas
        case Qt::Key_S:
            qDebug() << "S";
            game->setPlayerNextPositionOnScreen(0, 1, *map.get(), size());
            break;

        // déplacement vers la gauche
        case Qt::Key_Q:
            //qDebug() << "Q";
            game->setPlayerNextPositionOnScreen(-1, 0, *map.get(), size());
            break;

        // déplacement vers la droite
        case Qt::Key_D:
            qDebug() << "D";
            game->setPlayerNextPositionOnScreen(1, 0, *map.get(), size());
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