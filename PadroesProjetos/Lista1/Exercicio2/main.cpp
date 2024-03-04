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

    iate->display();
    bateira->display();
    canoa->display();
    jangada->display();
    barcoVela->display();
}