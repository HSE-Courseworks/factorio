#include "hero.h"
#include <optional>
#ifndef _MAP_H
#define _MAP_H

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
