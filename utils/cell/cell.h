#pragma once

#ifndef _CELL_H
#define _CELL_H

#include "../object/object.h"
#include "../ground/ground.h"
#include <vector>

class Cell {
    std::vector<_Object*> objects;

public:
    Cell();

    char getIcon();

    void setObject(_Object* object);

    void removeObject();

    _Object* getObject();
};

#endif //_CELL_H
