#include <vector>

#include "../raylib/src/raylib.h"
#include "../include/object.h"
#include "../include/hero.h"
#include "../include/ground.h"
#include "../include/cell.h"
#include "../include/map.h"
#include "../include/belt.h"
#include "../include/gameManager.h"
#include "../include/item.h"
#include "../include/inventory.h"

int main() {
    InitWindow(1920, 1080, "Factorio");
    // HideCursor();
    SetTargetFPS(144);

    Hero hero = Hero(1920 / 2.0f, 1080 / 2.0f, 15, 15, '@', BLUE);
    hero.setInventory(5);

    // Инициализация камеры
    Camera2D camera = { 0 };
    camera.target = (Vector2){ hero.getPosition().x, hero.getPosition().y };
    camera.offset = (Vector2){ hero.getPosition().x - 285,
    hero.getPosition().y + 125};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    Map map = Map(100, 100);
    map.generate();
    map.generateOres();

    GameManager gm = GameManager(&map, &hero, &camera);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        BeginMode2D(camera);

        map.draw();

        gm.PrintMap();
        gm.detectCollision();
        gm.Show();
        gm.Update();

        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
