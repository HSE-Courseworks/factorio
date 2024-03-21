#include "../include/hero.h"

void Hero::Draw() {
    DrawCircleV(position, 15, color);
}

void Hero::Move(const Vector2& direction) {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Hero::Update(){
    inventory->setActiveItem(GetKeyPressed());
    
    if (IsKeyDown(KEY_W)) {
        Move({0, -1});
    }
    if (IsKeyDown(KEY_S)) {
        Move({0, 1});
    }
    if (IsKeyDown(KEY_A)) {
        Move({-1, 0});
    }
    if (IsKeyDown(KEY_D)) {
        Move({1, 0});
    }
}

void Hero::setInventory(int size){
    inventory = new Inventory(size);
}

Inventory* Hero::getInventory(){
    return inventory;
}