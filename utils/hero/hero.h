#pragma once

#ifndef _HERO_H
#define _HERO_H

#include "../object/object.h"
#include "../cell/cell.h"
#include "../inventory/inventory.h"

#include <optional>
#include <iostream>

using namespace std;

class Hero : public _Object{
private:
    int x;
    int y;

    Inventory* inventory;
public:
    Hero(int X, int Y, int inventorySize);

    void Move(char ch, std::optional<Cell**> cells, int h, int w);

    Inventory* getInventory();

    int getX();

    int getY();
};

#endif //_HERO_H
