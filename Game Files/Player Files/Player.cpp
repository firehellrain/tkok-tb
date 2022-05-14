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
    return (crit == 10) ? damage*2 : damage;
};

int Player::recieveDamage(int dmg){

    health -= dmg;

    if (health < 0) {
        health = 0;
        status = Dead;
    }
        
    return health;
};

int Player::spell(Spells s){
    switch (s){
        case Heal: return spells.heal(inv.hasItem(Medicine));
        case Fireball: return spells.fireball();
        case IceScorch: return spells.icescorch(inv.hasItem(Ring));
    }
}
