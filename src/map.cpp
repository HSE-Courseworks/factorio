#include "../include/map.h"
#include "../include/ground.h"

Map::Map(int h, int w) {
    height = h;
    width = w;

    // Выделение памяти для массива ячеек
    cells = new Cell*[height];
    for (int i = 0; i < height; ++i) {
        cells[i] = new Cell[width];
    }
}

Map::~Map() {
    // Освобождение памяти массива ячеек
    for (int i = 0; i < height; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Map::generate() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Ground* obj = new Ground( (j * 40), (i * 40), 39, 39, '#', BROWN);
            cells[i][j].setObject(obj);
        }
    }
}

void Map::draw() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            auto objects = cells[i][j].getObjects();
            for (int k = 0; k < objects.size(); k++) {
                objects[k]->draw();
            }
        }
    }
}

Cell** Map::getCells() {
    return this->cells;
}

int Map::getHeight() {
    return this->height;
}

int Map::getWidth() {
    return this->width;
}

void Map::generateOres() {
    for (int i = 10; i < 20; i++) {
        for (int j = 10; j < 20; j++) {
            Iron* iron = new Iron((j * 40), (i * 40), 39, 39, 'I', GRAY);
            cells[i][j].setObject(iron);
        }
    }

    for (int i = 20; i < 30; i++) {
        for (int j = 20; j < 30; j++) {
            Copper* iron = new Copper((j * 40), (i * 40), 39, 39, 'C', ORANGE);
            cells[i][j].setObject(iron);
        }
    }
}
