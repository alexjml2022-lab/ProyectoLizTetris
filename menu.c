#include "raylib.h"
#include "menu.h"
#include "recors.h"
#include <stdio.h>
#include <stdlib.h>

// Función auxiliar para dibujar texto centrado en un botón
void DrawTextCentered(const char *text, Rectangle btn, int fontSize, Color color)
{
    int textWidth = MeasureText(text, fontSize);     
    int textX = btn.x + (btn.width - textWidth) / 2; 
    int textY = btn.y + (btn.height - fontSize) / 2; 
    DrawText(text, textX, textY, fontSize, color);
}

// Función auxiliar para dibujar texto centrado en la pantalla
void DrawTitleCentered(const char *text, int y, int fontSize, Color color)
{
    int textWidth = MeasureText(text, fontSize); 
    int textX = (GetScreenWidth() - textWidth) / 2;
    DrawText(text, textX, y, fontSize, color);
}

Pantalla updatescreen(void)
{
    SetTargetFPS(60);

    // 1. Inicialización de la ventana
    int screenWidth = 730;
    int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "TETRIS");

    Pantalla pantallaActual = MENU; // Comenzamos en el menú

    // Cargamos la textura
    Texture2D fondoMenu = LoadTexture("fondo.png");

    // Botones
    Rectangle botonJugar = {screenWidth / 2.0f - 100, screenHeight / 2.0f - 25, 200, 50};

    Rectangle botonRegresar = {screenWidth / 2.0f - 100, screenHeight / 2.0f + 120, 200, 50};

    Rectangle botonRecors = {screenWidth / 2.0f - 100, screenHeight / 2.0f + 50, 200, 50};

    Rectangle botonSalir = {screenWidth / 2.0f - 100, screenHeight / 2.0f + 195, 200, 50};

    // Variables independientes para saber si el ratón está sobre cada botón
    bool ratonSobreJugar = false;
    bool ratonSobreRegresar = false;
    bool ratonSobreRecors = false;
    bool ratonSobreSalir = false;

    // Controla si el juego termina
    bool deboCerrar = false;

    int anchoJugar = MeasureText("JUGAR", 20);
    int anchoRegresar = MeasureText("REGRESAR", 20);
    int anchoRecors = MeasureText("RECORS", 20);
    int anchoSalir = MeasureText("SALIR", 20);

    // Variables locales para la lectura y renderizado del archivo de texto
    FILE *fileRecords = NULL;
    char temp_name[20];
    int temp_puntuation;
    char bufferTexto[50]; 

    BeginDrawing();
    DrawTexture(fondoMenu, 0, 0, WHITE);
    ClearBackground(RAYWHITE);
    Vector2 ratonPos = GetMousePosition();

    // ----------------- MENU -----------------
    switch (pantallaActual)
    {
    case MENU://------------------------Menu--------------------------
        // TITULO
        DrawTitleCentered("TETRIS", 120, 60, WHITE);

        // Dibujar botónes
        DrawRectangleRec(botonJugar, ratonSobreJugar ? LIGHTGRAY : GREEN);
        DrawRectangleLinesEx(botonJugar, 2, BLACK);
        DrawRectangleRec(botonRecors, ratonSobreRecors ? LIGHTGRAY : DARKPURPLE);
        DrawRectangleLinesEx(botonRecors, 2, BLACK);
        DrawRectangleRec(botonSalir, ratonSobreSalir ? LIGHTGRAY : RED);
        DrawRectangleLinesEx(botonSalir, 2, BLACK);

        // TEXTO DE LOS BOTONES
        DrawText("JUGAR", botonJugar.x + (botonJugar.width - anchoJugar) / 2, botonJugar.y + 15, 20, BLACK);
        DrawText("RECORS", botonRecors.x + (botonRecors.width - anchoRecors) / 2, botonRecors.y + 15, 20, BLACK);
        DrawText("SALIR", botonSalir.x + (botonSalir.width - anchoSalir) / 2, botonSalir.y + 15, 20, BLACK);

        // ---------------JUGAR------------------
        if (CheckCollisionPointRec(ratonPos, botonJugar))
        {
            ratonSobreJugar = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                pantallaActual = JUEGO;
            }
        }
        else
        {
            ratonSobreJugar = false;
        }

        // ---------------RECORS------------------
        if (CheckCollisionPointRec(ratonPos, botonRecors))
        {
            ratonSobreRecors = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                pantallaActual = RECORS;
            }
        }
        else
        {
            ratonSobreRecors = false;
        }

        // ---------------SALIR----------------------
        if (CheckCollisionPointRec(ratonPos, botonSalir))
        {
            ratonSobreSalir = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                deboCerrar = true;
            }
        }
        else
        {
            ratonSobreSalir = false;
        }

        break;

    case JUEGO://--------------Juego------------------
        // TITULO
        DrawTitleCentered("JUGAR", 120, 60, WHITE);

        // DIBUJAR BOTONES
        DrawRectangleRec(botonJugar, ratonSobreJugar ? LIGHTGRAY : GREEN);
        DrawRectangleLinesEx(botonJugar, 2, BLACK);
        DrawRectangleRec(botonRegresar, ratonSobreRegresar ? LIGHTGRAY : ORANGE);
        DrawRectangleLinesEx(botonRegresar, 2, BLACK);
        DrawRectangleRec(botonSalir, ratonSobreSalir ? LIGHTGRAY : RED);
        DrawRectangleLinesEx(botonSalir, 2, BLACK);

        // TEXTO DE LOS BOTONES
        DrawText("JUGAR", botonJugar.x + (botonJugar.width - anchoJugar) / 2, botonJugar.y + 15, 20, BLACK);
        DrawText("REGRESAR", botonRegresar.x + (botonRegresar.width - anchoRegresar) / 2, botonRegresar.y + 15, 20, BLACK);
        DrawText("SALIR", botonSalir.x + (botonSalir.width - anchoSalir) / 2, botonSalir.y + 15, 20, BLACK);

        // ---------------REGRESAR------------------
        if (CheckCollisionPointRec(ratonPos, botonRegresar))
        {
            ratonSobreRegresar = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                pantallaActual = MENU;
            }
        }
        else
        {
            ratonSobreRegresar = false;
        }

        // ---------------SALIR------------------
        if (CheckCollisionPointRec(ratonPos, botonSalir))
        {
            ratonSobreSalir = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                deboCerrar = true;
            }
        }
        else
        {
            ratonSobreSalir = false;
        }

        break;

    case RECORS: //------------------------Recors------------------
        // TITULO
        DrawTitleCentered("TABLA DE RECORS", 80, 50, WHITE);

        // DIBUJAR BOTONES
        DrawRectangleRec(botonRegresar, ratonSobreRegresar ? LIGHTGRAY : ORANGE);
        DrawRectangleLinesEx(botonRegresar, 2, BLACK);
        DrawRectangleRec(botonSalir, ratonSobreSalir ? LIGHTGRAY : RED);
        DrawRectangleLinesEx(botonSalir, 2, BLACK);

        // TEXTO DE LOS BOTONES
        DrawText("REGRESAR", botonRegresar.x + (botonRegresar.width - anchoRegresar) / 2, botonRegresar.y + 15, 20, BLACK);
        DrawText("SALIR", botonSalir.x + (botonSalir.width - anchoSalir) / 2, botonSalir.y + 15, 20, BLACK);

        // --- NUEVA IMPLEMENTACIÓN EN EL CASO RECORS ---
        fileRecords = fopen("puntuaciones.txt", "r");
        if (fileRecords == NULL)
        {
            DrawTitleCentered("No hay records guardados aun.", screenHeight / 2, 20, MAROON);
        }
        else
        {
            int filaY = 160; // Dónde empieza el primer renglón de texto
            int contador = 1;

            // El bucle fscanf que ya conoces, adaptado para la pantalla gráfica
            while (fscanf(fileRecords, "%d %19s", &temp_puntuation, temp_name) == 2 && contador <= 5)
            {
                // Juntamos el entero y la cadena en un solo buffer formateado
                snprintf(bufferTexto, sizeof(bufferTexto), "%d. %-12s ...... %d pts", contador, temp_name, temp_puntuation);
                
                // Lo dibujamos en la pantalla de Raylib
                DrawText(bufferTexto, screenWidth / 2 - 140, filaY, 20, RAYWHITE);
                
                filaY += 35; // Bajamos 35 píxeles para el siguiente jugador de la lista
                contador++;
            }
            fclose(fileRecords);
        }

        // ---------------REGRESAR------------------
        if (CheckCollisionPointRec(ratonPos, botonRegresar))
        {
            ratonSobreRegresar = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                pantallaActual = MENU;
            }
        }
        else
        {
            ratonSobreRegresar = false;
        }

        // ---------------SALIR------------------
        if (CheckCollisionPointRec(ratonPos, botonSalir))
        {
            ratonSobreSalir = true;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                deboCerrar = true;
            }
        }
        else
        {
            ratonSobreSalir = false;
        }

        break;

    } // switch

    EndDrawing();

    // 4. Limpieza y cierre
    UnloadTexture(fondoMenu);
    CloseWindow();

    return pantallaActual;
}// luis estuvo aqui
