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
    int grid[20][10];

private:
    vector<Color> GetCellColors();
    int numRens;
    int numCols;
    int tamCelda;
    vector<Color> colors;
};