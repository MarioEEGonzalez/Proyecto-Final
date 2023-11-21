#ifndef AMMUNITION_H
#define AMMUNITION_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QEventLoop>
#include "enemy.h"

class ammunition: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ammunition( QString name,int posx,int posy,QString dir);
    void setShoot();
    int damage, posx,posy ;
    QTimer *timer;
    QPixmap *balita;
    QString dir1;

    float Vo,A,T,k;
    unsigned int n;
    void detect_colision();

    int height;
    int width;

    QRectF boundingRect() const;


public slots:
    void moveup();



};

#endif // AMMUNITION_H
