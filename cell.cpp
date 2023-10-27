#include "cell.h"
#include "object.h"
#include "ground.h"

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

_Object* Cell::getObject(){
    return objects[objects.size() - 1];
}