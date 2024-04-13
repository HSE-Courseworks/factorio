#include "../include/cell.h"
#include "../include/object.h"
#include "../include/ground.h"


Cell::Cell() {
    // auto ground = new Ground();
    // objects.push_back(ground);
}

char Cell::getIcon() {
    return objects[objects.size() - 1]->getIcon();
}

void Cell::setObject(Object* object) {
    objects.push_back(object);
}

void Cell::removeObject(){
    objects.pop_back();

}

Object* Cell::getObjectUnderHero(){
    return objects[objects.size() - 2];
}

Object* Cell::getObject(){
    if(objects.size() == 0) return nullptr;
    return objects[objects.size() - 1];
}

std::vector<Object*> Cell::getObjects(){
    return objects;
}