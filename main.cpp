#include "raylib.h"
#include "colorss.h"
#include "juego.h"
#include <iostream>

using namespace TetoColores;

double ultimoTempo = 0;
bool EventTriggered(double intervalo)
{
    double actuTempo = GetTime();
    if (actuTempo - ultimoTempo >= intervalo)
    {
        ultimoTempo = actuTempo;
        return true;
    }
    return false;
}

int main()
{

    InitWindow(500, 620, "Tetris");
    SetTargetFPS(60);

    Juego juego = Juego();
    while (!WindowShouldClose())
    {
        UpdateMusicStream(juego.musica);
        juego.HandleInput();
        if (EventTriggered(0.2))
        {
            juego.MoverAbajo();
        }
        BeginDrawing();
        ClearBackground(tetoRed);

        DrawText("Score", 350, 15, 38, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, tetoGrey);
        char *puntaje = new char[10];
        sprintf(puntaje, "%d", juego.puntaje);
        Vector2 tamTexto = MeasureTextEx(GetFontDefault(), puntaje, 38, 0);
        DrawText(puntaje, 320 + (170 - tamTexto.x) / 2, 65, 38, WHITE);

        DrawText("Next", 365, 175, 38, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, tetoGrey);
        if (juego.gameOver)
        {
            DrawText("Game Over", 320, 450, 35, WHITE);
        }

        juego.Dibujar();
        EndDrawing();
        delete[] puntaje;
    }

    CloseWindow();
    return 0;
}