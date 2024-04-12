#pragma once

#ifndef INVENTORY_H
#define INVENTORY_H

#include "../raylib/src/raylib.h"
#include "item.h"

#include <vector>

class Inventory{
private:
    int activeItem = -1;
    std::vector<Item*> items;
public:
    Inventory(int size);

    void setActiveItem(int ch);

    void showItems(Vector2 cameraOffset);

    void setItemInInventory(Item* item);

    int findItem(Item* item);

    void IncreaseItemCount(int i);
};

#endif