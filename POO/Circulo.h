#include <SDL2/SDL.h>

#include "figgeo.cpp"

using namespace std;

class Circulo : public FigGeo
{
private:
    int xd;
    int yd;

public:
    int raio;
    Circulo(int x, int y, int raio, vector<int> origem);
    void convCoord(vector<int> origem);
    void desenharCirculo(SDL_Renderer *renderizador,
                         int r, int g, int b, int a);
    void preencherCirculo(SDL_Renderer *renderizador,
                          int r, int g, int b, int a);
    int desX();
    int desY();
};