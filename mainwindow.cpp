#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "GameWidget.h"

#include <QLabel>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GameWidget* gameWidget = new GameWidget(this);
    setCentralWidget(gameWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
