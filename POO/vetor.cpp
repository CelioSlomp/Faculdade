#include <iostream>
#include <vector>
#include <math.h>

#include "Vetor.h"

Vetor::Vetor(double nx, double ny)
{
    x = nx;
    y = ny;
}

double Vetor::modulo()
{
    // retorna o modulo do vetor
    return sqrt(pow(x, 2) + pow(x, 2));
}

Vetor Vetor::unitario(Vetor vet)
{
    // Retorna um Vetor unitario
    double modulo = vet.modulo();
    vet.x = (vet.x / modulo);
    vet.y = (vet.y / modulo);
    return vet;
}