#pragma once

#ifndef IRON_H
#define IRON_H

#include "object.h"

class Iron : public Object{
public:
    Iron(int x, int y, int h, int w, char ic, Color col) : Object(x, y, h, w, ic, col){};
};

#endif