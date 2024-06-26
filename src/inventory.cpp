#include "../include/inventory.h"
#include <string>
#include <sstream>

Inventory::Inventory(int size) {
    items = std::vector<Item*>(size);
    for (int i = 0; i < size; i++) {
        items[i] = new Item(15, 15, 't', BLACK);
    }
}

void Inventory::showItems(Vector2 target) {
    int count = items.size() * 45;
    int x = target.x - count / 2;
    int y = target.y + 380;

    for (int i = 0; i < items.size(); i++) {
        std::stringstream text;

        if (items[i]->getIcon() == 'i') {
            if (i == activeItem) {
                DrawRectangle(x, y, 24, 24, WHITE);
                text << ':' << items[i]->GetCount() << ' ';
                DrawText(text.str().c_str(), x + 28, y, 28, WHITE);
            } else {
                DrawRectangle(x, y, 24, 24, GRAY);
                text << ':' << items[i]->GetCount() << ' ';
                DrawText(text.str().c_str(), x + 28, y, 28, GRAY);
            }
        } else if (items[i]->getIcon() == 'c') {
            if (i == activeItem) {
                DrawRectangle(x, y, 24, 24, WHITE);
                text << ':' << items[i]->GetCount() << ' ';
                DrawText(text.str().c_str(), x + 28, y, 28, WHITE);
            } else {
                DrawRectangle(x, y, 24, 24, ORANGE);
                text << ':' << items[i]->GetCount() << ' ';
                DrawText(text.str().c_str(), x + 28, y, 28, ORANGE);
            }
        } else {
            if (i == activeItem) {
                text << items[i]->getIcon() << ':'
                << items[i]->GetCount() << ' ';
                DrawText(text.str().c_str(), x, y, 28, WHITE);
            } else {
                text << items[i]->getIcon() << ':'
                << items[i]->GetCount() << ' ';
                DrawText(text.str().c_str(), x, y, 28, BLACK);
            }
        }
        x += 55;
    }
}

void Inventory::setActiveItem(int ch) {
    if (ch < 48 || ch > 53) {
        return;
    }
    activeItem = ch - 49;
}

void Inventory::setItemInInventory(Item* item) {
    int inventorySize = items.size();
    for (int i = 0; i < inventorySize; i++) {
        if (items[i]->GetCount() == 0
        && items[i]->getIcon() != item->getIcon()) {
            items[i] = item;
            return;
        }
    }
}

int Inventory::findItem(Item* item) {
    int itemCount = items.size();
    for (int i = 0; i < itemCount; i++) {
        if (items[i]->getIcon() == item->getIcon()) {
            return i;
        }
    }
    return -1;
}

void Inventory::IncreaseItemCount(int i) {
    items[i]->IncreaseCount();
}

Item* Inventory::getActiveItem() {
    if (items[activeItem]->getIcon() == 't'
    || items[activeItem]->GetCount() == 0) {
        return nullptr;
    }
    return items[activeItem];
}

void Inventory::decreaseItemCount() {
    items[activeItem]->decreaseCount();
    if (items[activeItem]->GetCount() == 0) {
        items[activeItem] = new Item(15, 15, 't', BLACK);
    }
}
