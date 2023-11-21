#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QTransform>



class character: public QObject, public QGraphicsPixmapItem
{
public:
    character();


    void setHealth(int cant);
    int getHealt();
    int getSpeed();
    void setSpeed(int cant);

    int health;
    int speed;
    int posx = 0 ,posy = 0;
    int count= 0;
    int scale= 5;

    int height;
    int width;


};

#endif // CHARACTER_H
