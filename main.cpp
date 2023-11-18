#include <iostream>
#include "windows.h"
#include <optional>
#include <ctime>
#include <random>
#include <conio.h>
#include "utils/cell/cell.cpp"
#include "utils/ground/ground.cpp"
#include "utils/hero/hero.cpp"
#include "utils/map/map.cpp"
#include "utils/object/object.cpp"
#include "utils/item/item.cpp"
#include "utils/inventory/inventory.cpp"
#include "utils/opt/opt.cpp"

using namespace std;

int main(){
    srand(time(nullptr));
    int h = 20, w = 20;
    Hero* hero = new Hero(h / 2, w/ 2, 5);
    Map map(h, w, hero);
    map.generate();
    map.render();
    while(true){

        if(_kbhit()){

            char ch = _getch();
            if(ch == 'x'){
                break;
            }
            if(std::isdigit(ch)){
                hero->getInventory()->setActiveItem(ch - '0');

            }
            hero->Move(ch, map.cells, h, w);
        }


    }
    return 0;
}