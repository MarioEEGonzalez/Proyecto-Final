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

    if (e->key()==Qt::Key_W && pers->pos().y() >= 0 )
    {

        //obst_collition(e);
    pers->moveup();

    dir= "up";
    }
    if (e->key()==Qt::Key_Space )
    {
    bala= new ammunition(":/new/prefix1/48.png",pers->pos().x(),pers->pos().y(),dir);
    scene1->addItem(bala);
    if (bala->pos().x()>500 || bala->pos().x()<0 || bala->pos().y()>500|| bala->pos().y()<0){
        delete bala;
    }


    }
    if (e->key()==Qt::Key_A && pers->pos().x() >= 0 )
    {

    //obst_collition(e);
    pers->moveleft();

    dir= "left";
    }
    if (e->key()==Qt::Key_D && pers->pos().x() <= 450 )
    {

    //obst_collition(e);
    pers->moveright();

    dir= "right";
    }
    if (e->key()==Qt::Key_S && pers->pos().y() <= 450 )
    {

    //obst_collition(e);
    pers->movedown();

    dir= "down";
    }

    //obst_collition(e);




}


MainWindow::~MainWindow()
{
    delete ui;
}

