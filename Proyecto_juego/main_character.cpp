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

void main_character::moveleft()
{

    if(count <1 *scale){
        setPixmap(QPixmap (":/new/prefix1/rick_left1.png").scaled(50,50));
        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap(QPixmap (":/new/prefix1/rick_left2.png").scaled(50,50));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap(QPixmap (":/new/prefix1/rick_left3.png").scaled(50,50));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap(QPixmap (":/new/prefix1/rick_left4.png").scaled(50,50));
        count++;
        if (count == 4*scale){
            count =0;
        }
    }
    posx-=speed;
    setPos(posx, posy);
}
void main_character::moveright()
{
    QTransform reflection;
    reflection.scale(-1, 1);
    if(count <1 *scale){

        setPixmap((QPixmap (":/new/prefix1/rick_left1.png").scaled(50,50).transformed(reflection)));

        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap((QPixmap (":/new/prefix1/rick_left2.png").scaled(50,50).transformed(reflection)));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap((QPixmap (":/new/prefix1/rick_left3.png").scaled(50,50).transformed(reflection)));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap((QPixmap (":/new/prefix1/rick_left4.png").scaled(50,50).transformed(reflection)));
        count++;
        if (count == 4*scale){
            count =0;
        }
    }
    posx+=speed;
    setPos(posx, posy);
}
void main_character::movedown()
{

    if(count <1 *scale){
        setPixmap(QPixmap (":/new/prefix1/rick1.png").scaled(50,50));
        count++;
    }
    else if ((count>=1*scale) && (count< scale*2)){
        setPixmap(QPixmap (":/new/prefix1/rick2.png").scaled(50,50));
        count++;
    }
    else if ((count>=2*scale) && (count< scale*3)){
        setPixmap(QPixmap (":/new/prefix1/rick1.png").scaled(50,50));
        count++;
    }
    else if((count>=3*scale) && (count< scale*4)){
        setPixmap(QPixmap (":/new/prefix1/rick3.png").scaled(50,50));
        count++;
        if (count == 4*scale){
            count =0;
        }
    }
    posy+=speed;
    setPos(posx, posy);
}

