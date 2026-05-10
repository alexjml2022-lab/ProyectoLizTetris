#include "juego.h"
#include <random>
using namespace std;

Juego::Juego()
{
    grid = Grid();
    bloques = GetAllBloqcks();
    actuBloque = GetRandomBlock();
    sigBloque = GetRandomBlock();
}

Bloque Juego::GetRandomBlock()
{
    if (bloques.empty())
    {
        bloques = GetAllBloqcks();
    }
    int randIndex = rand() % bloques.size();
    Bloque bloque = bloques[randIndex];
    bloques.erase(bloques.begin() + randIndex);
    return bloque;
}

vector<Bloque> Juego::GetAllBloqcks()
{
    return {IBloque(), JBloque(), LBloque(), OBloque(), SBloque(), ZBloque()};
}

void Juego::Dibujar()
{
    grid.Dibujar();
    actuBloque.Dibujar();
}

void Juego::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoverIzquierda();
        break;

    case KEY_RIGHT:
        MoverDerecha();
        break;
    case KEY_DOWN:
        MoverAbajo();
        break;
    }
}

void Juego::MoverIzquierda()
{
    actuBloque.Mover(0, -1);
    if (IsBlockOutSide())
    {
        actuBloque.Mover(0,1);
    }
}
void Juego::MoverDerecha()
{
    actuBloque.Mover(0, 1);
    if (IsBlockOutSide())
    {
        actuBloque.Mover(0,-1);
    }
}
void Juego::MoverAbajo()
{
    actuBloque.Mover(1, 0);
    if (IsBlockOutSide())
    {
        actuBloque.Mover(-1,0);
    }
}

bool Juego::IsBlockOutSide()
{
    vector<Posicion> tiles = actuBloque.GetCellPosicion();
    for (Posicion item : tiles)
    {
        if (grid.IsCellOutSide(item.reng, item.col))
        {
            return true;
        }
    }
    return false;
}
