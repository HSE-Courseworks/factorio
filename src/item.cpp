#include "../include/item.h"

int Item::GetCount(){
    return this->count;
}

void Item::IncreaseCount(){
    this->count++;
}