#include "CommonMonster.h"
#include <stdlib.h>
#include <algorithm>

CommonMonster::CommonMonster(int h, int d){

    health = h;
    damage = d;

};

int CommonMonster::attack(){

    return 1+rand()%damage;

};

int CommonMonster::recieveDamage(int dmg){

    health = std::max(health-dmg, 0);
    return health;

}

