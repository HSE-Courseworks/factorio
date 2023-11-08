#include "inventory.h"

Inventory::Inventory(int size){
    for (int i = 0; i < size; i++)
    {
        //items[i] = new Item();
        auto item = new Item();
        items.push_back(item);
    }
    
}

void Inventory::showItems(){
    for (int i = 0; i < items.size(); i++)
    {
        std::cout << items[i]->getIcon() << " ";
    }
    
}