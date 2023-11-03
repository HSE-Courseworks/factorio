#pragma once

#ifndef _HERO_H
#define _HERO_H

#include "../object/object.h"
#include "../cell/cell.h"

#include <optional>

class Hero : public _Object{
private:
    int x;
    int y;
public:
    Hero(int X, int Y);

    void Move(char ch, std::optional<Cell**> cells, int h, int w);

    int getX();

    int getY();
};

#endif //_HERO_H
