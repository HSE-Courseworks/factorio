#include "map.h"
#include <iostream>

Map::Map(int h, int w, Hero* he) {
    height = h;
    width = w;
    hero = he;

    // Выделение памяти для массива ячеек
    cells = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        cells.value()[i] = new Cell[width];
    }
}

Map::~Map() {
    // Освобождение памяти массива ячеек
    for (int i = 0; i < height; ++i) {
        delete[] cells.value()[i];
    }
    delete[] cells.value();
}


void Map::generate() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(cells.value()[i][j].getObject() == nullptr){
                auto ground = new Ground();
                cells.value()[i][j].setObject(ground);
            }
        }
    }
    cells.value()[hero->getY()][hero->getX()].setObject(hero);
}


void Map::render() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << cells.value()[i][j].getIcon();
        }
        std::cout << std::endl;
    }
    hero->getInventory()->showItems();
}