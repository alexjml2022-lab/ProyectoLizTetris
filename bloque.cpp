#include "bloque.h"

void Bloque_InicializarBase(Bloque *b)
{
    b->tamCel = 30;
    b->rotaCion = 0;
    b->colors = GetCellColors();
    b->rengOffset = 0;
    b->colOffset = 0;
}

void Bloque_Dibujar(const Bloque *b, int offsetX, int offsetY)
{
    vector<Posicion> tiles = Bloque_GetCellPosicion(b);
    for (Posicion item : tiles)
    {
        DrawRectangle(item.col * b->tamCel + offsetX, item.reng * b->tamCel + offsetY, b->tamCel - 1, b->tamCel - 1, b->colors[b->id]);
    }
}

void Bloque_Mover(Bloque *b, int rengs, int cols)
{
    b->rengOffset += rengs;
    b->colOffset += cols;
}

vector<Posicion> Bloque_GetCellPosicion(const Bloque *b)
{
    auto it = b->celdas.find(b->rotaCion);
    if (it == b->celdas.end())
        return {};

    vector<Posicion> tiles = it->second;
    vector<Posicion> moverTiles;
    for (Posicion item : tiles)
    {
        Posicion nPos = {item.reng + b->rengOffset, item.col + b->colOffset};
        moverTiles.push_back(nPos);
    }
    return moverTiles;
}

void Bloque_Rotar(Bloque *b)
{
    b->rotaCion++;
    if (b->rotaCion == (int)b->celdas.size())
    {
        b->rotaCion = 0;
    }
}

void Bloque_KyaRotacion(Bloque *b)
{
    b->rotaCion--;
    if (b->rotaCion == -1)
    {
        b->rotaCion = (int)b->celdas.size() - 1;
    }
}