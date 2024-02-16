#include "hero.h"

Hero::Hero(int X, int Y, int inventorySize){
    icon = '@';
    x = X;
    y = Y;

    inventory = new Inventory(inventorySize);
}

void Hero::Move(char ch, std::optional<Cell**> cells, int h, int w){
    int exX = x, exY = y;
    switch (ch) {
        case 'a':
            if(x == 0){
                return;
            }
            --x;
            break;
        case 'd':
            if(x == w - 1){
                return;
            }
            ++x;
            break;
        case 'w':
            if(y == 0){
                return;
            }
            --y;
            break;
        case 's':
            if(y == h - 1){
                return;
            }
            ++y;
            break;
    }
    cells.value()[exY][exX].removeObject();
    cells.value()[getY()][getX()].setObject(this);
    ShowIcon(exY, exX, cells);
    ShowIcon(getY(), getX(), cells);
}

void Hero::Dig(std::optional<Cell**> cells){
    if(cells.value()[y][x].getObjectUnderHero() == '0'){\
        CopperItem* copper = new CopperItem();
        int place = inventory->findItem(copper);
        if(place != -1){
            inventory->IncreaseItemCount(place, 1);
        }else {
            inventory->setItemInInventory(copper);
            int place = inventory->findItem(copper);
            inventory->IncreaseItemCount(place, 1);
            
        }
    }
    else if(cells.value()[y][x].getObjectUnderHero() == '9'){\
        IronItem* iron = new IronItem();
        int place = inventory->findItem(iron);
        if(place != -1){
            inventory->IncreaseItemCount(place, 1);
        }else {
            inventory->setItemInInventory(iron);
            int place = inventory->findItem(iron);
            inventory->IncreaseItemCount(place, 1);
        }
    }
}

int Hero::getX(){
    return this->x;
}

int Hero::getY(){
    return this->y;
}

Inventory* Hero::getInventory(){
    return inventory;
}