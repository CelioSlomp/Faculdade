#include <iostream>
using namespace std;

class FlyBehavior
{
    // Declarando a interface (classe abstrata)
public:
    // Destrutor para a classe
    virtual ~FlyBehavior(){};
    virtual void fly() = 0;
};

class FlyWithWIngs : public FlyBehavior
{
public:
    virtual void fly()
    {
        cout << "Está batendo as asas e voando.\n";
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    virtual void fly() {}
};