#include "ammunition.h"

ammunition::ammunition(QString name,int x, int y ,QString direction)
{

    posx= x;
    posy = y;
    setPos(posx,posy);
    timer = new QTimer(this);
    A=9;
    Vo= 2;
    T = 0.01;
    timer->start(1000*T);
    //Periodo de muestreo en segundos
    n = 0;
    k = 2;//Factor de velocidad
    dir1=direction;
    setShoot();
    connect(timer,SIGNAL(timeout()),this,SLOT(moveup()));


}
void ammunition::setShoot(){
    if (dir1 == "up"){
        posx+=7;
        posy-=15;

    }
    else if (dir1 == "left"){
        posx -=5;
        posy+=15;
    }
    else if(dir1 == "down"){
        posy +=15;
        posx+=3;
    }
    else if(dir1 == "right"){
        posx +=8;
        posy += 15;

    }
}
void ammunition::moveup(){
    QTransform rotation;




    if (dir1 == "up"){

        posy =posy- Vo-0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);


        setPixmap (QPixmap(":/new/prefix1/49.png").scaled(40,40));
        setPixmap (QPixmap(":/new/prefix1/50.png").scaled(40,40));
        n++;
    }
    else if (dir1 == "left"){
        posx =posx- Vo-0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(-90);
        setPixmap ((QPixmap(":/new/prefix1/49.png").scaled(40,40)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/50.png").scaled(40,40)).transformed(rotation));
        n++;
    }
    else if(dir1 == "down"){

        posy =posy+ Vo+0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(180);
        setPixmap ((QPixmap(":/new/prefix1/49.png").scaled(40,40)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/50.png").scaled(40,40)).transformed(rotation));
        n++;
    }
    else if(dir1 == "right"){

        posx =posx+ Vo+0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(90);
        setPixmap ((QPixmap(":/new/prefix1/49.png").scaled(40,40)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/50.png").scaled(40,40)).transformed(rotation));
        n++;
    }
}

