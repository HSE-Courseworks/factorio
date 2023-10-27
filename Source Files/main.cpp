#include <iostream>
#include <optional>
#include <ctime>
#include <random>
#include <vector>
#include <conio.h>

using namespace std;

class _Object {
protected:
    char icon;

public:
    char getIcon() const{
        return icon;
    }
};

class Ground : public _Object {
public:
    Ground() {
        icon = '#';
    }
};



class Cell {
    vector<_Object*> objects;

public:
    Cell() {
        auto ground = new Ground();
        objects.push_back(ground);
    }

    char getIcon() {
        return objects[objects.size() - 1] -> getIcon();
    }

    void setObject(_Object* object) {
        objects.push_back(object);
    }

    void removeObject(){
        objects.pop_back();
    }

    _Object* getObject(){
        return objects[objects.size() - 1];
    }
};

class Hero : public _Object{
private:
    int x;
    int y;
public:
    Hero(int X, int Y){
        icon = '@';
        x = X;
        y = Y;
    }

    void Move(char ch, optional<Cell**> cells, int h, int w){
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

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }
};

class Map {
    int height, width;

    Hero* hero;

public:
    optional<Cell**> cells;
    Map(int h, int w, Hero* he) {
        height = h;
        width = w;
        hero = he;

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


    void generate() {
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


    void render() {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if(i == hero->getY() && j == hero->getX()){
                    cells.value()[i][j].setObject(hero);
                }
                cout << cells.value()[i][j].getIcon();
            }
            cout << endl;
        }
    }
};



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
