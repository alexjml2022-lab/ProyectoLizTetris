#pragma once
#include <vector>
#include <map>
#include "posicion.h"
#include "colors.h"

using namespace std;
class Bloque
{
public:
    Bloque();
    void Dibujar(int offsetX, int offsetY);
    void Mover(int rengs, int cols);
    vector<Posicion> GetCellPosicion();
    void Rotar();
    void KyaRotacion();

    int id;
    map<int, vector<Posicion>> celdas;

private:
    int tamCel;
    int rotaCion;
    vector<Color> colors;
    int rengOffset;
    int colOffset;
};
