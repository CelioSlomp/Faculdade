/*
 * Codigo antigo do main, refazendo ele para orientacao a objetos
 * e também tirar o "lixo" feito no primeiro codigo.
 */

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <math.h>
#include <vector>
using namespace std;

vector<int> tamTela = {600, 600};

vector<int> origem = {tamTela[0] / 2, tamTela[1] / 2};

double angulo = 0;
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
SDL_Texture *loadTexture(string path);

// The window renderer
SDL_Renderer *renderizador = NULL;

// Current displayed texture
SDL_Texture *textura = NULL;

vector<double> resolv2x2(double a, double b, double c, double d, double e, double f)
{
    double dx = 0;
    double dy = 0;

    double m = e * a - d * b;
    if (m == 0)
    {
        return {1};
    }
    if (a != 0)
    {
        dy = (a * f - d * c) / m;
        dx = dx = (c - b * dy) / a;
    }
    else
    {
        dx = b * f - e * a;
        dy = (c - a * dx) / b;
    }
    return {dx, dy};
}

vector<double> resBhask(double a, double b, double c)
{
    // calcula a formula de bhaskara
    // dt = delta
    double dt = pow(b, 2) - 4 * a * c;
    if (dt < 0)
        return {};
    else if (dt == 0)
        return {b / 2 * a};

    double x1 = (-b + sqrt(dt)) / (2 * a);
    double x2 = (-b - sqrt(dt)) / (2 * a);
    return {x1, x2};
}

vector<int> convCoord(vector<int> coord)
{
    // converte a coordenada  para o SDL, ja que o 0, 0 fica no
    // canto superior esquerdo
    coord[0] += origem[0];
    coord[1] = origem[1] + (coord[1] * (-1));
    return coord;
}

double moduloVetor(vector<double> vetor)
{
    // Gera o modulo de um vetor
    return sqrt(pow(vetor[0], 2) + pow(vetor[1], 2));
}

vector<double> unitario(vector<double> vetor)
{
    double modulo = moduloVetor(vetor);
    vetor[0] /= modulo;
    vetor[1] /= modulo;
    return vetor;
}

SDL_Texture *loadTexture(string path)
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
                                  tamTela[0],
                                  tamTela[1],
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
    }
    return successo;
}

bool loadMedia(string path)
{
    // Seta para retornar true
    bool successo = true;

    // Carrega a imagem
    textura = loadTexture(path.c_str());
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

SDL_Event event;
bool quit = false;

double fat = 180;
double d_menor;

vector<double> calc_reflexao(vector<double> n, vector<double> r)
{
    n = unitario(n);
    r = unitario(r);
    double tmp = n[0] * r[0] + n[1] * r[1];
    vector<double> ref = {r[0] - 2 * tmp * n[0],
                          r[1] - 2 * tmp * n[1]};
    return ref;
}

vector<int> v_camera = convCoord({-150, -150});
vector<int> v_objeto = {200, 100};
int raio_objeto = 20;
// código arrumado linha 238-240, conversão int para double -> Fábio e Luana
void loopPrincipal()
{

    // variaveis do raytracing.py
    //  olho/saída do raio
    vector<double> vraio = {(200 * cos(angulo / 120.0) * 2 * M_PI),
                            (200 * sin(angulo / 120.0) * 2 * M_PI)};
    // centro do objeto
    vector<double> dir_raio = unitario(vraio);
    vector<int> org_raio = v_camera;
    vector<double> dir_borda = unitario({0, (double)tamTela[0]});
    vector<int> org_borda = {tamTela[0] / 2, tamTela[1] / 2};

    // limpa a tela
    SDL_SetRenderDrawColor(renderizador, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderizador);
    desenharCirculo(renderizador, v_camera[0], v_camera[1], 5, 0x00, 0x00, 0xFF, 0xFF);

    desenharCirculo(renderizador, convCoord({200, 0})[0], convCoord({0, 100})[1], 20, 0x00, 0x00, 0xFF, 0xFF);
    // Desenhar a luz
    desenharCirculo(renderizador, convCoord({-100, 0})[0], convCoord({0, 200})[1], 20, 0x00, 0x00, 0xFF, 0xFF);
    // Encher o circulo
    for (int i = 20; i > 0; i--)
    {
        desenharCirculo(renderizador, convCoord({-100, 0})[0], convCoord({0, 200})[1], i, 0x00, 0x00, 0xFF, 0xFF);
    }

    /*
    vector<double> coordIni = convCoord(pontoi);
    vector<double> coordFim = convCoord({pontoi[0] + 200 * ref[0],
                                         pontoi[1] + 200 * ref[1]});
                                '         */
    SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
    /* SDL_RenderDrawLine(renderizador, coordIni[0], coordIni[1],
                       coordFim[0], coordFim[1]);
                       */

    double a = dir_raio[0];
    double b = -dir_borda[0];
    double c = org_borda[0] - org_raio[0];

    double de = dir_raio[1];
    double e = -dir_borda[1];
    double fa = org_borda[1] - org_raio[1];

    vector<double> inter = resolv2x2(a, b, c, de, e, fa);
    if (inter.size() == 2)
    {
        // cout << inter[0] << " " << inter[1] << endl;
    }
    // cout << dir_raio[0] << " " << dir_raio[1] << endl;
    // cout << "==========" << endl;
    vector<int> cord = convCoord({(int)(200 * cos(angulo / fat) * 2 * M_PI),
                                  (int)(200 * sin(angulo / fat) * 2 * M_PI)});
    // Desenha a linha
    SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderizador, v_camera[0], v_camera[1],
                       cord[0], cord[1]);
    // cout << origem[0] << " " << origem[1] << endl;
    // cout << "--------------" << endl;
    cout << cord[0] << " " << cord[1] << endl;
    cout << "aa" << endl;

    a = dir_raio[0] * dir_raio[0] + dir_raio[1] * dir_raio[1];
    b = 2 * ((dir_raio[0] * (org_raio[0] - v_objeto[0])) +
             (dir_raio[1] * (org_raio[1] - v_objeto[1])));
    c = (org_raio[0] - v_objeto[0]) * (org_raio[0] - v_objeto[0]) +
        (org_raio[1] - v_objeto[1]) * (org_raio[1] - v_objeto[1]) -
        20 * 20;

    vector<double> d = resBhask(a, b, c);
    if (d.size() == 0)
    {
        cout << "d nao tem nada" << endl;
    }
    else
    {

        if (d.size() == 1)
        {
            cout << "passou aqui" << endl;
            vector<int> bla = convCoord({(int)(org_raio[0] + d[0] * dir_raio[0]),
                                         (int)(org_raio[1] + d[0] * dir_raio[1])});

            desenharCirculo(renderizador, bla[0], bla[1], 3, 0x00, 0x00, 0xFF, 0xFF);
            // Encher o circulo
            for (int i = 3; i > 0; i--)
            {
                desenharCirculo(renderizador, bla[0], bla[1], i, 0x00, 0x00, 0xFF, 0xFF);
            }
            vector<double> pontoi = {org_raio[0] + d[0] * dir_raio[0],
                                     org_raio[1] + d[0] * dir_raio[1]};
            vector<double> normal = unitario({(double)pontoi[0] - v_objeto[0],
                                              (double)pontoi[1] - v_objeto[1]});
            vector<double> ref = calc_reflexao(normal, dir_raio);
            SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
            SDL_RenderDrawLine(renderizador, convCoord({(int)pontoi[0], (int)pontoi[1]})[0],
                               convCoord({(int)pontoi[0], (int)pontoi[1]})[1],
                               convCoord({(int)(pontoi[0] + 200 * ref[0]), 0})[0],
                               convCoord({0, (int)(pontoi[1] + 200 * ref[1])})[1]);
        }
        else
        {
            vector<int> bla = {(int)(org_raio[0] + d[0] * dir_raio[0]),
                               (int)(org_raio[1] + d[0] * dir_raio[1])};
            desenharCirculo(renderizador, bla[0], bla[1], 3, 0x00, 0x00, 0xFF, 0xFF);
            // Encher o circulo
            for (int i = 3; i > 0; i--)
            {
                desenharCirculo(renderizador, bla[0], bla[1], i, 0x00, 0x00, 0xFF, 0xFF);
            }

            bla = convCoord({(int)(org_raio[0] + d[1] * dir_raio[0]),
                             (int)(org_raio[1] + d[1] * dir_raio[1])});
            desenharCirculo(renderizador, bla[0], bla[1], 3, 0x00, 0x00, 0xFF, 0xFF);
            // Encher o circulo
            for (int i = 3; i > 0; i--)
            {
                desenharCirculo(renderizador, bla[0], bla[1], i, 0x00, 0x00, 0xFF, 0xFF);
            }

            if (d[0] < d[1])
            {
                d_menor = d[0];
            }
            else
            {
                d_menor = d[1];
            }
            vector<double> pontoi = {org_raio[0] + d_menor * dir_raio[0],
                                     org_raio[1] + d_menor * dir_raio[1]};
            vector<double> normal = unitario({(double)pontoi[0] - v_objeto[0],
                                              (double)pontoi[1] - v_objeto[1]});
            vector<double> ref = calc_reflexao(normal, dir_raio);
            SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
            SDL_RenderDrawLine(renderizador,
                               convCoord({(int)pontoi[0], (int)pontoi[1]})[0],
                               convCoord({(int)pontoi[0], (int)pontoi[1]})[1],
                               convCoord({(int)(pontoi[0] + 200 * ref[0]), 0})[0],
                               convCoord({0, (int)(pontoi[1] + 200 * ref[1])})[1]);
            cout << pontoi[0] << " " << pontoi[1] << endl;
        }
    }

    // Espera e procura por algum evento

    while (SDL_PollEvent(&event) != 0)
    {
        if (event.type == SDL_QUIT)
        {
            quit = true;
        }
        else if (event.type == SDL_KEYDOWN)
        {
            // Pega as teclar apertadas
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                quit = true;
                break;

            case SDLK_UP:
                angulo += 1;
                break;

            case SDLK_DOWN:
                angulo -= 1;
                break;
            } // switch
        }     // else if e.type
    }         // While SDL POLLEVEnt

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
