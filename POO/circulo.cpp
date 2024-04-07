#include <vector>
#include "Circulo.h"

Circulo::Circulo(int nx, int ny, int r,
                 vector<int> origem)
{
    x = nx;
    y = ny;
    raio = r;
    convCoord(origem);
} // Construtor

void Circulo::desenharCirculo(SDL_Renderer *renderizador,
                              int r, int g, int b, int a)
{
    // fat = fatias do circulo (+- 180 graus)
    double fat = 180;
    for (int i = 0; i < fat; i++)
    {
        SDL_SetRenderDrawColor(renderizador, r, g, b, a);
        SDL_RenderDrawPoint(renderizador, raio * cos(((double)i / fat) * 2 * M_PI) + xd,
                            raio * sin(((double)i / fat) * 2 * M_PI) + yd);
    } // for i<fat
} // void desenharCirculo

void Circulo::convCoord(vector<int> origem)
{
    xd = x + origem[0];
    yd = origem[1] + (y * (-1));
} // void convCoord

void Circulo::preencherCirculo(SDL_Renderer *renderizador,
                               int r, int g, int b, int a)
{
    double fat = 180;
    for (int j = raio; j > 0; j--)
    {
        for (int i = 0; i < fat; i++)
        {
            SDL_SetRenderDrawColor(renderizador, r, g, b, a);
            SDL_RenderDrawPoint(renderizador, j * cos(((double)i / fat) * 2 * M_PI) + xd,
                                j * sin(((double)i / fat) * 2 * M_PI) + yd);
        } // for i<fat
    }
} // void preencherCirculo

int Circulo::desX()
{
    return xd;
} // int desX

int Circulo::desY()
{
    return yd;
} // int desY