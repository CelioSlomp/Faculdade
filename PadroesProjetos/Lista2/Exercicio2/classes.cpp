#include <iostream>
#include "interfaces.h"
#include <vector>

using namespace std;

class Notificador
{
public:
    vector<Observer *> observers;

    virtual void enviarNotificacao(vector<Observer *> obser, string notif)
    {
        this->observers = obser;
        for (int i = 0; i < observers.size(); i++)
        {
            observers.at(i)->update();
        }
    }
};

class Usuario : public Observer
{
public:
    string nome;

    Usuario(string nom)
    {
        this->nome = nom;
    }

    virtual void update()
    {
        cout << "Usuario Notificado\n";
    }
};

class Produto
{
public:
    string nome;
    double preco;

    Produto(string nom, double prec)
    {
        this->nome = nom;
        this->preco = prec;
    }
};

class Loja : public Subject
{
public:
    vector<Produto *> produtos = {};
    vector<Observer *> observers = {};
    Notificador *notificador = new Notificador();

    virtual void registerObserver(Observer *algumObserver)
    {
        this->observers.push_back(algumObserver);
    }

    virtual void removeObserver(Observer *algumObserver)
    {
        for (auto i = observers.begin(); i != observers.end(); i++)
        {
            if (*i == algumObserver)
            {
                observers.erase(i);
                break;
            }
        }
    }

    virtual void notifyObservers()
    {
        this->notificador->enviarNotificacao(observers, "Loja atualizada");
    }

    virtual void adicionarProduto(Produto *prod)
    {
        produtos.push_back(prod);
        this->notifyObservers();
    }

    virtual void atualizarProduto(Produto *prod, double prec)
    {
        for (int i = 0; i < produtos.size(); i++)
        {
            if (produtos.at(i) == prod)
            {
                produtos.at(i)->preco = prec;
            }
        }
        this->notifyObservers();
    }
};