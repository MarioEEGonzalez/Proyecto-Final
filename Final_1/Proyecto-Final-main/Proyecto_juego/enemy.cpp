#include "enemy.h"

enemy::enemy(int tipo1)
{

    speed= 5;
    tipo=tipo1;
    width = 60;
    height = 60;
    if (tipo == 1){
        timer = new QTimer(this);
        timer->start(100);
        setPixmap (QPixmap(":/new/prefix1/tammy_down1.png").scaled(width,height));
        setHealth(100);
        posx= 260;
        posy = 20;
        speedx = 2* speed;
        speedy = 1*speed;
        timer_dead_tammy = new QTimer;


        connect(timer,SIGNAL(timeout()),this,SLOT(movetammy()));

    }
    if (tipo == 2){

        setPixmap (QPixmap(":/new/prefix1/enemy2_left.png").scaled(width,height));
        setHealth(200);
        posx= 100;
        posy =100;

        centerX = 100;
        centerY = 100;
        radius = 50;
        omega = 0.1;

        //Periodo de muestreo en segundos
        T = 0.01;
        n = 0;
        k = 2;
        timer_tickets = new QTimer;
        timer_tickets->start(1000*T);
        connect(timer,SIGNAL(timeout()),this,SLOT(movetickets()));

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

        if(speedy >= 0){
            setPixmap((QPixmap (":/new/prefix1/tammy_down1.png").scaled(width,height)));
        }
        if (speedy<0){
            setPixmap((QPixmap (":/new/prefix1/tammy_up1.png").scaled(width,height)));
        }

    }
}

void enemy::movetickets()
{


    // Obtener el tiempo actual en segundos


    // Calcular las nuevas coordenadas del objeto
   // posx = centerX + radius * cos(omega * k*n*T);
   // posy = centerY + radius * sin(omega * k*n*T);
    posx+=10;
    setPos(posx,posy);
    n++;

}






void enemy::deadtammy()
{
    scale= 4;

    if(count <1 *scale){
        setPixmap(QPixmap (":/new/prefix1/kill1.png").scaled(50,50));
        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap(QPixmap (":/new/prefix1/kill2.png").scaled(50,50));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap(QPixmap (":/new/prefix1/kill3.png").scaled(50,50));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap(QPixmap (":/new/prefix1/kill4.png").scaled(50,50));
        count++;
        if (count== 4*scale){

            emit delete_tammy(tipo);
        }
    }
}


float enemy::getx(){
    return posx;
}

void enemy::dead(){
    timer_dead_tammy->start(30);

    connect(timer_dead_tammy,SIGNAL(timeout()),this,SLOT(deadtammy()));


}



QRectF enemy::boundingRect() const
{
    return QRectF(-width/2, -height/2, 2*width, 2*height);

}



