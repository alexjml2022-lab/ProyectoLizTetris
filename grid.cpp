#include "grid.h"
#include "colors.h"
#include <iostream>
using namespace std;
using namespace MikuColores;
using namespace NeruColores;

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
vector<Color> Grid::GetCellColors()
{
    Color neruGrey = {69, 70, 65, 255};
    Color neruYellow = {242, 188, 87, 255};
    Color neruOrange = {217, 146, 59, 255};
    Color neruCremita = {242, 196, 155, 255};
    Color neruLiteGrey = {158, 152, 140, 255};
    Color mikuCyan = {134, 206, 203, 255};
    Color mikuDarkCyan = {19, 122, 127, 255};
    Color mikuFiusha = {225, 40, 133, 255};

    return {
        neruGrey,
        mikuFiusha,
        neruYellow,
        mikuDarkCyan,
        neruOrange,
        mikuCyan,
        neruCremita,
        neruLiteGrey,
    };
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