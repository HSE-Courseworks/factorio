#pragma once

#ifndef OBJECT_H
#define OBJECT_H

#include "../raylib/src/raylib.h"

class Object {
protected:
    char icon;
    Color color;
    int height;
    int width;

    // Rectangle object;
    Vector2 position;
public:
    Rectangle object;
    char getIcon() const;

    Object(float x, float y, int height, int width, char icon, Color color);

    Vector2 getPosition();

    Vector2 getSize();

    Color getColor();

    void draw();

    void setColor(Color col);
};

#endif 