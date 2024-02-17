#include "cell.h"
#include "../object/object.h"
#include "../ground/ground.h"


Cell::Cell() {
    auto ground = new Ground();
    objects.push_back(ground);
}

char Cell::getIcon() {
    return objects[objects.size() - 1] -> getIcon();
}

void Cell::setObject(_Object* object) {
    objects.push_back(object);
}

void Cell::removeObject(){
    objects.pop_back();
}

char Cell::getObjectUnderHero(){
    return objects[objects.size() - 2] -> getIcon();
}

_Object* Cell::getObject(){
    if(objects.size() == 0) return nullptr;
    return objects[objects.size() - 1];
}

std::vector<_Object*> Cell::getObjects(){
    return this->objects;
}