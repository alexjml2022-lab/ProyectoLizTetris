#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "posicion.h"
#include "colors.h"

using namespace std;
class Bloque
{
public:
    Bloque();
    void Dibujar();
    void Mover(int rengs, int cols);
    vector<Posicion> GetCellPosicion();
    int id;
    map<int, vector<Posicion>> celdas;

private:
    int tamCel;
    int rotaCion;
    vector<Color> colors;
    int rengOffset;
    int colOffset;
};
