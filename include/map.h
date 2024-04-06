#pragma once

#ifndef MAP_H
#define MAP_H

#include "cell.h"
#include "hero.h"
#include "iron.h"
#include "copper.h"

#include <vector>

class Map{
private:
    int height, width;
    Cell** cells;

public:
    Map(int h, int w);

    ~Map();

    int getHeight();

    int getWidth();

    void generate();

    void draw();

    Cell** getCells();

    void generateOres();
};

#endif