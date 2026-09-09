#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "Game.h"

#include <QWidget>
#include <QTimer>
#include <QMouseEvent>

class GameWidget : public QWidget
{
    Q_OBJECT
private:
    QTimer* timer = nullptr;
    QPoint clickPosition;
    Game* game;

private slots:
    void updateGame();

public:
    explicit GameWidget(QWidget* parent = nullptr);
    ~GameWidget();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

signals:
};

#endif // GAMEWIDGET_H
