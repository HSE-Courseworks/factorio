#include <iostream>
#include <optional>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

class _Object {
protected:
    char icon;

public:
    char getIcon() {
        return icon;
    }
};

class Ground : public _Object {
public:
    Ground() {
        icon = '#';
    }
};

class Hero : public _Object{
    int x, y;
public:
    Hero(int height, int width){
        icon = '@';
        x = width / 2;
        y = height / 2;
    }

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void Move(){
        char ch = getch();

        switch (ch) {
            case 'w':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'a':
                x--;
                break;
            case 'd':
                x++;
        }
    }
};


class Cell {
    _Object* obj;

public:
    Cell() {
        obj = nullptr;
    }

    char getIcon() {
        return obj->getIcon();
    }

    void setObject(_Object* object) {
        obj = object;
    }

    _Object* getObject(){
        return obj;
    }
};


class Map {
    int height, width;
    optional<Cell**> cells;
    Hero* hero;

public:
    Map(int h, int w) {
        height = h;
        width = w;



        // Выделение памяти для массива ячеек
        cells = new Cell*[height];
        for (int i = 0; i < height; ++i) {
            cells.value()[i] = new Cell[width];
        }
    }

    ~Map() {
        // Освобождение памяти массива ячеек
        for (int i = 0; i < height; ++i) {
            delete[] cells.value()[i];
        }
        delete[] cells.value();
    }

    void setHero(Hero* hero){
        this -> hero = hero;
    }

    void generate() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(cells.value()[i][j].getObject() == nullptr){
                    auto ground = new Ground();
                    cells.value()[i][j].setObject(ground);
                }
            }
        }
    }

    void render() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(i == hero->getY() && j == hero->getX()){
                    cout << hero->getIcon();
                } else{
                    cout << cells.value()[i][j].getIcon();
                }

            }
            cout << endl;
        }
    }
};


int main() {
    int h = 40, w = 40;
    srand(time(nullptr));
    auto hero = new Hero(h, w);
    Map map(h, w);
    map.setHero(hero);
    map.generate();
    while(true){
        map.render();
        hero -> Move();
        system("cls");
    }
    return 0;
}

