#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>

int aG(Player& p){                  /// Player Damage Dice

    int critico = 1+rand()%10;
    int dado;

    if(p.sword == true) dado = 1+rand()%15;
    else dado = 1+rand()%5;

    if(critico==10) dado *= 2;

    return dado;
}

int fG(Player& p){                  /// Player Fireball Damage Dice

    p.fireballs--;

    int critico = 1+rand()%10, sFailure;
    int dado = 0;

    if(!p.ring)  sFailure = 1+rand()%10;
    else sFailure = 1+rand()%15;

    if (sFailure>5) dado = 10+rand()%15;
    if (critico==10) dado *= 2;

    return dado;
}

int iG(Player& p){                  /// Player Ice Scorch Damage Dice

    int critico = 1+rand()%10, sFailure;
    int dado = 0;

    if(!p.ring) sFailure = 1+rand()%15;
    else sFailure = 1+rand()%20;

    if (sFailure>5) dado = 5+rand()%10;
    if (critico==10) dado *= 2;

    return dado;
}

int mG(Monster& m, Player& p){      /// Monster Damage Dice

    int critico = 1+rand()%10;
    int hechizo = 1+rand()%20;
    int dado = 1+rand()%5;
    int escudo = 1+rand()%20;

    if(m.name=='D'){
        if(hechizo>15){
            if(escudo<hechizo || !p.shield){
                m.fireball = true;
                dado += rand()%15;
                if(critico==10) dado *= 2;
            } else {
                m.fireball = true;
                dado = 0;
            }
        } else {
            dado = 1+rand()%10;
            if(critico==10) dado *= 2;
            m.fireball = false;
        }
    }

    return dado;
}

int hG(Player& p){                  /// Player Heal Dice

    p.heals--;

    int dado = 0;
    int critico = 1+rand()%10;

    if(p.healboost) dado = 5+rand()%10;
    else dado = 10+rand()%15;

    if(critico==10) dado *= 2;

    return dado;
}

int dG(Player& p){                  /// Dog Damage Dice

    int critico = 1+rand()%20;
    int dado = 1+rand()%6;

    if(critico==20) dado *= 2;

    return dado;
}
