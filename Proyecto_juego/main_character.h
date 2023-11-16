#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H
#include"character.h"

class main_character : public character
{
public:

    QPixmap player;
    main_character(QString name);
    void moveup();

};

#endif // MAIN_CHARACTER_H
