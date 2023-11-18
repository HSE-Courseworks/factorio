#include "item.h"

Item::Item(int cnt) {
    icon = 'T';
    count = cnt;
}

int Item::getItemsCount(){
    return count;
}