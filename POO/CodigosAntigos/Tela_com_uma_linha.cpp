#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
using namespace std;

const int largura = 640;
const int altura = 480;

// Iniciar o SDL e criar a janela.
bool init();

// Carregar mídia.
bool loadMedia();

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

SDL_Texture *loadTexture(std::string path)
{
    // The final texture
    SDL_Texture *newTexture = NULL;

    // Load image at specified path
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderizador, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        // Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

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
                // Initialize renderer color
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
    // Loading success flag
    bool successo = true;

    // Load PNG texture
    textura = loadTexture("imagem.png");
    if (textura == NULL)
    {
        printf("Failed to load texture image!\n");
        successo = false;
    }

    return successo;
}

void close()
{
    // Free loaded image
    SDL_DestroyTexture(textura);
    textura = NULL;

    // Destroy window
    SDL_DestroyRenderer(renderizador);
    SDL_DestroyWindow(janela);
    janela = NULL;
    renderizador = NULL;

    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char *args[])
{
    int y1 = altura;
    // Start up SDL and create window
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {

        // Update the surface
        SDL_UpdateWindowSurface(janela);
        // Hack to get window to stay up
        SDL_Event e;
        bool quit = false;
        // While application is running
        while (!quit)
        {
            // Handle events on queue
            while (SDL_PollEvent(&e) != 0)
            {
                if (e.type == SDL_QUIT)
                {
                    quit = true;
                }
                else if (e.type == SDL_KEYDOWN)
                {
                    // Select surfaces based on key press
                    switch (e.key.keysym.sym)
                    {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;

                    case SDLK_UP:
                        y1 -= 10;
                        break;

                    case SDLK_DOWN:
                        y1 += 10;
                        break;
                    } // switch
                }     // else if e.type
            }         // While SDL POLLEVEnt

            // Clear screen
            SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderizador);

            // Draw blue horizontal line
            //  Desenhar até encostar no circulo
            SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
            SDL_RenderDrawLine(renderizador, largura / 2, altura / 2, largura, y1);

            SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 0);
            SDL_RenderDrawPoint(renderizador, largura / 2, altura / 2);

            // Update screen
            SDL_RenderPresent(renderizador);
        } // while quit

    } // Else2

    // Libera tudo e fecha o SDL.
    close();

    return 0;
}