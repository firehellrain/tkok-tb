#ifndef GAMESTATUS_h
#define GAMESTATUS_H
#include <array>
#include <stdlib.h>

const int numEvents = 8;

typedef std::array<Events, numEvents> PlayableEvents;

enum Events{
    null,
    FrozenMountain,
    HauntedHouse,
    WolvesAttackOldMan,
    DungeonChest,
    AbandonedDog,
    GrandmaHouse,
    WanderingMerchant,
    NymphMedic,
};

class GameStatus {

    int round;
    Events event;
    PlayableEvents playEv;
    int playEvSize;
    bool endGame;

    public:
        GameStatus();
        Events chooseEvent();
    private:
        void realloc_events(int pos);
};

#endif