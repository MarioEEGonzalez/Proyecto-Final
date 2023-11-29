#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <QTimer>
#include <cmath>
#include <QList>

class enemy:  public character
{
public:
    Q_OBJECT
public:
    enemy(int tipo);

    int tipo, damage;
    //tamy movimeinto rebota con los limites
    float posx,posy,speedx,speedy;
    //ticket please movimiento circular
    int  centerX ;
    int  centerY ;
    int  radius ;
    float  omega;
    float T,k,n;

    // timers tammy
    QTimer *timer;
    QTimer *timer_dead_tammy;

    //timer tickets plese
    QTimer *timer_tickets;
    QTimer *timer_dead_tickets;

    float getx();

    void dead();

    QRectF boundingRect() const;


signals:
    void delete_tammy(int tipo);
public slots:
    void movetammy();
    void deadtammy();
    void movetickets();



};

#endif // ENEMY_H
