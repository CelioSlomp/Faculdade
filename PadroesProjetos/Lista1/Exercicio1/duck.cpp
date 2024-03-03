#include <iostream>
using namespace std;

#include "quack.cpp"
#include "fly.cpp"

class Duck
{
public:
    FlyBehavior *flyBehavior;
    QuackBehavior *quackBehavior;

    virtual void display() = 0;

    void swim()
    {
        cout << "Está nadando\n";
    }

    void performQuack()
    {
        quackBehavior->quack();
    }

    void performFly()
    {
        flyBehavior->fly();
    }

    void setFlyBehavior(FlyBehavior *fly)
    {
        flyBehavior = fly;
    }

    void setQuackBehavior(QuackBehavior *quack)
    {
        quackBehavior = quack;
    }
};

class MallardDuck : public Duck
{
public:
    void display()
    {
        cout << "Eu sou o pato Mallard (?)\n";
    }

    MallardDuck()
    {
        setFlyBehavior(new FlyWithWIngs());
        setQuackBehavior(new Quack());
    }
};

class RedHeadDuck : public Duck
{
public:
    void display()
    {
        cout << "Eu sou o pato de cabeça vermelha\n";
    }

    RedHeadDuck()
    {
        setFlyBehavior(new FlyWithWIngs());
        setQuackBehavior(new Quack());
    }
};

class RubberDuck : public Duck
{
public:
    void display()
    {
        cout << "Eu sou o pato de borracha\n";
    }

    RubberDuck()
    {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new Squeak());
    }
};

class DecoyDuck : public Duck
{
public:
    void display()
    {
        cout << "Eu não faço nada\n";
    }

    DecoyDuck()
    {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new MuteQuack());
    }
};