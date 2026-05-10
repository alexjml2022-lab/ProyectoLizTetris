#include "bloque.h"
#include <iostream>
using namespace std;
Bloque::Bloque()
{
    tamCel = 30;
    rotaCion = 0;
    colors = GetCellColors();
    rengOffset = 0;
    colOffset = 0;
}

void Bloque::Dibujar()
{
    vector<Posicion> tiles = GetCellPosicion();
    for (Posicion item : tiles)
    {
        DrawRectangle(item.col * tamCel + 1, item.reng * tamCel, tamCel - 1, tamCel - 1, colors[id]);
    }
}

void Bloque::Mover(int rengs, int cols)
{
    rengOffset += rengs;
    colOffset += cols;
}

vector<Posicion> Bloque::GetCellPosicion()
{
    vector<Posicion> tiles = celdas[rotaCion];
    vector<Posicion> moverTiles;
    for (Posicion item : tiles)
    {
        Posicion nPos = Posicion(item.reng + rengOffset, item.col + colOffset);
        moverTiles.push_back(nPos);
    }
    return moverTiles;
}