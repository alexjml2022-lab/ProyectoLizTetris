#include "juego.h"
#include <random>
using namespace std;

enum puntajes
{
    oneL = 1,
    twoL,
    threeL
};

Juego::Juego() : grid()
{
    // Al poner ': grid()' arriba, ya se inicializa correctamente.
    // No necesitas poner 'grid = Grid()' aquí adentro.
    gameOver = false;
    puntaje = 0;
    bloques = GetAllBloqcks();
    actuBloque = GetRandomBlock();
    sigBloque = GetRandomBlock();
    gameOver = false;
    puntaje = 0;
    InitAudioDevice();
    musica = LoadMusicStream("musica/tetoris.MP3");
    PlayMusicStream(musica);
    rotateSound = LoadSound("");
    clearSound = LoadSound("");
}

Juego::~Juego()
{
    UnloadSound(clearSound);
    UnloadSound(rotateSound);
    UnloadMusicStream(musica);
    CloseAudioDevice();
}

Bloque Juego::GetRandomBlock()
{
    if (bloques.empty())
    {
        bloques = GetAllBloqcks();
    }
    int randIndex = rand() % bloques.size();
    Bloque bloque = bloques[randIndex];
    bloques.erase(bloques.begin() + randIndex);
    return bloque;
}

vector<Bloque> Juego::GetAllBloqcks()
{
    return {IBloque(), JBloque(), LBloque(), OBloque(), SBloque(), ZBloque(), TBloque()};
}

void Juego::Dibujar()
{
    grid.Dibujar();
    actuBloque.Dibujar(11, 11);
    sigBloque.Dibujar(270, 270);
}

void Juego::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }

    switch (keyPressed)
    {
    case KEY_LEFT:
        MoverIzquierda();
        break;

    case KEY_RIGHT:
        MoverDerecha();
        break;

    case KEY_DOWN:
        MoverAbajo();
        FPuntaje(0, 1);
        break;

    case KEY_UP:
        RotarBloque();
        break;
    }
}

void Juego::MoverIzquierda()
{
    if (!gameOver)
    {
        actuBloque.Mover(0, -1);
        if (IsBlockOutSide() || coliBloque() == false)
        {
            actuBloque.Mover(0, 1);
        }
    }
}
void Juego::MoverDerecha()
{
    if (!gameOver)
    {
        actuBloque.Mover(0, 1);
        if (IsBlockOutSide() || coliBloque() == false)
        {
            actuBloque.Mover(0, -1);
        }
    }
}
void Juego::MoverAbajo()
{
    if (!gameOver)
    {
        actuBloque.Mover(1, 0);
        if (IsBlockOutSide() || coliBloque() == false)
        {
            actuBloque.Mover(-1, 0);
            TerryBlo();
        }
    }
}

bool Juego::IsBlockOutSide()
{
    vector<Posicion> tiles = actuBloque.GetCellPosicion();
    for (Posicion item : tiles)
    {
        if (grid.IsCellOutSide(item.reng, item.col))
        {
            return true;
        }
    }
    return false;
}

void Juego::RotarBloque()
{
    if (!gameOver)
    {
        actuBloque.Rotar();
        if (IsBlockOutSide() || coliBloque() == false)
        {
            actuBloque.KyaRotacion();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

void Juego::TerryBlo()
{
    vector<Posicion> tiles = actuBloque.GetCellPosicion();
    for (Posicion item : tiles)
    {
        grid.grid[item.reng][item.col] = actuBloque.id;
    }
    actuBloque = sigBloque;
    if (coliBloque() == false)
    {
        gameOver = true;
    }

    sigBloque = GetRandomBlock();
    int lineas = grid.limpiarTodoRengs();
    if (lineas > 0)
    {
        PlaySound(clearSound);
        FPuntaje(lineas, 0);
    }
}

bool Juego::coliBloque()
{
    vector<Posicion> tiles = actuBloque.GetCellPosicion();
    for (Posicion item : tiles)
    {
        if (grid.IsCellEmpty(item.reng, item.col) == false)
            return false;
    }
    return true;
}

void Juego::Reset()
{
    grid.Iniciar();
    bloques = GetAllBloqcks();
    actuBloque = GetRandomBlock();
    sigBloque = GetRandomBlock();
    puntaje = 0;
}

void Juego::FPuntaje(int lineas, int puntosMover)
{
    switch (lineas)
    {
    case oneL:
        puntaje += 100;
        break;

    case twoL:
        puntaje += 300;
        break;

    case threeL:
        puntaje += 500;
        break;
    default:
        break;
    }
    puntaje += puntosMover;
}
