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

void Hero::Dig(Cell** cells){
    int j = std::floor(this->position.x / 40);
    int i = std::floor(this->position.y / 40);

    if(cells[i][j].getIcon() == 'i'){
        IronItem* iron = new IronItem(28, 28, 'i', GRAY);
        int place = inventory->findItem(iron);
        if(place != -1){
            inventory->IncreaseItemCount(place);
        } else {
            inventory->setItemInInventory(iron);
        }
    } else if (cells[i][j].getIcon() == 'c'){
        CopperItem* copper = new CopperItem(28, 28, 'c', ORANGE);
        int place = inventory->findItem(copper);
        if(place != -1){
            inventory->IncreaseItemCount(place);
        } else {
            inventory->setItemInInventory(copper);
        }
    }
}