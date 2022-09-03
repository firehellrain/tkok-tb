#ifndef COMMONMONSTER_H
#define COMMONMONSTER_H

class CommonMonster {

    int health;
    int damage;

    public:
        CommonMonster(int health, int damage);
        int attack();
        int recieveDamage(int dmg);

};

#endif