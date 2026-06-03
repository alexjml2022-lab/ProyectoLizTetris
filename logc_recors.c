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
        printf("Error al abrir el archivo.\n");
        return;
    }

    // Array para guardar a todos los jugadores del archivo
    Jugador lista_jugadores[MAX_JUGADORES];
    int contador = 0;

    //Guardamos todo el archivo en el array
    while (fscanf(file, "%d %19s", &lista_jugadores[contador].puntuation, lista_jugadores[contador].name) == 2)
    {
        contador++;
        if (contador >= MAX_JUGADORES) break;
    }
    
    fclose(file);

    if (contador == 0)
    {
        printf("El archivo de puntuaciones está vacío.\n");
        return;
    }

    for (int i = 0; i < contador - 1; i++)
    {
        for (int j = 0; j < contador - i - 1; j++)
        {
            if (lista_jugadores[j].puntuation < lista_jugadores[j + 1].puntuation)
            {
                Jugador temp = lista_jugadores[j];
                lista_jugadores[j] = lista_jugadores[j + 1];
                lista_jugadores[j + 1] = temp;
            }
        }
    }

    printf("\n   PUNTUACIONES MAS ALTAS   \n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d. Jugador: %-15s | Puntuacion: %d\n", i + 1, lista_jugadores[i].name, lista_jugadores[i].puntuation);
    }
}

    fclose(file);
}
