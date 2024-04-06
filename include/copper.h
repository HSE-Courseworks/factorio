#pragma once

#ifndef COPPER_H
#define COPPER_H

#include "object.h"

class Copper : public Object{
public:
    Copper(int x, int y, int h, int w, char ic, Color col) : Object(x, y, h, w, ic, col){};
};

#endif