#include "Spellbook.h"
#include <stdlib.h>

Spellbook::Spellbook(){
    heals = 3;
    firespells = 3;
    icespells = false;
};

void Spellbook::refill_heals(){
    heals = 3;
}

int Spellbook::heal(bool hasMedicine){

    int dice, crit;

    if (heals == 0) return -1;
    heals--;

    crit = 1+rand()%10;
    dice = hasMedicine ? 10+rand()%15 : 5+rand()%10;

    return (crit==10) ? dice*2 : dice;
}

int Spellbook::fireball(){
    
    int dice, crit, spellFailure;
    
    if (firespells == 0) return -1;
    firespells--;

    spellFailure = 1+rand()%15;
    if(spellFailure < 5) return 0;
        
    crit = 1+rand()%10;
    dice = 10+rand()%15;
    return (crit == 10) ? dice*2 : dice;
}

int Spellbook::icescorch(bool hasRing){

    int dice, crit, spellFailure;
    
    if (!icespells) return -1;

    spellFailure = hasRing ? 1+rand()%15 : 1+rand()%20;
    if(spellFailure < 5) return 0;
    
    crit = 1+rand()%10;
    dice = 5+rand()%10;
    return (crit == 10) ? dice*2 : dice;
}