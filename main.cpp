#include <raylib.h>
#include "juego.h"
#include <iostream>
#include "colorss.h"

using namespace TetoColores;

enum estados
{
    MENU,
    JUEGO,
    SCOREADD,
    SCORESEE
};

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
    Image icono = LoadImage("public/tetoPNG.png");
    SetWindowIcon(icono);
    UnloadImage(icono);
    SetTargetFPS(60);

    Juego juego;
    bool juegoInicializado = false;

    int botonSeleccionado = 0;
    estados estadoJ = MENU;
    while (!WindowShouldClose())
    {
        switch (estadoJ)
        {
        case MENU:
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN))
            {
                botonSeleccionado = (botonSeleccionado == 0) ? 1 : 0;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                if (botonSeleccionado == 0)
                {
                    Juego_Inicializar(&juego);
                    juegoInicializado = true;
                    estadoJ = JUEGO;
                }
                else
                {
                    estadoJ = SCORESEE;
                }
            }
            break;

        case JUEGO:
            if (juegoInicializado)
            {
                UpdateMusicStream(juego.musica);

                if (!juego.gameOver)
                {
                    Juego_HandleInput(&juego);
                    if (EventTriggered(0.2))
                    {
                        Juego_MoverAbajo(&juego);
                    }
                }
                else
                {
                    if (IsKeyPressed(KEY_A))
                    {
                    }
                    if (IsKeyPressed(KEY_S))
                    {
                        juego.gameOver = false;
                        Juego_Reset(&juego);
                    }
                    if (IsKeyPressed(KEY_M))
                    {
                        Juego_Destruir(&juego);
                        juegoInicializado = false;
                        estadoJ = MENU;
                    }
                }
            }
            break;

        case SCOREADD:
            break;

        case SCORESEE:
            break;

        default:
            break;
        }

        BeginDrawing();
        ClearBackground(tetoRed);

        switch (estadoJ)
        {
        case MENU:
            DrawText("TETRIS", 130, 100, 70, WHITE);

            if (botonSeleccionado == 0)
            {
                DrawRectangleRounded({125, 290, 250, 50}, 0.3, 6, WHITE);
                DrawText("JUGAR", 205, 300, 28, tetoDark);
            }
            else
            {
                DrawRectangleRounded({125, 290, 250, 50}, 0.3, 6, tetoGrey);
                DrawText("JUGAR", 205, 300, 28, WHITE);
            }

            if (botonSeleccionado == 1)
            {
                DrawRectangleRounded({125, 370, 250, 50}, 0.3, 6, WHITE);
                DrawText("PUNTAJES", 185, 380, 28, tetoDark);
            }
            else
            {
                DrawRectangleRounded({125, 370, 250, 50}, 0.3, 6, tetoGrey);
                DrawText("PUNTAJES", 185, 380, 28, WHITE);
            }

            DrawText("Usa Flechas para moverte y ENTER para seleccionar", 50, 550, 16, WHITE);
            break;

        case JUEGO:
        {
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
                DrawText("M Menu", 315, 530, 19, WHITE);
            }
            break;
        }

        case SCOREADD:

            break;

        case SCORESEE:
            break;

        default:
            break;
        }

        EndDrawing();
    }

    Juego_Destruir(&juego);
    CloseWindow();
    return 0;
}