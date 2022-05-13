#include "Player.h"

Player::Player(){
    health = 50;
    status = Healthy;
    spells = Spellbook();
    inv = Inventory();
}

int Player::attack(){

    int damage;
    int crit;
    int dice = 5;

    if (inv.hasItem(Sword)) dice = 15;

    damage = 1+rand()%dice;
    crit = 1+rand()%10;

    if(crit == 10)
        return damage*2;
    else return damage;

};

int Player::recieveDamage(int dmg){
    health -= dmg;
    return health;
};

int Player::heal(){

}
