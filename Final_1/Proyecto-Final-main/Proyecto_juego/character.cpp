#include "character.h"

character::character()
{

}

void character::setHealth(int cant){
    health = cant;
}

int character::getHealt(){
    return health;
}
int character::getSpeed(){
    return speed;
}
void character::setSpeed(int cant){
    speed = cant;
}

