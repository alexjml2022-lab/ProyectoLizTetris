#pragma once
#include "grid.h"
#include "bloque.h"
#include <vector>

using namespace std;

struct Juego
{
    Grid grid;
    vector<Bloque> bloques;
    Bloque actuBloque;
    Bloque sigBloque;
    bool gameOver;
    int puntaje;
    Music musica;
    Sound rotateSound;
    Sound clearSound;
};

void Juego_Inicializar(Juego *j);
void Juego_Destruir(Juego *j);
void Juego_Dibujar(Juego *j);
void Juego_HandleInput(Juego *j);
void Juego_MoverAbajo(Juego *j);
void Juego_MoverIzquierda(Juego *j);
void Juego_MoverDerecha(Juego *j);
bool Juego_IsBlockOutSide(Juego *j);
void Juego_RotarBloque(Juego *j);
void Juego_TerryBlo(Juego *j);
bool Juego_coliBloque(Juego *j);
void Juego_Reset(Juego *j);
