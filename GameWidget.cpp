#include "GameWidget.h"

#include<QPainter>
#include <QDebug>

GameWidget::GameWidget(QWidget* parent)
    : QWidget{parent}
{
    timer = new QTimer(this);
    game = new Game();
    clickPosition = QPoint(-100, -100);

    connect(timer, &QTimer::timeout, this, &GameWidget::updateGame);

    timer->start(16);
}

GameWidget::~GameWidget()
{
    delete game;
    game = nullptr;
}

void GameWidget::updateGame()
{
    /*circleX += 1;
    if(circleX + 100 >= this->width())
    {
        circleX = 0;
    }*/
    game->update();
    update(); // fct from QWidget. Calls paintEvent
}

void GameWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    unsigned int nbPokemonEnemy = game->getNbPokemonEnemy();

    for(unsigned int numPkmn=0; numPkmn<nbPokemonEnemy; ++numPkmn)
        painter.drawEllipse(game->getPokemonEnemyX(numPkmn),game->getPokemonEnemyY(numPkmn),100,100);
    /*painter.drawEllipse(clickPosition.x() - 25,
                        clickPosition.y() - 25,
                        50,
                        50);
*/
}

void GameWidget::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Clic en :" << event->position();
    clickPosition = event->position().toPoint();
    update();
}