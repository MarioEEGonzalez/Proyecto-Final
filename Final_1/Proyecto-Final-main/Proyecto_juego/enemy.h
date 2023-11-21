#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"
#include <QTimer>

#include <QList>

class enemy:  public character
{
public:
    Q_OBJECT
public:
    enemy(int tipo);
    int tipo, damage;
    float posx,posy,speedx,speedy;
    QTimer *timer;
    float getx();
    void Detect_colision( );

public slots:
    void movetammy();
    void dead();


};

#endif // ENEMY_H
