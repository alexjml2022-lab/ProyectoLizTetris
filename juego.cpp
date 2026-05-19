#include "juego.h"
#include <random>

enum puntajes
{
    oneL = 1,
    twoL,
    threeL
};

Bloque CrearLBloque();
Bloque CrearJBloque();
Bloque CrearIBloque();
Bloque CrearOBloque();
Bloque CrearSBloque();
Bloque CrearTBloque();
Bloque CrearZBloque();

vector<Bloque> Juego_GetAllBlocks()
{
    return {CrearLBloque(), CrearJBloque(), CrearIBloque(), CrearOBloque(), CrearSBloque(), CrearTBloque(), CrearZBloque()};
}

Bloque Juego_GetRandomBlock(Juego *j)
{
    if (j->bloques.empty())
    {
        j->bloques = Juego_GetAllBlocks();
    }
    int randIndex = rand() % j->bloques.size();
    Bloque b = j->bloques[randIndex];
    j->bloques.erase(j->bloques.begin() + randIndex);
    return b;
}

void Juego_Inicializar(Juego *j)
{
    Grid_Iniciar(&j->grid);
    j->gameOver = false;
    j->puntaje = 0;
    j->bloques = Juego_GetAllBlocks();
    j->actuBloque = Juego_GetRandomBlock(j);
    j->sigBloque = Juego_GetRandomBlock(j);

    InitAudioDevice();
    j->musica = LoadMusicStream("musica/tetoris.MP3");
    PlayMusicStream(j->musica);
    j->rotateSound = LoadSound("");
    j->clearSound = LoadSound("");
}

void Juego_Destruir(Juego *j)
{
    Grid_BorrarMat(&j->grid);
    UnloadSound(j->clearSound);
    UnloadSound(j->rotateSound);
    UnloadMusicStream(j->musica);
    CloseAudioDevice();
}

void Juego_Dibujar(Juego *j)
{
    Grid_Dibujar(&j->grid);
    Bloque_Dibujar(&j->actuBloque, 11, 11);

    if (j->sigBloque.id == 3)
    {
        Bloque_Dibujar(&j->sigBloque, 255, 255);
    }
    else if (j->sigBloque.id == 4)
    {
        Bloque_Dibujar(&j->sigBloque, 255, 235);
    }
    else
    {
        Bloque_Dibujar(&j->sigBloque, 270, 240);
    }
}

void Juego_HandleInput(Juego *j)
{
    int key = GetKeyPressed();
    if (j->gameOver)
    {
        j->gameOver = false;
    }
    switch (key)
    {
    case KEY_LEFT:
        Juego_MoverIzquierda(j);
        break;
    case KEY_RIGHT:
        Juego_MoverDerecha(j);
        break;
    case KEY_DOWN:
        Juego_MoverAbajo(j);
        j->puntaje++;
        break;
    case KEY_UP:
        Juego_RotarBloque(j);
        break;
    }
}

void Juego_MoverIzquierda(Juego *j)
{
    if (!j->gameOver)
    {
        Bloque_Mover(&j->actuBloque, 0, -1);
        if (Juego_IsBlockOutSide(j) || !Juego_coliBloque(j))
        {
            Bloque_Mover(&j->actuBloque, 0, 1);
        }
    }
}

void Juego_MoverDerecha(Juego *j)
{
    if (!j->gameOver)
    {
        Bloque_Mover(&j->actuBloque, 0, 1);
        if (Juego_IsBlockOutSide(j) || !Juego_coliBloque(j))
        {
            Bloque_Mover(&j->actuBloque, 0, -1);
        }
    }
}

void Juego_MoverAbajo(Juego *j)
{
    if (!j->gameOver)
    {
        Bloque_Mover(&j->actuBloque, 1, 0);
        if (Juego_IsBlockOutSide(j) || !Juego_coliBloque(j))
        {
            Bloque_Mover(&j->actuBloque, -1, 0);
            Juego_TerryBlo(j);
        }
    }
}

bool Juego_IsBlockOutSide(Juego *j)
{
    vector<Posicion> tiles = Bloque_GetCellPosicion(&j->actuBloque);
    for (Posicion item : tiles)
    {
        if (Grid_IsCellOutSide(&j->grid, item.reng, item.col))
        {
            return true;
        }
    }
    return false;
}

void Juego_RotarBloque(Juego *j)
{
    if (!j->gameOver)
    {
        Bloque_Rotar(&j->actuBloque);
        if (Juego_IsBlockOutSide(j) || !Juego_coliBloque(j))
        {
            Bloque_KyaRotacion(&j->actuBloque);
        }
        else
        {
            PlaySound(j->rotateSound);
        }
    }
}

void Juego_TerryBlo(Juego *j)
{
    vector<Posicion> tiles = Bloque_GetCellPosicion(&j->actuBloque);
    for (Posicion item : tiles)
    {
        j->grid.grid[item.reng][item.col] = j->actuBloque.id;
    }
    j->actuBloque = j->sigBloque;
    if (!Juego_coliBloque(j))
    {
        j->gameOver = true;
    }
    j->sigBloque = Juego_GetRandomBlock(j);

    int lineas = Grid_LimpiarTodoRengs(&j->grid);
    if (lineas > 0)
    {
        PlaySound(j->clearSound);
        if (lineas == oneL)
            j->puntaje += 100;
        else if (lineas == twoL)
            j->puntaje += 300;
        else if (lineas == threeL)
            j->puntaje += 500;
    }
}

bool Juego_coliBloque(Juego *j)
{
    vector<Posicion> tiles = Bloque_GetCellPosicion(&j->actuBloque);
    for (Posicion item : tiles)
    {
        if (Grid_IsCellEmpty(&j->grid, item.reng, item.col) == false)
        {
            return false;
        }
    }
    return true;
}

void Juego_Reset(Juego *j)
{
    Grid_BorrarMat(&j->grid);
    Grid_Iniciar(&j->grid);
    j->bloques = Juego_GetAllBlocks();
    j->actuBloque = Juego_GetRandomBlock(j);
    j->sigBloque = Juego_GetRandomBlock(j);
    j->puntaje = 0;
}