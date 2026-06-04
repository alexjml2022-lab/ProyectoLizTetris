#ifndef RECORS_H
#define RECORS_H

// Declaramos la variable como 'extern' para que el main sepa que existe,
// pero su espacio real se asigne en el archivo .c
extern char player_name[20];

// Prototipos de las funciones
void setName(char *input_player);
void saveGame(char *name, int player_puntuation);
//void loadPuntuation(void);

#endif // RECORS_H