#pragma once
#include "grid.h"
#include "bloques.cpp"
using namespace std;

class Juego
{
public:
    Juego();
    Bloque GetRandomBlock();
    vector<Bloque> GetAllBloqcks();
    void Dibujar();
    void HandleInput();
    void MoverIzquierda();
    void MoverDerecha();
    void MoverAbajo();
    Grid grid;

private:
    bool IsBlockOutSide();
    vector<Bloque> bloques;
    Bloque actuBloque;
    Bloque sigBloque;
};