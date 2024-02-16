#include "gameManager.h"

GameManager::GameManager(Hero* he, Map* m){
    this->hero = he;
    this->map = m;
}

void GameManager::ShowInfo(){
    // Дескриптор консоли
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Получение размеров окна консоли
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    int consoleWidth = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
    int consoleHeight = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;

    int hx = hero->getX();
    int hy = hero->getY();

    auto objects = map->cells.value()[hy][hx].getObjects();

    // Координаты для вывода инвентаря
    int x = (consoleWidth - 3); // 2 - ширина одного элемента массива
    int y = 0;

    COORD pos = {SHORT(x), SHORT(y)};
    SetConsoleCursorPosition(hConsole, pos);
    
    for (int i = 0; i < objects.size(); i++)
    {

        if(objects[i]->getIcon() == '@'){
            continue;
        }

        std::cout << objects[i]->getIcon() << ":" << 0;
        x = (consoleWidth - 3);
        y++;

        COORD pos = {SHORT(x), SHORT(y)};
        SetConsoleCursorPosition(hConsole, pos);
    }
}