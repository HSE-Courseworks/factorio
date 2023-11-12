#pragma once

#ifndef INVENTORY_H
#define INVENTORY_H

#include "../item/item.h"

#include <iostream>
#include <vector>

class Inventory{
private:
    std::vector<Item*> items;
public:
    Inventory(int size);

    void showItems();
};

#endif