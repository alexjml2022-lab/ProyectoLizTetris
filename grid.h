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
    bool IsCellEmpty(int reng, int col);
    int limpiarTodoRengs();
    int grid[20][10];

private:
    bool IsRowFull(int reng);
    void LimpiarReng(int reng);
    void MoverRengAbajo(int reng, int numRengs);
    int numRens;
    int numCols;
    int tamCelda;
    vector<Color> colors;
};