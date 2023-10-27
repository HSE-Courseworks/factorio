#include <iostream>
#include <optional>
#include <ctime>
#include <random>
#include <conio.h>
#include "cell.cpp"
#include "ground.cpp"
#include "hero.cpp"
#include "map.cpp"
#include "object.cpp"

using namespace std;


int main(){
    srand(time(nullptr));
    int h = 10, w = 10;
    Hero* hero = new Hero(h / 2, w/ 2);
    Map map(h, w, hero);
    map.generate();
    while(true){

        if(_kbhit()){

            char ch = _getch();
            if(ch == 'x'){
                break;
            }
            hero->Move(ch, map.cells, h, w);
            system("cls");
            map.render();
        }


    }
    return 0;
}