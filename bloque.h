#pragma once
#include <vector>
#include <map>
#include "posicion.h"
#include "colors.h"

using namespace std;

struct Bloque
{
    int id;
    map<int, vector<Posicion>> celdas;
    int tamCel;
    int rotaCion;
    vector<Color> colors;
    int rengOffset;
    int colOffset;
};

void Bloque_InicializarBase(Bloque *b);
void Bloque_Dibujar(const Bloque *b, int offsetX, int offsetY);
void Bloque_Mover(Bloque *b, int rengs, int cols);
vector<Posicion> Bloque_GetCellPosicion(const Bloque *b);
void Bloque_Rotar(Bloque *b);
void Bloque_KyaRotacion(Bloque *b);