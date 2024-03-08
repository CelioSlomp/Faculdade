#include <iostream>
using namespace std;

#include "classes.cpp"

int main()
{
    Barco *iate = new Iate();
    Barco *bateira = new Bateira();
    Barco *canoa = new Canoa();
    Barco *jangada = new Jangada();
    Barco *barcoVela = new BarcoVelas();

    iate->displayUP();
    bateira->displayUP();
    canoa->displayUP();
    jangada->displayUP();
    barcoVela->displayUP();
}