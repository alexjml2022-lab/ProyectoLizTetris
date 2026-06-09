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
    j->lineasG = 0;
    j->nivel = 0;
    j->bloques = Juego_GetAllBlocks();
    j->actuBloque = Juego_GetRandomBlock(j);
    j->sigBloque = Juego_GetRandomBlock(j);
    j->musica = LoadMusicStream("musica/tetoris.MP3");
    PlayMusicStream(j->musica);
}

void Juego_Destruir(Juego *j)
{
    Grid_BorrarMat(&j->grid);
    UnloadMusicStream(j->musica);
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

    if (j->tieneBloqueHold == 1 && !j->gameOver)
    {
        if (j->bloqueHold.id == 3)
        {
            Bloque_Dibujar(&j->bloqueHold, 255, 470);
        }
        else if (j->bloqueHold.id == 4)
        {
            Bloque_Dibujar(&j->bloqueHold, 255, 450);
        }
        else
        {
            Bloque_Dibujar(&j->bloqueHold, 270, 465);
        }
    }
}
// NUEVA FUNCIÓN nos servirá para obtener un bloque completamente limpio y centrado usando su id sin quitar el que estaba guardado en el hold
Bloque Juego_ObtenerBloqueGay(int id)
{
    switch (id)
    {
    case 1:
        return CrearLBloque();
    case 2:
        return CrearJBloque();
    case 3:
        return CrearIBloque();
    case 4:
        return CrearOBloque();
    case 5:
        return CrearSBloque();
    case 6:
        return CrearTBloque();
    case 7:
        return CrearZBloque();
    default:
        return CrearLBloque();
    }
}
//
void Juego_Hold(Juego *j)
{

    // Si ya usó el hold con la pieza actual o el juego terminó, no hacer nada
    if (j->gameOver || j->hold == 1)
    {
        return;
    }

    if (!j->tieneBloqueHold)
    {
        // CASO: El está vacío.
        j->bloqueHold = Juego_ObtenerBloqueGay(j->actuBloque.id);

        j->actuBloque = j->sigBloque;

        j->sigBloque = Juego_GetRandomBlock(j); // hacemos otro bloque

        j->tieneBloqueHold = true; // se llena el hold
    }
    else
    {
        j->hold = 0;

        // CASO: Ya había un bloque entonces los intercambiamos
        int idActual = j->actuBloque.id;

        j->actuBloque = Juego_ObtenerBloqueGay(j->bloqueHold.id);

        j->bloqueHold = Juego_ObtenerBloqueGay(idActual);
    }
    j->hold = 1;
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
    case KEY_SPACE:
        Juego_HardDrop(j);
        break;
    case KEY_LEFT_SHIFT:
        Juego_Hold(j);
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
    j->lineasG += lineas;

    j->nivel = j->lineasG / 10;
    if (lineas > 0)
    {
        if (lineas == oneL)
            j->puntaje += 100;
        else if (lineas == twoL)
            j->puntaje += 300;
        else if (lineas >= threeL)
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
            j->hold = 0;
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
    j->lineasG = 0;
    j->nivel = 0;
    j->hold = 0;
    j->tieneBloqueHold = false;
}

double Juego_Niveles(Juego *j)
{
    double velocidad = 0.5 - (j->nivel * 0.05);
    if (velocidad < 0.05)
    {
        velocidad = 0.05;
    }
    return velocidad;
}

void Juego_HardDrop(Juego *j)
{
    if (!j->gameOver)
    {
        while (!Juego_IsBlockOutSide(j) && Juego_coliBloque(j))
        {
            Bloque_Mover(&j->actuBloque, 1, 0);
        }
        Bloque_Mover(&j->actuBloque, -1, 0);
        Juego_TerryBlo(j);
    }
}
