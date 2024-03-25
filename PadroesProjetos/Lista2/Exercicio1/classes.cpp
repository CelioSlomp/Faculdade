#include <iostream>
#include <vector>
using namespace std;

#include "interfaces.h"

class WeatherData : public Subject
{
public:
    vector<Observer *> *objetos = {};
    virtual void registerObserver(Observer *algumDisplay)
    {
        objetos->push_back(algumDisplay);
    }
    virtual void removeObserver() {}
    virtual void notifyObservers() {}
};

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    string nome;

    CurrentConditionsDisplay(string nome)
    {
        this->nome = nome;
    }

    virtual void update()
    {
        cout << "CurrentConditionsDisplay atualizou\n";
    }

    virtual void display()
    {
        cout << "As medidas atuais são de XX\n";
    }
};

class StatisticsDisplay : public Observer, public DisplayElement
{
public:
    string nome;

    StatisticsDisplay(string nome)
    {
        this->nome = nome;
    }

    virtual void update()
    {
        cout << "StatisticDisplay atualizou\n";
    }

    virtual void display()
    {
        cout << "As Estatisticas atuais são de YY\n";
    }
};
