#pragma once

class Grid
{
private:
    int numRens;
    int numCols;
    int tamCelda;

public:
    Grid();
    void Iniciar();
    void Imprimir();
    int grid[20][10];
};

