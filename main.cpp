#include <raylib.h>
#include "juego.h"
#include <iostream>
#include "colorss.h"

using namespace TetoColores;

double ultimoTempo = 0.0;

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
    const int screenWidth = 500;
    const int screenHeight = 620;
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Juego juego;
    Juego_Inicializar(&juego);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(juego.musica);
        Juego_HandleInput(&juego);

        if (!juego.gameOver && EventTriggered(0.2))
        {
            Juego_MoverAbajo(&juego);
        }

        BeginDrawing();
        ClearBackground(tetoRed);

        DrawText("Score", 350, 15, 38, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, tetoGrey);

        char puntajeTexto[10];
        sprintf(puntajeTexto, "%d", juego.puntaje);
        Vector2 tamTexto = MeasureTextEx(GetFontDefault(), puntajeTexto, 38, 0);
        DrawText(puntajeTexto, 320 + (170 - tamTexto.x) / 2, 65, 38, WHITE);

        DrawText("Next", 365, 145, 38, WHITE);
        DrawRectangleRounded({320, 190, 170, 150}, 0.15, 6, tetoGrey);

        Juego_Dibujar(&juego);

        if (juego.gameOver)
        {
            DrawText("GAME OVER", 320, 450, 28, WHITE);
            DrawText("A Guardar Puntaje", 315, 490, 19, WHITE);
            DrawText("S Reiniciar", 315, 510, 19, WHITE);
        }

        EndDrawing();
    }

    Juego_Destruir(&juego);
    CloseWindow();
    return 0;
}