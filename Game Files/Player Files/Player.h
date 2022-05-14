#ifndef PLAYER_H
#define PLAYER_H

#include "Spellbook.h"
#include "Inventory.h"

enum Status {
    Healthy,
    Cursed,
    Vampiric,
    Dead
};

class Player {
   
    int health;
    Status status;
    Spellbook spells; 
    Inventory inv;

    public:
        Player();
        int attack();
        int spell(Spells spell);
        int recieveDamage(int dmg);
};

#endif