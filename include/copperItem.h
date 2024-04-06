#pragma once

#ifndef COPPERITEM_H
#define COPPERITEM_H

#include "object.h"
#include "item.h"

class CopperItem : public Item{
public:
    CopperItem(int h, int w, char ic, Color col) : Item(h, w, ic, col){};
};

#endif