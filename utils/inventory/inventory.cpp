#include "inventory.h"
#include <windows.h>
#include <iostream>

Inventory::Inventory(int size){
    
    for (int i = 0; i < size; i++)
    {
        Item* item = new Item();     
        items.push_back(item);
    }
    
}

void Inventory::showItems(){
    // Дескриптор консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Получение размеров окна консоли
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;

    int itemCount = items.size(); 

    // Координаты для вывода инвентаря
    int x = (consoleWidth - itemCount * 2) / 2; // 2 - ширина одного элемента массива
    int y = consoleHeight - 1;

    COORD pos = {SHORT(x), SHORT(y)};
    SetConsoleCursorPosition(hConsole, pos);
    

    // Вывод массива
    for (int i = 0; i < itemCount; i++)
    {
        if (i % consoleWidth == 0 && i != 0) {
            std::cout << "\n";
        }
        if(i == activeItem){
            std::cout << "\033[1;34m" <<items[i]->getIcon() << ":" << items[i]->getItemsCount() << "\033[0m"<<" ";
        }else{
            std::cout << items[i]->getIcon() << ":" << items[i]->getItemsCount() << " ";
        }
        
    }

}

void Inventory::setActiveItem(char ch){
    activeItem = int(ch) - 1;
}

void Inventory::setItemInInventory(Item* item){
    int itemCount = items.size(); 
    for (int i = 0; i < itemCount; i++)
    {
        if(items[i]->getItemsCount() == 0 && items[i]->getIcon() != item->getIcon()){
            items[i] = item;
            return;
        }
    }
}

int Inventory::findItem(Item* item){
    int itemCount = items.size(); 
    for (int i = 0; i < itemCount; i++)
    {
        if(items[i]->getIcon() == item->getIcon()){
            return i;
        }
    }
    return -1;
}

void Inventory::IncreaseItemCount(int i, int value){
    items[i]->IncreaseCount(value);
}