#include "raylib.h"
#include "colorss.h"
#include "juego.h"

using namespace TetoColores;
int main()
{

    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Juego juego = Juego();
    while (!WindowShouldClose())
    {
        BeginDrawing();

        juego.HandleInput();
        ClearBackground(tetoRed);
        juego.Dibujar();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}