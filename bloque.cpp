#include "bloque.h"
using namespace std;
Bloque::Bloque()
{
    tamCel = 30;
    rotaCion = 0;
    colors = GetCellColors();
    rengOffset = 0;
    colOffset = 0;
}

void Bloque::Dibujar(int offsetX, int offsetY)
{
    vector<Posicion> tiles = GetCellPosicion();
    for (Posicion item : tiles)
    {
        DrawRectangle(item.col * tamCel + offsetX, item.reng * tamCel + offsetY, tamCel - 1, tamCel - 1, colors[id]);
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

void Bloque::Rotar()
{
    rotaCion++;
    if (rotaCion == (int)celdas.size())
    {
        rotaCion = 0;
    }
}

void Bloque::KyaRotacion()
{
    rotaCion--;
    if (rotaCion == -1)
    {
        rotaCion = celdas.size() - 1;
    }
}
