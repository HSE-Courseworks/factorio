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


// Generate
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


// GenerateOres
void Map::generateOres(){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            auto copper = new Copper();
            cells.value()[i][j].setObject(copper);
        }
        
    }
    
}


// Render
void Map::render() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if(cells.value()[i][j].getIcon() == '0'){
                std::cout << "\033[1;33m" << cells.value()[i][j].getIcon() << "\033[0m";
            }
            else {
                std::cout << cells.value()[i][j].getIcon();
            }
        }
        std::cout << std::endl;
    }
    hero->getInventory()->showItems();
}