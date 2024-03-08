#include <iostream>
using namespace std;

class DefinirValorComportamento
{
public:
    virtual ~DefinirValorComportamento(){};
    virtual double definirValor() = 0;
};

class DefinirValorComEdificacao : public DefinirValorComportamento
{
private:
    int comodos;
    double espaco;
    char localizacao;

public:
    DefinirValorComEdificacao(char loc, double esp, int com)
    {
        this->comodos = com;
        this->espaco = esp;
        this->localizacao = loc;
    }
    virtual double definirValor()
    {
        int qtdeCom = this->comodos * 1000;
        if (this->localizacao == 'A')
        {
            return this->espaco * 3000 + qtdeCom;
        }
        else if (this->localizacao == 'B')
        {
            return this->espaco * 1000 + qtdeCom;
        }
        return this->espaco * 500 + qtdeCom;
    }
};

class DefinirValorSemEdificacao : public DefinirValorComportamento
{
private:
    double espaco;
    char localizacao;

public:
    DefinirValorSemEdificacao(char loc, double esp)
    {
        this->espaco = esp;
        this->localizacao = loc;
    }

    virtual double definirValor()
    {
        if (this->localizacao == 'A')
        {
            return this->espaco * 1500;
        }
        else if (this->localizacao == 'B')
        {
            return this->espaco * 750;
        }
        return this->espaco * 200;
    }

    void setEspaco(double esp)
    {
        this->espaco = esp;
    }

    void setLocalizacao(char loc)
    {
        this->localizacao = loc;
    }

    double getEspaco()
    {
        return this->espaco;
    }

    char getLocalizacao()
    {
        return this->localizacao;
    }
};