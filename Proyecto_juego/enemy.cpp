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


    posx= 100;
    posy = 100;
    setPos(posx,posy);
    setHealth(100);
    speedx = 2;
    speedy = 2;

    timer = new QTimer(this);
    timer->start(70);
    connect(timer,SIGNAL(timeout()),this,SLOT(movetammy()));


}
void enemy::movetammy(){
    setPos(posx + speedx, posy + speedy);

    /*
    // Verificar colisión con las paredes
    if (posx <= 0 || x() >= 499) {
        speedx = -speedx; // Invertir la velocidad en X en caso de colisión
    }

    if (posy <= 0 || posy >= 499) {
        speedy = -speedy; // Invertir la velocidad en Y en caso de colisión
    }
*/
}

