#include "../include/gameManager.h"
#include <string>
#include <sstream>

using namespace std;

GameManager::GameManager(Map* m, Hero* h, Camera2D* c){
    map = m;
    hero = h;
    cam = c;
    // belts = std::vector<Belt*>();
}

void GameManager::Update() {
    hero->Update();
    BeltsAction();
    hero->PlaceItems(map->getCells(), belts);

    if (IsKeyPressed(KEY_E)) {
        hero->Dig(map->getCells());
    }

    if (IsKeyPressed(KEY_Q)) {
        hero->Drop(map->getCells());
    }

    hero->Draw();

    // Получаем позицию персонажа
    Vector2 heroPosition = hero->getPosition();

    // Устанавливаем позицию камеры в центре персонажа
    cam->target.x = heroPosition.x;
    cam->target.y = heroPosition.y;

    hero->getInventory()->showItems(cam->target);

    
}

void GameManager::detectCollision() {
    int j = std::floor(hero->getPosition().x / 40);
    int i = std::floor(hero->getPosition().y / 40);

    if (i >= map->getHeight() || i < 0 || j >= map->getWidth() || j < 0) {
        return;
    }
    // cells[i][j].getObject()->setColor(RED);
}

void GameManager::Show() {
    int j = std::floor(hero->getPosition().x / 40);
    int i = std::floor(hero->getPosition().y / 40);

    auto objects = map->getCells()[i][j].getObjects();

    int x = hero->getPosition().x + 600;
    int y = hero->getPosition().y - 320;
  
    for (int i = 0; i < objects.size(); i++) {
        std::stringstream ss;

        ss << objects[i]->getIcon();

        DrawText(ss.str().c_str(), x, y, 28, WHITE);
        y += 28;
    }
}

void GameManager::BeltsAction() {
    if (belts.empty()) {
        return;
    }

    for (auto &belt : belts) {
        belt->Action(map->getCells());
    }
}

void GameManager::PrintMap() {
    int j = std::floor(hero->getPosition().x / 40);
    int i = std::floor(hero->getPosition().y / 40);
    for (int a = -10; a < 10; a++) {
        for (int b = -10; b < 10; b++) {
            if (i + a < 0 || j + a < 0) {
                return;
            }
            auto objects = map->getCells()[i + a][j + b].getObjects();
            for (auto &obj : objects) {
                obj->draw();
            }
        }
    }
}

