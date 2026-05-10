#pragma once
#include <vector>
#include <raylib.h>
using namespace std;
class Grid
{
public:
    Grid();
    void Iniciar();
    void Imprimir();
    void Dibujar();
    bool IsCellOutSide(int reng, int col);
    int grid[20][10];

private:
    int numRens;
    int numCols;
    int tamCelda;
    vector<Color> colors;
};