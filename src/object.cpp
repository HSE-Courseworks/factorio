#include "../include/object.h"

char Object::getIcon() const {
    return icon;
}

Object::Object(float x, float y, int h, int w, char ic, Color col) {
    position = Vector2{x, y};
    height = h;
    width = w;
    icon = ic;
    color = col;

    this->object.height = h;
    this->object.width = w;
    this->object.x = x;
    this->object.y = y;
}

Vector2 Object::getPosition() {
    return this->position;
}

Vector2 Object::getSize() {
    return Vector2 {static_cast<float>(height), static_cast<float>(width)};
}

Color Object::getColor() {
    return this->color;
}

void Object::draw() {
    // DrawRectangleV(position, Vector2{float(height), float(width)}, color);
    DrawRectangleRec(object, color);
}

void Object::setColor(Color col) {
    this->color = col;
}
