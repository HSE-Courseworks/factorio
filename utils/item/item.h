#pragma once

#ifndef FACTORIO_ITEM_H
#define FACTORIO_ITEM_H

#include "../object/object.h"

class Item : public _Object{
private:
    int count;
public:
    Item(int cnt);

    int getItemsCount();
};

#endif //FACTORIO_ITEM_H
