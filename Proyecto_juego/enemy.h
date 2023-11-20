#ifndef ENEMY_H
#define ENEMY_H
#include"character.h"
#include <QTimer>

class enemy: public character
{
    Q_OBJECT
public:
    enemy(int tipo1);
    int tipo, damage;
    float posx,posy,speedx,speedy;
    QTimer *timer;

public slots:
    void movetammy();



};

#endif // ENEMY_H
