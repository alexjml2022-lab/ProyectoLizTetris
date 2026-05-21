#include "raylib.h"

// Estados
typedef enum
{
    MENU,
    JUEGO,
    RECORS
} Pantalla;

// Función auxiliar para dibujar texto centrado en un botón
void DrawTextCentered(const char *text, Rectangle btn, int fontSize, Color color);

// Función auxiliar para dibujar texto centrado en la pantalla
void DrawTitleCentered(const char *text, int y, int fontSize, Color color);

Pantalla updatescreen ();// luis estuvo aqui