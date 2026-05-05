#pragma once

class Grid
{
public:
    Grid();
    void Iniciar();
    void Imprimir();
    int grid[20][10];

private:
    int numRens;
    int numCols;
    int tamCelda;
};