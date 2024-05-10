#pragma once

#ifndef CELL_H
#define CELL_H

#include "object.h"

#include <vector>
#include <iostream>

class Cell {
private:
    std::vector<Object*> objects;
public:
    Cell();

    char getIcon();

    void setObject(Object* object);

    void removeObject();

    Object* getObjectUnderHero();

    Object* getObject();

    std::vector<Object*> getObjects();
};

#endif 