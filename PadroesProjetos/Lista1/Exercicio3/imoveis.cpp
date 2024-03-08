#include <iostream>
using namespace std;
#include "valores.cpp"

class Imovel
{
private:
    int comodos;
    double espaco;
    char localizacao;

public:
    DefinirValorComportamento *definirValor;

    Imovel() : comodos(0), espaco(0.0), localizacao(' ') {}

    Imovel(char loc, double esp, int com)
    {
        this->comodos = com;
        this->espaco = esp;
        this->localizacao = loc;
    }

    void setComodos(int com)
    {
        this->comodos = com;
    }

    void setEspaco(double esp)
    {
        this->espaco = esp;
    }

    void setLocalizacao(char loc)
    {
        this->localizacao = loc;
    }

    void getComodos()
    {
        cout << comodos;
    }

    void getValor()
    {
        cout << definirValor->definirValor() << "\n";
    }
};

class Casa : public Imovel
{
public:
    Casa(char loc, double esp, int com)
    {
        this->setComodos(com);
        this->setLocalizacao(loc);
        this->setEspaco(esp);
        this->definirValor = new DefinirValorComEdificacao(loc, esp, com);
    }
};

class Apartamento : public Imovel
{
public:
    Apartamento(char loc, double esp, int com)
    {
        this->setComodos(com);
        this->setLocalizacao(loc);
        this->setEspaco(esp);
        this->definirValor = new DefinirValorComEdificacao(loc, esp, com);
    }
};

class Terreno : public Imovel
{
public:
    Terreno(char loc, double esp)
    {
        this->setComodos(0);
        this->setLocalizacao(loc);
        this->setEspaco(esp);
        this->definirValor = new DefinirValorSemEdificacao(loc, esp);
    }
};