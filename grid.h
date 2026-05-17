#pragma once
#include <vector>
#include <raylib.h>
using namespace std;
class Grid
{
public:
    Grid();
    ~Grid();
    void BorrarMat();
    void Iniciar();
    void Imprimir();
    void Dibujar();
    bool IsCellOutSide(int reng, int col);
    bool IsCellEmpty(int reng, int col);
    int limpiarTodoRengs();
    int **grid;
    Grid(const Grid &) = delete;
    Grid &operator=(const Grid &) = delete;

private:
    bool IsRowFull(int reng);
    void LimpiarReng(int reng);
    void MoverRengAbajo(int reng, int numRengs);
    int numRens;
    int numCols;
    int tamCelda;
    vector<Color> colors;
};