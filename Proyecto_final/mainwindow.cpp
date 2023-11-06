#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    level1 = new QGraphicsScene();
    ui->graphicsView->setScene(level1);

    //message1 = level1->addText(QString "INCIANDO",QFont f("Helvetica"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

