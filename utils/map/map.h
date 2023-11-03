#pragma once

#ifndef _MAP_H
#define _MAP_H

#include "../hero/hero.h"

#include <optional>

class Map {
    int height, width;
    Hero* hero;

public:
    std::optional<Cell**> cells;
    Map(int h, int w, Hero* he);
    ~Map();
    void generate();
    void render();
};

#endif //_MAP_H
