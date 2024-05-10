#pragma once

#ifndef BELT_H
#define BELT_H

#include <string>

#include "object.h"
#include "cell.h"


class Belt : public Object {
private:
    char direction;

public:
    Belt(float x, float y, int h, int w, char ic, Color col, char dir)
        : Object(x, y, h, w, ic, col), direction(dir) {}

    char GetDirection();

    void Action(Cell** cells);
};

//34
#endif