#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene1= new QGraphicsScene();
    ui->graphicsView->setScene(scene1);

    QImage Bg(":/new/prefix1/FONDO1.png");
    QBrush Bgimg(Bg);
    ui->graphicsView->setBackgroundBrush(Bgimg);
    int sc_factor = 1;
    scene1->setSceneRect(0,0,(ui->graphicsView->width() - 2)/sc_factor,(ui->graphicsView->height() - 2)/sc_factor); //
    ui->graphicsView->scale(sc_factor,sc_factor);

    int char_num = 1;

    if(char_num ==1)
    {
    pers = new main_character(":/new/prefix1/rick1.png");}//rick
    else if(char_num == 2){
    pers = new main_character("D:/MIO/UNIVERSIDAD/Informatica 2/Proyecto-Final/sprites/morty.png");//morty

    }
    scene1->addItem(pers);




}

void MainWindow::keyPressEvent(QKeyEvent *e){
    QString dir = "down";
    if (e->key()==Qt::Key_W && pers->pos().y() >= 10 )
    {

        //obst_collition(e);
    pers->moveup();

    dir= "up";
    }
    if (e->key()==Qt::Key_Space )
    {
    bala= new ammunition(":/new/prefix1/48.png",pers->pos().x(),pers->pos().y());
    scene1->addItem(bala);



    dir= "up";
    }


    //obst_collition(e);




}


MainWindow::~MainWindow()
{
    delete ui;
}

