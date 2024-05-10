#pragma once

#ifndef ITEM_H
#define ITEM_H

#include "object.h"

class Item : public Object{
private:
    int count = 0;
public:
    Item(int h, int w, char ic, Color col) : Object(0, 0, h, w, ic, col){};

    int GetCount();

    void decreaseCount();

    void IncreaseCount();
};

#endif