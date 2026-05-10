#include "bloque.h"
#include "posicion.h"

class LBloque : public Bloque
{
public:
    LBloque()
    {
        id = 1;
        celdas[0] = {
            Posicion(0, 2),
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
        };
        celdas[1] = {
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(2, 1),
            Posicion(2, 2),
        };
        celdas[2] = {
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 0),
        };
        celdas[3] = {
            Posicion(0, 0),
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(2, 1),
        };
        Mover(0, 3);
    }
};

class JBloque : public Bloque
{
public:
    JBloque()
    {
        id = 2;
        celdas[0] = {
            Posicion(0, 0),
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
        };
        celdas[1] = {
            Posicion(0, 1),
            Posicion(0, 2),
            Posicion(1, 1),
            Posicion(2, 1),
        };
        celdas[2] = {
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 2),
        };
        celdas[3] = {
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(2, 0),
            Posicion(2, 1),
        };
        Mover(0, 3);
    }
};

class IBloque : public Bloque
{
public:
    IBloque()
    {
        id = 3;
        celdas[0] = {
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(1, 3),
        };
        celdas[1] = {
            Posicion(0, 2),
            Posicion(1, 2),
            Posicion(2, 2),
            Posicion(3, 2),
        };
        celdas[2] = {
            Posicion(2, 0),
            Posicion(2, 1),
            Posicion(2, 2),
            Posicion(2, 3),
        };
        celdas[3] = {
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(2, 1),
            Posicion(3, 1),
        };
        Mover(-1, 3);
    }
};

class OBloque : public Bloque
{
public:
    OBloque()
    {
        id = 4;
        celdas[0] = {
            Posicion(0, 0),
            Posicion(0, 1),
            Posicion(1, 0),
            Posicion(1, 1),
        };
        Mover(0, 4);
    }
};

class SBloque : public Bloque
{
public:
    SBloque()
    {
        id = 5;
        celdas[0] = {
            Posicion(0, 1),
            Posicion(0, 2),
            Posicion(1, 0),
            Posicion(1, 1),
        };
        celdas[1] = {
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 2),
        };
        celdas[2] = {
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 0),
            Posicion(2, 1),
        };
        celdas[3] = {
            Posicion(0, 0),
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(2, 1),
        };
        Mover(0, 3);
    }
};

class TBloque : public Bloque
{
public:
    TBloque()
    {
        id = 6;
        celdas[0] = {
            Posicion(0, 1),
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
        };
        celdas[1] = {
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 1),
        };
        celdas[2] = {
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 1),
        };
        celdas[3] = {
            Posicion(0, 1),
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(2, 1),
        };
        Mover(0, 3);
    }
};

class ZBloque : public Bloque
{
public:
    ZBloque()
    {
        id = 7;
        celdas[0] = {
            Posicion(0, 0),
            Posicion(0, 1),
            Posicion(1, 1),
            Posicion(1, 2),
        };
        celdas[1] = {
            Posicion(0, 2),
            Posicion(1, 1),
            Posicion(1, 2),
            Posicion(2, 1),
        };
        celdas[2] = {
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(2, 1),
            Posicion(2, 2),
        };
        celdas[3] = {
            Posicion(0, 1),
            Posicion(1, 0),
            Posicion(1, 1),
            Posicion(2, 0),
        };
        Mover(0, 3);
    }
};