#ifndef COMMONMONSTER_H
#define COMMONMONSTER_H

class CommonMonster {

    char name;
    int health;
    int damage;

    public:
        CommonMonster(char n, int health, int damage);
        void getName();
        int attack();
        int recieveDamage(int dmg);

};

#endif