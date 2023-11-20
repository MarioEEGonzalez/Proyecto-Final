#include "enemy.h"

enemy::enemy(int tipo1)
{
    tipo=tipo1;
    if (tipo == 1){
        setPixmap (QPixmap(":/new/prefix1/tammy_down1.png").scaled(60,60));
    }
    if (tipo == 0){
        setPixmap (QPixmap(":/new/prefix1/morty_down1.png").scaled(50,50));
    }


    posx= 260;
    posy = 20;
    setPos(posx,posy);
    setHealth(100);
    speedx = 10;
    speedy = 8;

    timer = new QTimer(this);
    timer->start(70);
    connect(timer,SIGNAL(timeout()),this,SLOT(movetammy()));

}
void enemy::movetammy(){

    posx +=speedx;
    posy += speedy;
    setPos(posx, posy);


    // Verificar colisión con las paredes
    if (posx <= 0 || x() >= 450) {
        speedx = -speedx; // Invertir la velocidad en X en caso de colisión
    }

    if (posy <= 0 || posy >= 450) {
        speedy = -speedy; // Invertir la velocidad en Y en caso de colisión
    }

}
