#include <iostream>
#include "classes.cpp"
using namespace std;

int main()
{

    WeatherData *dados = new WeatherData();

    dados->registerObserver(new CurrentConditionsDisplay("CondAtuais"));
    dados->registerObserver(new ForecastDisplay("ClimaAtual"));
    dados->registerObserver(new StatisticsDisplay("Estatisticas"));

    dados->measurementsChanged();
    cout << dados->getHumidity();

    return 0;
}