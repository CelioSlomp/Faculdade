#include <iostream>
using namespace std;

class Imovel
{
private:
    int comodos;
    double espaco;
    char localizacao;

public:
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
};

class Casa : public Imovel
{
public:
    Casa(char loc, double esp, int com)
    {
        setComodos(com);
        setLocalizacao(loc);
        setEspaco(esp);
    }
};

class Apartamento : public Imovel
{
};

class Terreno : public Imovel
{
};