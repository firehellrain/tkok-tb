#ifndef INVENTORY_H
#define INVENTORY_H
#include <array>

typedef std::array<Item, 5> Backpack;

enum Item {
    Shield,
    Sword,
    Ring,
    Food,
    Medicine,
    Box,
    Key
};

class Inventory {
    
    int max_load;
    int load;
    Backpack bag;
    
    public:
        Inventory();
        bool addItem(Item i);
        bool hasItem(Item i);

};

#endif