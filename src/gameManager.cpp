#include "../include/gameManager.h"

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
    Cell** cells = map->getCells();

    int j = std::floor(hero->getPosition().x / 40);
    int i = std::floor(hero->getPosition().y / 40);

    if (i >= map->getHeight() || i < 0 || j >= map->getWidth() || j < 0) {
        return;
    }
    
    // cells[i][j].getObject()->setColor(RED);
}

