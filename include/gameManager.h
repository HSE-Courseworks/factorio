#pragma once

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "belt.h"
#include "map.h"
#include "hero.h"
#include "../raylib/src/raylib.h"

#include<vector>

class GameManager{
private:
    Hero* hero;
    Map* map;
    Camera2D* cam;
    std::vector<Belt*> belts;
public:
    GameManager(Map* m, Hero* h, Camera2D* c);

    void detectCollision();

    void Update();

    void Show();

    void BeltsAction();

    void PrintMap();
};

#endif