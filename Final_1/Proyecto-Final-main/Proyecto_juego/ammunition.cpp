#include "ammunition.h"

ammunition::ammunition(QString name,int x, int y ,QString direction)
{

    posx= x;
    posy = y;
    setPos(posx,posy);
    height = 40;
    width = 40;

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

QRectF ammunition::boundingRect() const
{
    return QRectF(-width/2, -height/2, 2*width, 2*height);
}

void ammunition::moveup(){
    QTransform rotation;




    if (dir1 == "up"){

        posy =posy- Vo-0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);


        setPixmap (QPixmap(":/new/prefix1/49.png").scaled(width,height));
        setPixmap (QPixmap(":/new/prefix1/50.png").scaled(width,height));
        n++;
    }
    else if (dir1 == "left"){
        posx =posx- Vo-0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(-90);
        setPixmap ((QPixmap(":/new/prefix1/49.png").scaled(width,height)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/50.png").scaled(width,height)).transformed(rotation));
        n++;
    }
    else if(dir1 == "down"){

        posy =posy+ Vo+0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(180);
        setPixmap ((QPixmap(":/new/prefix1/49.png").scaled(width,height)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/50.png").scaled(width,height)).transformed(rotation));
        n++;
    }
    else if(dir1 == "right"){

        posx =posx+ Vo+0.5*(A)*(n*n*k*k*T*T);
        setPos(posx,posy);

        rotation.rotate(90);
        setPixmap ((QPixmap(":/new/prefix1/49.png").scaled(width,height)).transformed(rotation));
        setPixmap ((QPixmap(":/new/prefix1/50.png").scaled(width,height)).transformed(rotation));
        n++;
    }
}

