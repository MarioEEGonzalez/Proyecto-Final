#include "main_character.h"


main_character::main_character(QString name)
{

    setPixmap (QPixmap(name).scaled(50,50));
    posx= 250;
    posy = 250;
    setPos(posx,posy);
    speed = 2;

}



void main_character::moveup()
{

    if(count <1 *scale){
        setPixmap(QPixmap (":/new/prefix1/rick_up1.png").scaled(50,50));
        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap(QPixmap (":/new/prefix1/rick_up2.png").scaled(50,50));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap(QPixmap (":/new/prefix1/rick_up3.png").scaled(50,50));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap(QPixmap (":/new/prefix1/rick_up1.png").scaled(50,50));
        count++;
        if (count == 4*scale){
            count =0;
        }
    }
    posy-=speed;
    setPos(posx, posy);
}


