#include "CommonMonster.h"
#include "ConsoleColor.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>

CommonMonster::CommonMonster(char n, int h, int d){

    name = n;
    health = h;
    damage = d;

};

void CommonMonster::getName(){
    switch(name){
        case 'A': std::cout<<yellow<<"Army of Bloodthirsty Bats"<<white; break;
        case 'B': std::cout<<yellow<<"Guardian of the Vampires"<<white; break;
        case 'C': std::cout<<yellow<<"Hecuba, Mistress of the Vampires"<<white; break;
        case 'D': std::cout<<red<<"Drakar, Lord of the Vampires"<<white; break;
        case 'E': std::cout<<blue<<"Undead Shapeshifter"<<white; break;
        default: std::cout<<yellow<<"Commoner"<<white; break;
    }
}

int CommonMonster::attack(){

    return 1+rand()%damage;
    
};

int CommonMonster::recieveDamage(int dmg){

    health = (health-dmg) > 0 ? health-dmg : 0;
    return health;

}

