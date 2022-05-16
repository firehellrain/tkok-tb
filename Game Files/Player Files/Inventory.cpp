#include "Inventory.h"

Inventory::Inventory(){
    max_load = 5;
    load = 0;
    bag = {};
}

bool Inventory::addItem(Item i){
    
    if(load == 5) return false;
    
    bag[load] = i;
    load++;
    return true;
    
}

bool Inventory::hasItem(Item i){

    for (int j = 0; j<load; j++)
        if (bag[j] == i) return true;
    
    return false;
}