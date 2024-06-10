#include "../include/hero.h"

void Hero::Draw() {
    DrawCircleV(position, 15, color);
}

void Hero::Move(const Vector2& direction) {
    position.x += direction.x * speed;
    position.y += direction.y * speed;
}

void Hero::Update() {
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

void Hero::setInventory(int size) {
    inventory = new Inventory(size);
}

Inventory* Hero::getInventory() {
    return inventory;
}

void Hero::Dig(Cell** cells) {
    int j = std::floor(this->position.x / 40);
    int i = std::floor(this->position.y / 40);

    if (cells[i][j].getIcon() == 'I') {
        IronItem* iron = new IronItem(28, 28, 'i', GRAY);
        int place = inventory->findItem(iron);
        if (place != -1) {
            inventory->IncreaseItemCount(place);
        } else {
            inventory->setItemInInventory(iron);
            place = inventory->findItem(iron);
            inventory->IncreaseItemCount(place);
        }
    } else if (cells[i][j].getIcon() == 'C') {
        CopperItem* copper = new CopperItem(28, 28, 'c', ORANGE);
        int place = inventory->findItem(copper);
        if (place != -1) {
            inventory->IncreaseItemCount(place);
        } else {
            inventory->setItemInInventory(copper);
            place = inventory->findItem(copper);
            inventory->IncreaseItemCount(place);
        }
    }
}

void Hero::Drop(Cell** cells) {
    int j = std::floor(this->position.x / 40);
    int i = std::floor(this->position.y / 40);

    Item* activeItem = inventory->getActiveItem();

    if (activeItem == nullptr) {
        return;
    }

    auto newItem = new Object(j * 40 + 10, i * 40 + 10, 20, 20,
    activeItem->getIcon(), activeItem->getColor());

    // activeItem->object.x = this->position.x;
    // activeItem->object.y = this->position.y;
    // activeItem->object.height = 20;
    // activeItem->object.width = 20;

    cells[i][j].setObject(newItem);

    inventory->decreaseItemCount();
}

void Hero::PlaceItems(Cell** cells, std::vector<Belt*>& belts) {
    int j = std::floor(this->position.x / 40);
    int i = std::floor(this->position.y / 40) - 1;
    if (IsKeyPressed(KEY_C)) {
        auto belt = new Belt(j * 40 + 5, i * 40 + 5, 30, 30, 'b', BLUE, 'u');
        cells[i][j].setObject(belt);
        belts.push_back(belt);
    }
}

void Hero::PickItem() {
    int j = std::floor(this->position.x / 40);
    int i = std::floor(this->position.y / 40);
}
