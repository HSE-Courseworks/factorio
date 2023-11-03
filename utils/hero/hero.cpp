#include "hero.h"

Hero::Hero(int X, int Y){
    icon = '@';
    x = X;
    y = Y;
}

void Hero::Move(char ch, std::optional<Cell**> cells, int h, int w){
    cells.value()[y][x].removeObject();
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
}

int Hero::getX(){
    return x;
}

int Hero::getY(){
    return y;
}