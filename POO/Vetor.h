#include <iostream>
#include <vector>
#include <math.h>

class Vetor
{
private:
    double x;
    double y;

public:
    Vetor(double nx, double ny);
    double modulo();
    Vetor unitario(Vetor vet);
};