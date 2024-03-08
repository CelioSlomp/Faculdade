#include <iostream>
using namespace std;

#include "imoveis.cpp"

int main()
{
    Imovel *ter = new Terreno('A', 6.0);
    Imovel *cas = new Casa('B', 8.0, 2);
    Imovel *apa = new Apartamento('C', 2.0, 2);

    ter->getValor();
    cas->getValor();
    apa->getValor();

    return 0;
}