#ifndef MAIN_CHARACTER_H
#define MAIN_CHARACTER_H
#include"character.h"


class main_character : public character
{
public:

    QPixmap player;
    main_character( int tipo1);
    void moveup();
    void moveleft();
    void moveright();
    void movedown();
    int tipo;

};

#endif // MAIN_CHARACTER_H
