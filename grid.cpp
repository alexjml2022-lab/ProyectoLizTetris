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
            DrawRectangle(cols * tamCelda + 11, reng * tamCelda + 11, tamCelda - 1, tamCelda - 1, colors[ValCeld]);
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

bool Grid::IsCellEmpty(int reng, int col)
{
    if (grid[reng][col] == 0)
    {
        return true;
    }
    return false;
}

int Grid::limpiarTodoRengs()
{
    int com = 0;
    for (int reng = numRens - 1; reng >= 0; reng--)
    {
        if (IsRowFull(reng))
        {
            LimpiarReng(reng);
            com++;
        }
        else if (com > 0)
        {
            MoverRengAbajo(reng, com);
        }
    }
    return com;
}

bool Grid::IsRowFull(int reng)
{
    for (int col = 0; col < numCols; col++)
    {
        if (grid[reng][col] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::LimpiarReng(int reng)
{
    for (int col = 0; col < numCols; col++)
    {
        grid[reng][col] = 0;
    }
}

void Grid::MoverRengAbajo(int reng, int numRengs)
{
    for (int col = 0; col < numCols; col++)
    {
        grid[reng + numRengs][col] = grid[reng][col];
        grid[reng][col] = 0;
    }
}
