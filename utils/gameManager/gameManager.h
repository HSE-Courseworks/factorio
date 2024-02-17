#pragma once

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../hero/hero.h"
#include "../map/map.h"
#include "../object/object.h"
#include "../ground/ground.h"

#include "windows.h"
#include <vector>

class GameManager{
    Hero* hero;
    Map* map;
public:
    GameManager(Hero* he, Map* m);

    void ShowInfo();
};

#endif