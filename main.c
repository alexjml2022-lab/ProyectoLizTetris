#include "raylib.h"

int main() {
    InitWindow(800, 450, "¡Raylib funcionando!");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Si ves esto, ¡instalaste todo bien!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}