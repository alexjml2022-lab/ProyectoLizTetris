#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char player_name[20];

void setName(char *input_player)
{
    strncpy(player_name, input_player, sizeof(player_name) - 1);
    player_name[sizeof(player_name) - 1] = '\0';
}

void saveGame(char *name, int player_puntuation)
{
    FILE *file = fopen("puntuaciones.txt", "a"); 
    if (file == NULL)
    {
        perror("Error al abrir el archivo de guardado");
        return;
    }
    
    fprintf(file, "%d %s\n", player_puntuation, name);

    fclose(file);
    printf("Felicidades,%s tu puntuacion ha sido guardada.\n", name);
}

void loadPuntuation()
{
    FILE *file = fopen("puntuaciones.txt", "r");
    if (file == NULL)
    {
        printf("Error al abrir el archivo (Es posible que aun no haya puntuaciones guardadas).\n");
        return;
    }

    // Variables temporales para leer el historial línea por línea
    char temp_name[20];
    int temp_puntuation;
    int contador = 1;

    printf("\n=========================\n");
    printf("   MEJORES PUNTUACIONES   \n");
    printf("===========================\n");

    // El bucle while continuará leyendo mientras fscanf encuentre pares de (int, string)
    while (fscanf(file, "%d %19s", &temp_puntuation, temp_name) == 2)
    {
        printf("%d. Jugador: %-15s | Puntuacion: %d\n", contador, temp_name, temp_puntuation);
        contador++;
    }
    
    if (contador == 1)
    {
        printf("El archivo de puntuaciones está vacío.\n");
    }

    fclose(file);
}