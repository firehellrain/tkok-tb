#ifndef SPELLBOOK_H
#define SPELLBOOK_H

enum Spells {
    Heal,
    Fireball,
    IceScorch,
};

class Spellbook{

    int heals;
    int firespells;
    bool icespells;

    public:
        Spellbook();
        void refill_heals();
        int heal(bool hasMedicine);
        int fireball();
        int icescorch(bool hasRing);
};

#endif