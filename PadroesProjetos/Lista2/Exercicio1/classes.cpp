#include <iostream>
#include <vector>
using namespace std;

#include "interfaces.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    string nome;
    double temperatura;
    double humidade;
    double pressao;

    CurrentConditionsDisplay(string nom)
    {
        this->nome = nom;
    }

    virtual void update()
    {
        this->temperatura = atualizaTemperatura(4);
        this->humidade = atualizaHumidade(5);
        this->pressao = atualizaPressao(6);
        cout << "CurrentConditionsDisplay atualizou\n";
    }

    virtual void display()
    {
        cout << "A temperatura atual é de " << this->temperatura << "\n";
        cout << "A humidade atual é de " << this->humidade << "\n";
        cout << "A pressao atual é de " << this->pressao << "\n";
    }

    virtual double getTemperatura()
    {
        return this->temperatura;
    }
    virtual double getHumidade()
    {
        return this->humidade;
    }
    virtual double getPressao()
    {
        return this->pressao;
    }

    virtual double atualizaTemperatura(double temp)
    {
        this->temperatura = temp;
    }
    virtual double atualizaHumidade(double humid)
    {
        this->humidade = humid;
    }
    virtual double atualizaPressao(double press)
    {
        this->pressao = press;
    }
};

class WeatherData : public Subject
{
public:
    vector<Observer *> objetos = {};
    CurrentConditionsDisplay *tempo = new CurrentConditionsDisplay("DadosTempo");

    virtual void registerObserver(Observer *algumDisplay)
    {
        objetos.push_back(algumDisplay);
    }

    virtual void removeObserver(Observer *algumDisplay)
    {
        for (auto i = objetos.begin(); i != objetos.end(); i++)
        {
            if (*i == algumDisplay)
            {
                objetos.erase(i);
                break;
            }
        }
    }

    virtual void notifyObservers()
    {
        for (int i = 0; i < objetos.size(); i++)
        {
            objetos.at(i)->update();
        }
    }

    virtual double getTemperature()
    {
        tempo->update();
        return tempo->getTemperatura();
    }
    virtual double getHumidity()
    {
        tempo->update();
        return tempo->getHumidade();
    }
    virtual double getPressure()
    {
        tempo->update();
        return tempo->getPressao();
    }

    virtual double measurementsChanged()
    {
        notifyObservers();
    }
};

class StatisticsDisplay : public Observer, public DisplayElement
{
public:
    string nome;
    vector<double> ultimas24h = {};

    StatisticsDisplay(string nom)
    {
        this->nome = nom;
    }

    virtual void update()
    {
        if (ultimas24h.size() > 24)
            ultimas24h.erase(ultimas24h.begin()); // Remove o primeiro elemento caso passe de 24h

        ultimas24h.push_back(updateTemp(9));

        cout << "StatisticDisplay atualizou\n";
    }

    virtual double updateTemp(double temp)
    {
        return temp;
    }

    virtual void display()
    {
        double max = -9999; // Valor baixo para ter certeza que vai ser substituido
        double min = 9999;  // Valor alto para ter certeza que vai ser substituido
        double media = 0;

        for (int i = 0; i < ultimas24h.size(); i++)
        {
            if (max < i)
                max = i;
            if (min > i)
                min = i;
            media += i;
        }

        cout << "A temperatura maxima é de " << max << "\n";
        cout << "A temperatura minima é de " << min << "\n";
        cout << "A temperatura media é de " << media / (ultimas24h.size()) << "\n";
    }
};

class ThirdPartyDisplay : public Observer, public DisplayElement
{
public:
    string nome;
    ThirdPartyDisplay(string nom)
    {
        this->nome = nom;
    }

    string climaAtual;
    virtual void update()
    {
        this->climaAtual = novoClima("Algum Clima");
    }

    string novoClima(string clima)
    {
        return clima;
    }

    virtual void display()
    {
        cout << "O clima atual é de: " << climaAtual << "\n";
    }
};

class ForecastDisplay : public Observer, public DisplayElement
{
public:
    string nome;
    ThirdPartyDisplay *barometro = new ThirdPartyDisplay("barometro");

    ForecastDisplay(string nom)
    {
        this->nome = nom;
    }

    virtual void update()
    {
        barometro->update();
        cout << "ForecastDisplay atualizou\n";
    }

    virtual void display()
    {
        cout << "O clima atual é de: " << barometro->climaAtual << "\n";
    }
};