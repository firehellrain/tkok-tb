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

    heals--;

    int dado = 0;
    int critico = 1+rand()%10;

    dado = hasMedicine ? 10+rand()%15 : 5+rand()%10;

    return (critico==10) ? dado*2 : dado;
}

int Spellbook::fireball(){
    
    int crit, spellFailure, dice;
    
    if (firespells > 0){
        firespells--;

        spellFailure = 1+rand()%15;

        if(spellFailure > 5){
            crit = 1+rand()%10;
            dice = 10+rand()%15;
            return (crit == 10) ? dice*2 : dice;
        }
    }
    
    return 0;
}

int Spellbook::icescorch(bool hasRing){

    int crit, spellFailure, dice;
    
    if (icespells){

        spellFailure = hasRing ? 1+rand()%15 : 1+rand()%20;

        if(spellFailure > 5){
            crit = 1+rand()%10;
            dice = 5+rand()%10;
            return (crit == 10) ? dice*2 : dice;
        }
    }
    
    return 0;
}