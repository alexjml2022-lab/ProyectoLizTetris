#pragma once
#include "grid.h"
#include "bloques.cpp"
using namespace std;

class Juego
{
public:
    Juego();
    ~Juego();
    void Dibujar();
    void HandleInput();
    void MoverAbajo();
    bool gameOver;
    int puntaje;
    Music musica;

private:
    Grid grid;
    Bloque GetRandomBlock();
    vector<Bloque> GetAllBloqcks();
    void MoverIzquierda();
    void MoverDerecha();
    bool IsBlockOutSide();
    void RotarBloque();
    void TerryBlo();
    bool coliBloque();
    void Reset();
    void FPuntaje(int lineas, int puntosMover);
    vector<Bloque> bloques;
    Bloque actuBloque;
    Bloque sigBloque;
    Sound rotateSound;
    Sound clearSound;
};