#include "rendertela.cpp"
#include "matematica.cpp"
#include "vetor.cpp"
#include "circulo.cpp"

using namespace std;

vector<int> tamanhoTela = {800, 800}; // Resolucao da tela
vector<int> origem = {tamanhoTela[0] / 2,
                      tamanhoTela[1] / 2}; // seta o ponto origem
RenderTela janelaRT("RayTracing - POO1",
                    tamanhoTela[0], tamanhoTela[1]); // Cria o objeto janela
SDL_Renderer *sdl_render = janelaRT.getRender();
bool quit = false; // se o jogo vai ser fechado ou nao
SDL_Event e;       // seta a var evento
ParteMat mat;      // Criar objeto ParteMat para facilitar na escrita
double parte = 0;  // Parte do angulo que o observador verá
double fat = 180;  // mostrar que terá 180 graus
double d_menor;    // o menor da op. segundo grau
// Objeto que será refletido
Circulo obj_ref(300, 150, 80, origem);

// Objeto luz
Circulo obj_luz(-150, 300, 15, origem);

// Objeto do observador
Circulo obj_observ(-200, -150, 5, origem);

void loop() // loop principal do codigo
{
    vector<double> inter = {};
    vector<double> vraio = {(cos(parte / fat)),
                            (sin(parte / fat))};
    // direcao do raio
    vector<double> dir_raio = mat.unitario(vraio);
    vector<int> org_raio = {obj_observ.getterX(),
                            obj_observ.getterY()};
    vector<double> dir_borda = mat.unitario({0, (double)tamanhoTela[0]});
    vector<int> org_borda = {origem[0], -origem[1]};

    // limpa a tela
    SDL_SetRenderDrawColor(sdl_render, 0xFF, 0xFF, 0xFF, 0xFF);
    janelaRT.limparTela();

    // Desenha o eixo X na tela
    SDL_SetRenderDrawColor(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(sdl_render, 0, origem[1],
                       tamanhoTela[0], origem[1]);

    // Desenha o eixo Y na tela
    SDL_SetRenderDrawColor(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(sdl_render, origem[0], 0,
                       origem[0], tamanhoTela[1]);

    // Desenha o objeto que reflete a luz
    obj_ref.desenharCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);

    // Desenha o objeto luz. Coloquei o 'desenharCirculo' antes para
    // ficar mais facil de se compreenter
    obj_luz.desenharCirculo(sdl_render, 0x00, 0x00, 0x00, 0xFF);
    obj_luz.preencherCirculo(sdl_render, 0x00, 0x00, 0x00, 0xFF);

    // Desenha o objeto observador
    obj_observ.desenharCirculo(sdl_render, 0x00, 0x00, 0x00, 0xFF);

    // calcular se tem toque
    double va = dir_raio[0];
    double vb = -dir_borda[0];
    double vc = org_borda[0] - org_raio[0];

    double vd = dir_raio[1];
    double ve = -dir_borda[1];
    double vf = org_borda[1] - org_raio[1];

    inter = mat.resolv2x2(va, vb, vc, vd, ve, vf);
    // o ponto que a reta principal vai até
    vector<int> cord = mat.convCoord({(int)(org_borda[0] + inter[1] * dir_borda[0]),
                                      (int)(org_borda[1] + inter[1] * dir_borda[1])});

    // valores para chegar a interseccao do objeto
    va = dir_raio[0] * dir_raio[0] + dir_raio[1] * dir_raio[1];
    vb = 2 * ((dir_raio[0] * (org_raio[0] - obj_ref.getterX())) +
              (dir_raio[1] * (org_raio[1] - obj_ref.getterY())));
    vc = (org_raio[0] - obj_ref.getterX()) * (org_raio[0] - obj_ref.getterX()) +
         (org_raio[1] - obj_ref.getterY()) * (org_raio[1] - obj_ref.getterY()) -
         pow(obj_ref.raio, 2);

    // cria o circulo com valores aleatorios
    Circulo c1(-100000, -100000, 10, origem);

    vector<double> d = mat.resBhask(va, vb, vc);

    if (d.size() == 1)
    {
        // coloca outros valores no circulo
        c1 = Circulo((int)(org_raio[0] + d[0] * dir_raio[0]),
                     (int)(org_raio[1] + d[0] * dir_raio[1]),
                     2, origem);
        c1.desenharCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
        c1.preencherCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);

        // cria o ponto de interseccao
        vector<double> pontoi = {org_raio[0] + d[0] * dir_raio[0],
                                 org_raio[1] + d[0] * dir_raio[1]};
        // cria o vetor normal para a reflexao
        vector<double> normal = mat.unitario({(double)pontoi[0] - obj_ref.getterX(),
                                              (double)pontoi[1] - obj_ref.getterY()});
        // calcula a reflexao
        vector<double> ref = mat.calc_reflexao(normal, dir_raio);

        // reta de reflexao
        SDL_SetRenderDrawColor(renderizador, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(sdl_render,
                           c1.desX(), c1.desY(),
                           mat.convCoord({(int)(c1.getterX() + 200 * ref[0]), 0})[0],
                           mat.convCoord({0, (int)(c1.getterY() + 200 * ref[1])})[1]);

        // desenha a reta quando ela não está encostando no objeto
        SDL_SetRenderDrawColor(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(sdl_render, obj_observ.desX(), obj_observ.desY(),
                           cord[0], cord[1]);

    } // if
    else
    {
        // cria os dois objetos circulo de interseccao
        c1 = Circulo((int)(org_raio[0] + d[1] * dir_raio[0]),
                     (int)(org_raio[1] + d[1] * dir_raio[1]),
                     2, origem);
        Circulo c2((int)(org_raio[0] + d[0] * dir_raio[0]),
                   (int)(org_raio[1] + d[0] * dir_raio[1]),
                   2, origem);
        // desenha os circulos
        c1.desenharCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
        c1.preencherCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
        c2.desenharCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
        c2.preencherCirculo(sdl_render, 0x00, 0x00, 0xFF, 0xFF);

        // separa o menor valor de bhaskara
        if (d[0] < d[1])
        {
            d_menor = d[0];
        } // if
        else
        {
            d_menor = d[1];
        } // else
        vector<double> pontoi = {org_raio[0] + d_menor * dir_raio[0],
                                 org_raio[1] + d_menor * dir_raio[1]};
        vector<double> normal = mat.unitario({(double)pontoi[0] - obj_ref.getterX(),
                                              (double)pontoi[1] - obj_ref.getterY()});
        vector<double> ref = mat.calc_reflexao(normal, dir_raio);

        // Desenha a reta de reflexao
        SDL_SetRenderDrawColor(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(sdl_render,
                           c1.desX(), c1.desY(),
                           mat.convCoord({(int)(c1.getterX() + 200 * ref[0]), 0})[0],
                           mat.convCoord({0, (int)(c1.getterY() + 200 * ref[1])})[1]);
    } // else

    // desenha a reta quando ela não está encostando no objeto
    SDL_SetRenderDrawColor(sdl_render, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(sdl_render, obj_observ.desX(), obj_observ.desY(),
                       cord[0], cord[1]);

    while (SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
            quit = true;
        else if (e.type == SDL_KEYDOWN)
        {
            // Pega as teclas apertadas
            switch (e.key.keysym.sym)
            {

            case SDLK_ESCAPE: // fechar a tela
                quit = true;
                break;

            case SDLK_UP: // levantar a reta
                parte += 1;
                break;

            case SDLK_RIGHT: // abaixar a reta
                parte -= 1;
                break;
            } // switch
        }     // else if e.type
    }         // While SDL POLLEVEnt

    // Atualizar tela
    janelaRT.display();
} // void loop

int main(int argc, char *args[])
{
    // Update the surface
    SDL_UpdateWindowSurface(janelaRT.getJanela());

    while (!quit) // roda o loop principal até 'quit' ser true
    {
        // roda a funcao principal do SDL
        loop();
    } // while quit

    // limpa tudo e fecha o SDL
    janelaRT.destruirTela();

    return 0;
} // int main
