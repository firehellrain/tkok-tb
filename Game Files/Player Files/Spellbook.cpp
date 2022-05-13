#include "Spellbook.h"
#include <stdlib.h>

Spellbook::Spellbook(){
    heals = 3;
    fireballs = 3;
    icespells = false;
};

void Spellbook::refill_heals(){
    heals = 3;
}

int Spellbook::fireball(){
    
    int crit, spellFailure, dice;
    
    if (fireballs > 0){
        fireballs--;

        spellFailure = 1+rand()%15;
        if(spellFailure > 5){
            crit = 1+rand()%10;
            dice = 10+rand()%15;
            if (crit == 10) return dice*2;
            else return dice;
        }
    }
    
    return 0;
}

int Spellbook::icescorch(bool hasRing){

    int crit, spellFailure, dice;
    
    if (icespells){

        if(hasRing) spellFailure = 1+rand()%15;
        else spellFailure = 1+rand()%20;

        if(spellFailure > 5){
            crit = 1+rand()%10;
            dice = 5+rand()%10;
            if (crit == 10) return dice*2;
            else return dice;
        }
    }
    
    return 0;
}