#include "enemy.h"

enemy::enemy(int tipo1)
{
    timer = new QTimer(this);
    timer->start(50);
    speed= 3;
    tipo=tipo1;
    if (tipo == 1){
        width = 60;
        height = 60;
        setPixmap (QPixmap(":/new/prefix1/tammy_down1.png").scaled(width,height));
        setHealth(100);
        posx= 260;
        posy = 20;
        speedx = 2* speed;
        speedy = 1*speed;
        //Detect_colision( );
        connect(timer,SIGNAL(timeout()),this,SLOT(movetammy()));
    }
    if (tipo == 0){
        setPixmap (QPixmap(":/new/prefix1/morty_down1.png").scaled(50,50));
    }



    setPos(posx,posy);




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

float enemy::getx(){
    return posx;
}

void enemy::dead(){
    scale=1000;
    count= 0;

    while(count<4*scale ){
    if(count <1 *scale){
        setPixmap(QPixmap (":/new/prefix1/kill1.png").scaled(50,50));
        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap(QPixmap (":/new/prefix1/kill2.png").scaled(50,50));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap(QPixmap (":/new/prefix1/kill2.png").scaled(50,50));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap(QPixmap (":/new/prefix1/kill2.png").scaled(50,50));
        count++;


    }

    }



}



QRectF enemy::boundingRect() const
{
    return QRectF(-width/2, -height/2, 2*width, 2*height);

}



