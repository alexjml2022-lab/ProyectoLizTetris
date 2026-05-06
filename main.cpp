#include "raylib.h"
#include "colors.h"
#include "grid.h"
using namespace TetoColores;
int main()
{

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Imprimir(); 

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(tetoRed);
        grid.Dibujar();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}