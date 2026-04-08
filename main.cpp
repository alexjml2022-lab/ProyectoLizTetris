#include "raylib.h"

int main()
{
    Color tetoRed = {255, 0, 69, 255};
    Color tetoBlue = {6, 5, 59, 255};
    Color tetoPink = {237, 167, 186, 255};
    Color tetoFiusha = {217, 36, 213, 255};
    Color tetoGrey = {63, 71, 80, 255};
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(tetoRed);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}