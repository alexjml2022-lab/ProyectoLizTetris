#ifndef MENU_H
#define MENU_H

// Definición del tipo enumerado para controlar los estados de las pantallas.
// Esto permite que updatescreen() sepa en qué sección del juego está el usuario.
typedef enum Pantalla {
    MENU,
    JUEGO,
    RECORS
} Pantalla;

// Prototipo de la función principal del módulo del menú.
// Configura la interfaz, procesa los clics de un solo fotograma y devuelve la pantalla activa.
Pantalla updatescreen(void);

#endif // MENU_H
