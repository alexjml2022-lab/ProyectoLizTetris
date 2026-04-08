#include "grid.h"
#include <iostream>
using namespace std;

Grid::Grid()
{
    numRens = 20;
    numCols = 10;
    tamCelda = 30;
    Iniciar();
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