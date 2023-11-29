#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "character.h"
#include "main_character.h"
#include "ammunition.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setLevel1();
    void keyPressEvent(QKeyEvent *e);
    QTimer *timer_colision;
    QList <ammunition*> balas;
    QList <enemy*> enemigos;
signals:
    void colision();


private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene1;
    QGraphicsPixmapItem *level1;
    main_character *pers;
    ammunition *bala;
    QString dir;
    enemy *enemy1;
    enemy *enemy2;

public slots:
void colision_enemy_bala();
void remove_enemy(int enemi);

};

#endif // MAINWINDOW_H
