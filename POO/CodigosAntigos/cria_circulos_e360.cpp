#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <math.h>
using namespace std;

const int largura = 600;
const int altura = 600;

const int xorigem = largura / 2;
const int yorigem = altura / 2;

// Iniciar o SDL e criar a janela.
bool init();

// Carregar mídia.
bool loadMedia();

SDL_Event e;
bool quit = false;

double f = 180;
double t = 0;
double ra = 250;

// Libera e fecha SDL.
void close();

// A janela que iremos abrir.
SDL_Window *janela = NULL;

// A tela que será reenderizada.
SDL_Surface *tela = NULL;

// A imagem que iremos abrir.
SDL_Surface *imagem = NULL;

// Loads individual image as texture
SDL_Texture *loadTexture(std::string path);

// The window renderer
SDL_Renderer *renderizador = NULL;

// Current displayed texture
SDL_Texture *textura = NULL;

int converteX(int x)
{
    // Gera o X de acordo com a origem
    return xorigem + x;
}

int converteY(int y)
{
    // Gera o Y de acordo com o ponto origem e inverte o valor
    // já que no SDL o 0 começa em cima e não em baixo

    return yorigem + (y * (-1));
}

double moduloVetor(double vetor[2])
{
    // Gera o modulo de um vetor
    return sqrt(pow(vetor[0], 2) + pow(vetor[1], 2));
}

double *unitario(double vetor[2])
{
    double modulo = moduloVetor(vetor);
    vetor[0] = vetor[0] / modulo;
    vetor[1] = vetor[1] / modulo;
    return vetor;
}

SDL_Texture *loadTexture(std::string path)
{
    // A nova textura
    SDL_Texture *newTexture = NULL;

    // Pega o arquivo
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Não deu para carregar a imagem %s! ERRO: %s\n", path.c_str(), IMG_GetError());
    } // If
    else
    {
        // Coloca a imagem na tela
        newTexture = SDL_CreateTextureFromSurface(renderizador, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Não deu para criar a imagem %s! ERRO: %s\n", path.c_str(), IMG_GetError());
        }

        // Libera a imagem antiga.
        SDL_FreeSurface(loadedSurface);
    } // Else

    return newTexture;
}

bool init()
{
    // Carregar que deu certo
    bool successo = true;

    // Inicializar o SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Não deu para iniciar o SDL. ERRO: %s\n", SDL_GetError());
        successo = false;
    }
    else
    {
        // Criar janela
        janela = SDL_CreateWindow("Janela SDL",
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  largura,
                                  altura,
                                  SDL_WINDOW_SHOWN);
        if (janela == NULL)
        {
            printf("Janela nao foi criada. ERRO: %s\n", SDL_GetError());
            successo = false;
        }

        else
        {
            renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
            if (renderizador == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                successo = false;
            }
            else
            {
                // Coloca uma cor de fundo na janela
                SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
                // Pega a tela que sera colocada na janela.
                tela = SDL_GetWindowSurface(janela);
            }
        }
        return successo;
    }
}

bool loadMedia()
{
    // Seta para retornar true
    bool successo = true;

    // Carrega a imagem
    textura = loadTexture("imagem.png");
    if (textura == NULL)
    {
        cout << "Não deu para carregar a imagem.";
        successo = false;
    }

    return successo;
}

void close()
{
    // Libera a textura
    SDL_DestroyTexture(textura);
    textura = NULL;

    // Fecha a janela
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    janela = NULL;
    renderizador = NULL;

    // Fecha tudo.
    IMG_Quit();
    SDL_Quit();
}

void desenharCirculo(SDL_Renderer *rend, int centX, int centY,
                     double raio, int r, int g, int b, int a)
{
    // fat = fatias do circulo (+- 180 graus)
    double fat = 180;
    for (int i = 0; i < fat; i++)
    {
        SDL_SetRenderDrawColor(rend, r, g, b, a);
        SDL_RenderDrawPoint(rend, raio * cos(((double)i / fat) * 2 * M_PI) + centX,
                            raio * sin(((double)i / fat) * 2 * M_PI) + centY);
    }
}

void loopPrincipal()
{
    // Espera e procura por algum evento
    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            // Pega as teclar apertadas
            switch (e.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                quit = true;
                break;

            case SDLK_UP:
                t -= 1;
                break;

            case SDLK_DOWN:
                t += 1;
                break;
            } // switch
        }     // else if e.type
    }         // While SDL POLLEVEnt

    // limpa a tela
    SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderizador);
    desenharCirculo(renderizador, converteX(0), converteY(0), 5, 0x00, 0x00, 0xFF, 0xFF);

    desenharCirculo(renderizador, converteX(200), converteY(100), 20, 0x00, 0x00, 0xFF, 0xFF);
    // Desenhar a luz
    desenharCirculo(renderizador, converteX(-100), converteY(200), 20, 0x00, 0x00, 0xFF, 0xFF);
    // Encher o circulo
    for (int i = 20; i > 0; i--)
    {
        desenharCirculo(renderizador, converteX(-100), converteY(200), i, 0x00, 0x00, 0xFF, 0xFF);
    }

    // Desenha a linha
    SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderizador, xorigem, yorigem,
                       ra * cos((t / f) * 2 * M_PI) + xorigem,
                       ra * sin((t / f) * 2 * M_PI) + yorigem);

    // Atualizar tela
    SDL_RenderPresent(renderizador);
}

int main(int argc, char *args[])
{
    // Inicia o SDL e a janela
    if (!init())
    {
        cout << "Não deu para inicializar.\n";
    }
    else
    {

        // Update the surface
        SDL_UpdateWindowSurface(janela);

        // Enquanto que a aplicação não é fechada
        while (!quit)
        {
            loopPrincipal();
        } // while quit
    }     // Else

    // Libera tudo e fecha o SDL.
    close();

    return 0;
}