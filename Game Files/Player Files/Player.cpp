#include "Player.h"

Player::Player(){
    health = 50;
    status = Healthy;
    spells = Spellbook();
    inv = Inventory();
}

int Player::attack(){

    int dice, crit, damage;

    dice = inv.hasItem(Sword) ? 15 : 5;
    damage = 1+rand()%dice;
    crit = 1+rand()%10;
    
    return (crit == 10) ? damage*2 : damage;
};

int Player::recieveDamage(int dmg){

    health = std::max(health-dmg, 0);

    if (health == 0) status = Dead;
        
    return health;
};

int Player::spell(Spells s){
    switch (s){
        case Heal: return spells.heal(inv.hasItem(Medicine));
        case Fireball: return spells.fireball();
        case IceScorch: return spells.icescorch(inv.hasItem(Ring));
    }
}
