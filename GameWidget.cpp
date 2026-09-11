#include "GameWidget.h"

#include <QPainter>
#include <QDebug>

GameWidget::GameWidget(QWidget* parent)
    : QWidget{parent}
{
    timer = new QTimer(this);
    game = std::make_unique<Game>();  // passage de pointeur à smart pointeur -> verif que tout est OK
    clickPosition = QPoint(-100, -100);

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
    game->update(dt); // todo deltatime
    update(); // fct from QWidget. Calls paintEvent
}

void GameWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    unsigned int nbPokemonEnemy = game->getNbPokemonEnemy();

    for(unsigned int numPkmn=0; numPkmn<nbPokemonEnemy; ++numPkmn)
    {
        const QPointF& position = game->getPokemonEnemyPosition(numPkmn);
        painter.drawEllipse(position,50,50);
    }
}

void GameWidget::mousePressEvent(QMouseEvent* event)
{
    qDebug() << "Clic en :" << event->position();
    clickPosition = event->position().toPoint();
    update();
}