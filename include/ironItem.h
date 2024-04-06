#pragma once

#ifndef IRONITEM_H
#define IRONITEM_H

#include "object.h"
#include "item.h"

class IronItem : public Item{
public:
    IronItem(int h, int w, char ic, Color col) : Item(h, w, ic, col){};
};

#endif