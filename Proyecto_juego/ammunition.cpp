#include "ammunition.h"

ammunition::ammunition(QString name,int x, int y )
{
    setPixmap (QPixmap(name).scaled(40,40));
    posx= x+7;
    posy = y-30;
    setPos(posx,posy);
    timer = new QTimer(this);
    timer->start(70);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveup()));


}

void ammunition::moveup(){


    posy -=15;
    setPos(posx,posy);

    setPixmap (QPixmap(":/new/prefix1/49.png").scaled(40,40));
    setPixmap (QPixmap(":/new/prefix1/50.png").scaled(40,40));

}
