#include "../include/belt.h"

char Belt::GetDirection() {
    return direction;
}

void Belt::Action(Cell** cells) {
    int j = std::floor(position.x/ 40);
    int i = std::floor(position.y / 40);
    Object* obj = cells[i][j].getObject();
    if (obj->getIcon() == 'b' || obj->getIcon() == '#') {
        return;
    }
    if (direction == 'u') {
        cells[i - 1][j].setObject(obj);
        obj->object.y = (i - 1) * 40 + 10;
        cells[i][j].removeObject();
    } else if (direction == 'd') {
        cells[i +1][j].setObject(obj);
        cells[i][j].removeObject();
    } else if (direction == 'l') {
        cells[i][j - 1].setObject(obj);
        cells[i][j].removeObject();
    } else if (direction == 'r') {
        cells[i][j + 1].setObject(obj);
        cells[i][j].removeObject();
    }
}
