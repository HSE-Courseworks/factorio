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
        std::cout << items[i]->getIcon() << " ";
    }

}