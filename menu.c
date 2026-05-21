#include "raylib.h"
#include "menu.h"
// Función auxiliar para dibujar texto centrado en un botón
void DrawTextCentered(const char *text, Rectangle btn, int fontSize, Color color)
{
    int textWidth = MeasureText(text, fontSize);     // Se utiliza la función MeasureText() de Raylib. Esto mide cuántos píxeles ocupa el texto y permite colocarlo exactamente en el centro del botón, sin importar lo que escribas.
    int textX = btn.x + (btn.width - textWidth) / 2; // En lugar de coordenadas fijas, ahora se usa el ancho de la ventana
    int textY = btn.y + (btn.height - fontSize) / 2; // para calcular el centro exacto: (screenWidth - buttonWidth) / 2.
    DrawText(text, textX, textY, fontSize, color);
}

// Función auxiliar para dibujar texto centrado en la pantalla
void DrawTitleCentered(const char *text, int y, int fontSize, Color color)
{
    int textWidth = MeasureText(text, fontSize); // Se utiliza la función MeasureText() de Raylib. Esto mide cuántos píxeles ocupa el texto y permite colocarlo exactamente en el centro del botón, sin importar lo que escribas.
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

    // Definimos la posición y tamaño del boton jugar
    Rectangle botonJugar = {screenWidth / 2.0f - 100, screenHeight / 2.0f - 25, 200, 50};

    // botón regresar un poco más abajo para diferenciarlo
    Rectangle botonRegresar = {screenWidth / 2.0f - 100, screenHeight / 2.0f + 50, 200, 50};

    // Definimos la posición y tamaño del boton de los recors
    Rectangle botonRecors = {screenWidth / 2.0f - 100, screenHeight / 2.0f + 50, 200, 50};

    // Definimos la posición y tamaño del boton de los SALIDA
    Rectangle botonSalir = {screenWidth / 2.0f - 100, screenHeight / 2.0f + 125, 200, 50};

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

    BeginDrawing();
    DrawTexture(fondoMenu, 0, 0, WHITE);
    ClearBackground(RAYWHITE);
    Vector2 ratonPos = GetMousePosition();

    // ----------------- MENU -----------------
    switch (pantallaActual)
    {
    case MENU:
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

    case JUEGO:
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

    case RECORS:
        // TITULO
        DrawTitleCentered("TABLA DE RECORS", 120, 60, WHITE);

        // DIBUJAR BOTONES
        DrawRectangleRec(botonRegresar, ratonSobreRegresar ? LIGHTGRAY : ORANGE);
        DrawRectangleLinesEx(botonRegresar, 2, BLACK);
        DrawRectangleRec(botonSalir, ratonSobreSalir ? LIGHTGRAY : RED);
        DrawRectangleLinesEx(botonSalir, 2, BLACK);

        // TEXTO DE LOS BOTONES
        DrawText("REGRESAR", botonRegresar.x + (botonRegresar.width - anchoRegresar) / 2, botonRegresar.y + 15, 20, BLACK);
        DrawText("SALIR", botonSalir.x + (botonSalir.width - anchoSalir) / 2, botonSalir.y + 15, 20, BLACK);

        // ---------------TABLA DE RECORS------------------
        // Aqui va la logica de la tabla

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

    return 0;
} // luis estuvo aqui