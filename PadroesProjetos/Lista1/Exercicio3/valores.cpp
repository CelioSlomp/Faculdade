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
    virtual double definirValor()
    {
        int qtdeCom = this->comodos * 1000;
        if (localizacao == 'A')
        {
            return espaco * 3000 + qtdeCom;
        }
        else if (localizacao == 'B')
        {
            return espaco * 1000 + qtdeCom;
        }
        return espaco * 500 + qtdeCom;
    }
};

class DefinirValorSemEdificacao : public DefinirValorComportamento
{
private:
    double espaco;
    char localizacao;
    virtual double definirValor()
    {
        if (localizacao == 'A')
        {
            return espaco * 1500;
        }
        else if (localizacao == 'B')
        {
            return espaco * 750;
        }
        return espaco * 200;
    }

public:
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
        return espaco;
    }

    char getLocalizacao()
    {
        return localizacao;
    }
};