#pragma once

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "map.h"
#include "hero.h"

class GameManager{
private:
    Hero* hero;
    Map* map;
    Camera2D* cam;
public:
    GameManager(Map* m, Hero* h, Camera2D* c);

    void detectCollision();

    void Update();
};

#endif