#include "raylib.h"
#include "colors.h"
#include "grid.h"
using namespace TetoColores;
int main()
{

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