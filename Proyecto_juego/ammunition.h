#ifndef AMMUNITION_H
#define AMMUNITION_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QTimer>
#include <QKeyEvent>
#include <QEventLoop>

class ammunition: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ammunition(QString name, int posx,int posy,QString dir);
    void setShoot();
    int damage, posx= 0,posy= 0;
    QTimer *timer;
    QPixmap *balita;
    QString dir1;
public slots:
    void moveup();



};

#endif // AMMUNITION_H
