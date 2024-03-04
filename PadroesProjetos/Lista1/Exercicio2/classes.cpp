#include <iostream>
using namespace std;

class UnidadePotencia
{
public:
    virtual ~UnidadePotencia(){};
    virtual void display() = 0;
};

class Motor : public UnidadePotencia
{
public:
    virtual void display()
    {
        cout << "Este barco se movimenta usando motor\n";
    }
};

class Remos : public UnidadePotencia
{
public:
    virtual void display()
    {
        cout << "Este barco se movimenta usando remos\n";
    }
};

class Velas : public UnidadePotencia
{
public:
    virtual void display()
    {
        cout << "Este barco se movimenta usando velas\n";
    }
};

class Barco
{
public:
    UnidadePotencia *unidadePotencia;

    void display()
    {
        unidadePotencia->display();
    }

    void setUnidadePotencia(UnidadePotencia *UnidPot)
    {
        unidadePotencia = UnidPot;
    }
};

class Iate : public Barco
{
public:
    Iate()
    {
        setUnidadePotencia(new Motor());
    }
};

class Bateira : public Barco
{
public:
    Bateira()
    {
        setUnidadePotencia(new Motor());
    }
};

class Canoa : public Barco
{
public:
    Canoa()
    {
        setUnidadePotencia(new Remos());
    }
};

class Jangada : public Barco
{
public:
    Jangada()
    {
        setUnidadePotencia(new Remos());
    }
};

class BarcoVelas : public Barco
{
public:
    BarcoVelas()
    {
        setUnidadePotencia(new Velas());
    }
};