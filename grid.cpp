#include "grid.h"
#include <iostream>
#include "colors.h"
using namespace std;

Grid::Grid()
{
    numRens = 20;
    numCols = 10;
    tamCelda = 30;
    Iniciar();
    colors = GetCellColors();
}

void Grid::Iniciar()
{
    for (int rens = 0; rens < numRens; rens++)
    {
        for (int cols = 0; cols < numCols; cols++)
        {
            grid[rens][cols] = 0;
        }
    }
}

void Grid::Imprimir()
{
    for (int rens = 0; rens < numRens; rens++)
    {
        for (int cols = 0; cols < numCols; cols++)
        {
            cout << grid[rens][cols] << " ";
        }
        cout << endl;
    }
}

void Grid::Dibujar()
{
    for (int reng = 0; reng < numRens; reng++)
    {
        for (int cols = 0; cols < numCols; cols++)
        {
            int ValCeld = grid[reng][cols];
            DrawRectangle(cols * tamCelda + 1, reng * tamCelda + 1, tamCelda - 1, tamCelda - 1, colors[ValCeld]);
        }
    }
}

bool Grid::IsCellOutSide(int reng, int col)
{
    if (reng >= 0 && reng < numRens && col >= 0 && col < numCols)
    {
        return false;
    }
    return true;
}
