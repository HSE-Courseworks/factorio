#pragma once

#ifndef GROUND_H
#define GROUND_H

#include "object.h"

class Ground : public Object{
public:
    Ground(float x, float y, int h, int w, char ic, Color col) : Object(x, y, h, w, ic, col){};

    void draw();
};

#endif 