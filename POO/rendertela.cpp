// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
// #include <SDL2/SDL_image.h>
// #include <iostream>

#include "RenderTela.h"

RenderTela::RenderTela(const char *titulo, int t_x, int t_y)
{
    // Author: Celio Ludwig Slomp
    // Ultima modif.: 17/12/22

    // Construtor da classe.
    // Tenta criar a janela.
    janela = SDL_CreateWindow(titulo, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              t_x, t_y, SDL_WINDOW_SHOWN);
    if (janela == NULL)
    {
        printf("Não deu para inicializar. ERRO: ", SDL_GetError());
    } // if Janela
    else
    {
        renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    } // else janela null

    if (renderizador == NULL)
    {
        printf("Renderizador nulo. Erro: ", SDL_GetError());
    } // if renderizado null
    else
    {
        // Coloca uma cor de fundo na janela
        SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
        tela = SDL_GetWindowSurface(janela);
    } // else renderizador null
} // Rendertela

SDL_Texture *RenderTela::carregarTextura(const char *caminhoArq)
{
    // Author: Celio Ludwig Slomp
    // Ultima modif.: 8/12/22
    // Carrega a imagem que será colocada na tela
    SDL_Texture *textura = NULL;
    textura = IMG_LoadTexture(renderizador, caminhoArq);

    if (textura == NULL)
    {
        // Caso não dê para carregar a imagem, gerará uma mensagem de erro.
        printf("Não deu para carregar a textura. ERRO:", SDL_GetError());
    } // if textura null
    else
        return textura;
} // Carregar textura

void RenderTela::destruirTela()
{
    // Author: Celio Ludwig Slomp
    // Ultima modif.: 17/12/22
    // Destroi a tela o SDL
    SDL_DestroyWindow(janela);
    SDL_DestroyRenderer(renderizador);
    SDL_Quit();
} // void destruirTela

void RenderTela::limparTela()
{
    // Author: Celio Ludwig Slomp
    // Ultima modif.: 17/12/22
    // Limpa a tela da janela do SDL
    SDL_RenderClear(renderizador);
} // void limparTela

void RenderTela::display()
{
    // Author: Celio Ludwig Slomp
    // Ultima modif.: 17/12/22
    SDL_RenderPresent(renderizador);
} // void display

SDL_Renderer *RenderTela::getRender()
{
    return renderizador;
} // renderer getrender

SDL_Window *RenderTela::getJanela()
{
    return janela;
} // window getjanela