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
    Color neruGrey;
    Color neruYellow;
    Color neruOrange;
    Color neruCremita;
    Color neruLiteGrey;
    Color mikuFiusha;
    Color mikuDarkCyan;
    Color mikuCyan;

    return {neruGrey,
            neruYellow,
            neruOrange,
            neruCremita,
            neruLiteGrey,
            mikuFiusha,
            mikuDarkCyan,
            mikuCyan};
}