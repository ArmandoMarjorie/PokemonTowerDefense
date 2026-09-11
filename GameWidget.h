#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "Game.h"
#include "Map.h"

#include <QWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QElapsedTimer>

class GameWidget : public QWidget
{
    Q_OBJECT

private:
    QTimer* timer = nullptr;
    //QPoint clickPosition;
    QElapsedTimer elapsedTimer;
    std::unique_ptr<Game> game;
    std::unique_ptr<Map> map;

private slots:
    void updateGame();

public:
    explicit GameWidget(QWidget* parent = nullptr);
    ~GameWidget();

protected:
    void paintEvent(QPaintEvent* event) override;
    //void mousePressEvent(QMouseEvent* event) override;

signals:
};

#endif // GAMEWIDGET_H
