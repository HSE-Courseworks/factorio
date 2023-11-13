#include "opt.h"

void SetCurPos(int y, int x){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void ShowIcon(int y, int x, std::optional<Cell**> cells){
    SetCurPos(y, x);
    std::cout << cells.value()[y][x].getIcon();
}