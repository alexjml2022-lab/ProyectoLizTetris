#pragma once
#include <vector>
#include <raylib.h>
using namespace std;

struct Grid
{
    int **grid;
    int numRens;
    int numCols;
    int tamCelda;
    vector<Color> colors;
};

void Grid_Iniciar(Grid *g); 
void Grid_IniciarMatriz(Grid *g);
void Grid_BorrarMat(Grid *g);
void Grid_Imprimir(Grid *g);
void Grid_Dibujar(Grid *g);
bool Grid_IsCellOutSide(Grid *g, int reng, int col);
bool Grid_IsCellEmpty(Grid *g, int reng, int col);
int Grid_LimpiarTodoRengs(Grid *g);
bool Grid_IsRowFull(Grid *g, int reng);
void Grid_LimpiarReng(Grid *g, int reng);
void Grid_MoverRengAbajo(Grid *g, int reng, int numRengs);