#include "opt.h"
#include "../ores/copper.h"

void SetCurPos(int y, int x){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void ShowIcon(int y, int x, std::optional<Cell**> cells){
    SetCurPos(y, x);
    if(cells.value()[y][x].getIcon() == '0'){
        std::cout << "\033[1;33m" << cells.value()[y][x].getIcon() << "\033[0m";
    }
    else{
        std::cout << cells.value()[y][x].getIcon();
    }
    
}