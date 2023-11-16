#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "character.h"
#include "main_character.h"
#include "ammunition.h"
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
    QTimer *time_bala;
private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene1;
    QGraphicsPixmapItem *level1;
    main_character *pers;
    ammunition *bala;
    QString dir;

};

#endif // MAINWINDOW_H
