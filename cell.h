#include "object.h"
#include "ground.h"
#include <vector>
#ifndef _CELL_H
#define _CELL_H

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
