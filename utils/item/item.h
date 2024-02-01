#pragma once

#ifndef FACTORIO_ITEM_H
#define FACTORIO_ITEM_H

#include "../object/object.h"

class Item : public _Object{
private:
    int count;
public:
    Item();

    int getItemsCount();

    void IncreaseCount(int value);
};

#endif //FACTORIO_ITEM_H
