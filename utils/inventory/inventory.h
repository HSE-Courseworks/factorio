#pragma once

#ifndef INVENTORY_H
#define INVENTORY_H

#include "../item/item.h"

#include <iostream>
#include <vector>

class Inventory{
private:
    int activeItem = -1;

    std::vector<Item*> items;
public:
    Inventory(int size);

    void setActiveItem(char ch);

    void showItems();

    void setItemInInventory(Item* item);

    int findItem(Item* item);

    void IncreaseItemCount(int i, int value);
};

#endif