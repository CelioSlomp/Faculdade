#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Window *janela = NULL;
SDL_Renderer *renderizador = NULL;
class RenderTela
{
    // Author: Celio Ludwig Slomp
    // Ultima modif.: 9/12/22
    // Cria todo o escopo da classe principal do SDL
public:
    SDL_Surface *tela = NULL;
    RenderTela(const char *titulo, int t_x, int t_y);
    SDL_Texture *carregarTextura(const char *caminhoArq);
    void destruirTela();
    void limparTela();
    void display();
    SDL_Renderer *getRender();
    SDL_Window *getJanela();

private:
    SDL_Window *janela;
    SDL_Renderer *renderizador;
};