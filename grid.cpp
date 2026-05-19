#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std;

void Grid_Iniciar(Grid *g)
{
    g->numRens = 20;
    g->numCols = 10;
    g->tamCelda = 30;
    Grid_IniciarMatriz(g);
    g->colors = GetCellColors();
}

void Grid_IniciarMatriz(Grid *g)
{
    g->grid = new int *[g->numRens];
    for (int reng = 0; reng < g->numRens; reng++)
    {
        g->grid[reng] = new int[g->numCols];
        for (int col = 0; col < g->numCols; col++)
        {
            g->grid[reng][col] = 0; // Inicialización limpia
        }
    }
}

void Grid_BorrarMat(Grid *g)
{
    if (g->grid != nullptr)
    {
        for (int i = 0; i < g->numRens; ++i)
        {
            delete[] g->grid[i];
        }
        delete[] g->grid;
        g->grid = nullptr;
    }
}

void Grid_Imprimir(Grid *g)
{
    for (int rens = 0; rens < g->numRens; rens++)
    {
        for (int cols = 0; cols < g->numCols; cols++)
        {
            cout << g->grid[rens][cols] << " ";
        }
        cout << endl;
    }
}

void Grid_Dibujar(Grid *g)
{
    for (int reng = 0; reng < g->numRens; reng++)
    {
        for (int cols = 0; cols < g->numCols; cols++)
        {
            int ValCeld = g->grid[reng][cols];
            DrawRectangle(cols * g->tamCelda + 11, reng * g->tamCelda + 11, g->tamCelda - 1, g->tamCelda - 1, g->colors[ValCeld]);
        }
    }
}

bool Grid_IsCellOutSide(Grid *g, int reng, int col)
{
    if (reng >= 0 && reng < g->numRens && col >= 0 && col < g->numCols)
    {
        return false;
    }
    return true;
}

bool Grid_IsCellEmpty(Grid *g, int reng, int col)
{
    if (reng >= 0 && reng < g->numRens && col >= 0 && col < g->numCols)
    {
        return g->grid[reng][col] == 0;
    }
    return false;
}

bool Grid_IsRowFull(Grid *g, int reng)
{
    for (int col = 0; col < g->numCols; col++)
    {
        if (g->grid[reng][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid_LimpiarReng(Grid *g, int reng)
{
    for (int col = 0; col < g->numCols; col++)
    {
        g->grid[reng][col] = 0;
    }
}

void Grid_MoverRengAbajo(Grid *g, int reng, int numRengs)
{
    for (int col = 0; col < g->numCols; col++)
    {
        g->grid[reng + numRengs][col] = g->grid[reng][col];
        g->grid[reng][col] = 0;
    }
}

int Grid_LimpiarTodoRengs(Grid *g)
{
    int com = 0;
    for (int reng = g->numRens - 1; reng >= 0; reng--)
    {
        if (Grid_IsRowFull(g, reng))
        {
            Grid_LimpiarReng(g, reng);
            com++;
        }
        else if (com > 0)
        {
            Grid_MoverRengAbajo(g, reng, com);
        }
    }
    return com;
}