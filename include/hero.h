#pragma once

#ifndef HERO_H
#define HERO_H

#include "object.h"
#include "inventory.h"
#include "cell.h"
#include "ironItem.h"
#include "copperItem.h"

#include "../raylib/src/raylib.h"

class Hero : public Object{
public:
    Hero(float x, float y, int h, int w, char ic, Color col) : Object(x, y, h, w, ic, col){};

    void Draw();

    void Move(const Vector2& direction);

    void Update();

    void setInventory(int size);

    void Dig(Cell** cells);

    Inventory* getInventory();
private:
    Inventory* inventory;

    float speed = 3;
};


#endif //HERO_H
