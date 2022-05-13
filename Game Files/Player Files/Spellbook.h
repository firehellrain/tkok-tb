#ifndef SPELLBOOK_H
#define SPELLBOOK_H

enum Spells {
    Fireball,
    IceScorch,
};

class Spellbook{

    int heals;
    int fireballs;
    bool icespells;

    public:
        Spellbook();
        void refill_heals();
        int fireball();
        int icescorch(bool hasRing);
};

#endif