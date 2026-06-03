#include <raylib.h>
#include "juego.h"
#include <iostream>
#include "colorss.h"
#include <stdio.h>

using namespace TetoColores;
enum estados
{
    MENU,
    JUEGO,
    SCOREADD
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
void DrawTextCentered(const char *text, Rectangle btn, int fontSize, Color color)
{
    int textWidth = MeasureText(text, fontSize);
    int textX = btn.x + (btn.width - textWidth) / 2;
    int textY = btn.y + (btn.height - fontSize) / 2;
    DrawText(text, textX, textY, fontSize, color);
}

void DrawTitleCentered(const char *text, int y, int fontSize, Color color)
{
    int textWidth = MeasureText(text, fontSize);
    int textX = (500 - textWidth) / 2;
    DrawText(text, textX, y, fontSize, color);
}

int main()
{
    const int screenWidth = 500;
    const int screenHeight = 620;
    InitWindow(screenWidth, screenHeight, "Tetris");
    InitAudioDevice();
    Image icono = LoadImage("public/tetoPNG.png");
    SetWindowIcon(icono);
    UnloadImage(icono);
    SetTargetFPS(60);

    Juego juego;
    bool juegoInicializado = false;

    Rectangle botonJugar = {(float)(screenWidth / 2 - 125), 250, 250, 50};
    Rectangle botonPuntajes = {(float)(screenWidth / 2 - 125), 350, 250, 50};
    Rectangle botonSalir = {(float)(screenWidth / 2 - 125), 450, 250, 50};
    Rectangle botonRegresar = {(float)(screenWidth / 2 - 125), 520, 250, 50};

    estados estadoJ = MENU;
    while (!WindowShouldClose())
    {
        Vector2 ratonPos = GetMousePosition();
        bool ratonSobreJugar = CheckCollisionPointRec(ratonPos, botonJugar);
        bool ratonSobrePuntajes = CheckCollisionPointRec(ratonPos, botonPuntajes);
        bool ratonSobreSalir = CheckCollisionPointRec(ratonPos, botonSalir);
        bool ratonSobreRegresar = CheckCollisionPointRec(ratonPos, botonRegresar);
        switch (estadoJ)
        {
        case MENU:
            if (ratonSobreJugar && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                Juego_Inicializar(&juego);
                juegoInicializado = true;
                estadoJ = JUEGO;
            }
            if (ratonSobrePuntajes && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                estadoJ = SCOREADD;
            if (ratonSobreSalir && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                if (juegoInicializado)
                {
                    Juego_Destruir(&juego);
                }
                CloseAudioDevice();
                CloseWindow();
                return 0;
            }
            break;

        case JUEGO:
            if (juegoInicializado)
            {
                UpdateMusicStream(juego.musica);

                if (!juego.gameOver)
                {
                    Juego_HandleInput(&juego);
                    double velAct = Juego_Niveles(&juego);
                    if (EventTriggered(velAct))
                    {
                        Juego_MoverAbajo(&juego);
                    }
                }
                else
                {
                    if (IsKeyPressed(KEY_A))
                    {
                        FILE *file = fopen("puntuaciones.txt", "a");
                        if (file != NULL)
                        {
                            fprintf(file, "%d %s\n", juego.puntaje, "PLAYER");
                            fclose(file);
                        }
                        juego.gameOver = false;
                        estadoJ = SCOREADD;
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

            if (ratonSobreRegresar)
                DrawRectangleRoundedLines(botonRegresar, 0.3f, 6, WHITE);
            if (ratonSobreRegresar && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                estadoJ = MENU;
            break;

        default:
            break;
        }
        //---------------------Dibujos----------------------
        BeginDrawing();
        ClearBackground(tetoRed);
        if (estadoJ == MENU)
        {
            if (ratonSobreJugar)
                DrawRectangleRoundedLines(botonJugar, 0.3f, 6, WHITE);
            if (ratonSobrePuntajes)
                DrawRectangleRoundedLines(botonPuntajes, 0.3f, 6, WHITE);
            if (ratonSobreSalir)
                DrawRectangleRoundedLines(botonSalir, 0.3f, 6, WHITE);
        }
        else if (estadoJ == SCOREADD)
        {
            if (ratonSobreRegresar)
                DrawRectangleRoundedLines(botonRegresar, 0.3f, 6, WHITE);
        }
        switch (estadoJ)
        {
        case MENU:
            DrawTitleCentered("TETRIS", 100, 50, WHITE);
            DrawRectangleRounded(botonJugar, 0.3f, 6, ratonSobreJugar ? LIGHTGRAY : tetoGrey);
            DrawTextCentered("JUGAR", botonJugar, 28, WHITE);

            // --- BOTÓN PUNTAJES ---
            DrawRectangleRounded(botonPuntajes, 0.3f, 6, ratonSobrePuntajes ? LIGHTGRAY : tetoGrey);
            DrawTextCentered("PUNTAJES", botonPuntajes, 28, WHITE);

            // --- BOTÓN SALIR ---
            DrawRectangleRounded(botonSalir, 0.3f, 6, ratonSobreSalir ? LIGHTGRAY : tetoGrey);
            DrawTextCentered("SALIR", botonSalir, 28, WHITE);
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
        {
            FILE *fileRecords = fopen("puntuaciones.txt", "r");
            if (fileRecords == NULL)
            {
                DrawText("No hay registros todavia.", 120, 200, 20, WHITE);
            }
            else
            {
                DrawTitleCentered("TOP 5 PUNTAJES", 50, 35, WHITE);

                char temp_name[20];
                int temp_puntuation;
                int contador = 1;
                int filaY = 150;
                char bufferNombre[50];
                char bufferPuntos[50];

                while (fscanf(fileRecords, "%d %19s", &temp_puntuation, temp_name) == 2 && contador <= 15)
                {
                    snprintf(bufferNombre, sizeof(bufferNombre), "%d. %s", contador, temp_name);
                    snprintf(bufferPuntos, sizeof(bufferPuntos), "%d pts", temp_puntuation);

                    DrawText(bufferNombre, 100, filaY, 22, WHITE);
                    DrawText(bufferPuntos, 320, filaY, 22, WHITE);

                    filaY += 50;
                    contador++;
                }
                fclose(fileRecords);
            }
            DrawRectangleRounded(botonRegresar, 0.3f, 6, ratonSobreRegresar ? LIGHTGRAY : tetoGrey);
            DrawTextCentered("VOLVER", botonRegresar, 22, WHITE);
            break;
        }

        default:
            break;
        }

        EndDrawing();
    }

    if (juegoInicializado)
    {
        Juego_Destruir(&juego);
    }
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
