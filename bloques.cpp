#include "bloque.h"
#include "posicion.h"

Bloque CrearLBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 1;
    b.celdas[0] = {{0, 2}, {1, 0}, {1, 1}, {1, 2}};
    b.celdas[1] = {{0, 1}, {1, 1}, {2, 1}, {2, 2}};
    b.celdas[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 0}};
    b.celdas[3] = {{0, 0}, {0, 1}, {1, 1}, {2, 1}};
    Bloque_Mover(&b, 0, 3);
    return b;
}

Bloque CrearJBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 2;
    b.celdas[0] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}};
    b.celdas[1] = {{0, 1}, {0, 2}, {1, 1}, {2, 1}};
    b.celdas[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 2}};
    b.celdas[3] = {{0, 1}, {1, 1}, {2, 0}, {2, 1}};
    Bloque_Mover(&b, 0, 3);
    return b;
}

Bloque CrearIBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 3;
    b.celdas[0] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}};
    b.celdas[1] = {{0, 2}, {1, 2}, {2, 2}, {3, 2}};
    b.celdas[2] = {{2, 0}, {2, 1}, {2, 2}, {2, 3}};
    b.celdas[3] = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};
    Bloque_Mover(&b, -1, 3); 
    return b;
}

Bloque CrearOBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 4;
    b.celdas[0] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    Bloque_Mover(&b, 0, 4);
    return b;
}

Bloque CrearSBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 5;
    b.celdas[0] = {{0, 1}, {0, 2}, {1, 0}, {1, 1}};
    b.celdas[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 2}};
    b.celdas[2] = {{1, 1}, {1, 2}, {2, 0}, {2, 1}};
    b.celdas[3] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
    Bloque_Mover(&b, 0, 3);
    return b;
}

Bloque CrearTBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 6;
    b.celdas[0] = {{0, 1}, {1, 0}, {1, 1}, {1, 2}};
    b.celdas[1] = {{0, 1}, {1, 1}, {1, 2}, {2, 1}};
    b.celdas[2] = {{1, 0}, {1, 1}, {1, 2}, {2, 1}};
    b.celdas[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 1}};
    Bloque_Mover(&b, 0, 3);
    return b;
}

Bloque CrearZBloque()
{
    Bloque b;
    Bloque_InicializarBase(&b);
    b.id = 7;
    b.celdas[0] = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    b.celdas[1] = {{0, 2}, {1, 1}, {1, 2}, {2, 1}};
    b.celdas[2] = {{1, 0}, {1, 1}, {2, 1}, {2, 2}};
    b.celdas[3] = {{0, 1}, {1, 0}, {1, 1}, {2, 0}};
    Bloque_Mover(&b, 0, 3);
    return b;
}