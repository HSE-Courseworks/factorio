#include "item.h"

Item::Item() {
    icon = 'T';
    count = 0;
}

int Item::getItemsCount(){
    return count;
}

void Item::IncreaseCount(int value){
    this->count += value;
}
