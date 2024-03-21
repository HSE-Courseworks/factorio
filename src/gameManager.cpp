#include "../include/gameManager.h"
#include <string>
#include <sstream>

GameManager::GameManager(Map* m, Hero* h, Camera2D* c){
    map = m;
    hero = h;
    cam = c;
}

void GameManager::Update() {
    // Получаем позицию персонажа
    Vector2 heroPosition = hero->getPosition();
    
    // Устанавливаем позицию камеры в центре персонажа
    cam->target.x = heroPosition.x;
    cam->target.y = heroPosition.y;

    hero->getInventory()->showItems(cam->target);
}

void GameManager::detectCollision(){
    int j = std::floor(hero->getPosition().x / 40);
    int i = std::floor(hero->getPosition().y / 40);

    if (i >= map->getHeight() || i < 0 || j >= map->getWidth() || j < 0) {
        return;
    }
    
    // cells[i][j].getObject()->setColor(RED);
}

void GameManager::Show(){
    int j = std::floor(hero->getPosition().x / 40);
    int i = std::floor(hero->getPosition().y / 40);

    

    auto objects = map->getCells()[i][j].getObjects();

    int x = hero->getPosition().x + 700;
    int y = hero->getPosition().y - 380; 

    for (int i = 0; i < objects.size(); i++)
    {
        std::stringstream ss;
        if(objects[i].getIcon() == '@'){
            continue;
        }

        ss << objects[i].getIcon();
        
        DrawText(ss.str().c_str(), x, y, 28, WHITE);
        ss.clear();
        y += 28;
    }
}

