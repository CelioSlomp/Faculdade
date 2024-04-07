#include <iostream>
#include <vector>
#include <math.h>

#include "Matematica.h"

using namespace std;

vector<int> ParteMat::convCoord(vector<int> coord)
{
    // converte a coordenada  para o SDL, ja que o 0, 0 fica no
    // canto superior esquerdo
    vector<int> tamTela = {800, 800};
    vector<int> origem = {tamTela[0] / 2, tamTela[1] / 2};
    coord[0] += origem[0];
    coord[1] = origem[1] + (coord[1] * (-1));
    return coord;
} // vector convCoord

vector<double> ParteMat::resBhask(double a, double b, double c)
{
    // calcula a formula de bhaskara
    // dt = delta
    double dt = pow(b, 2) - 4 * a * c;
    double x1 = (-b + sqrt(dt)) / (2 * a);
    double x2 = (-b - sqrt(dt)) / (2 * a);
    vector<double> res = {x1, x2};
    return res;
} // vector resBhask

vector<double> ParteMat::unitario(vector<double> vet)
{
    // Retorna um Vetor unitario
    double mod = modulo(vet);
    vet[0] = (vet[0] / mod);
    vet[1] = (vet[1] / mod);
    return vet;
} // ParteMat unitario

double ParteMat::modulo(vector<double> vet)
{
    // retorna o modulo do vetor
    return sqrt(pow(vet[0], 2) + pow(vet[1], 2));
} // modulo

vector<double> ParteMat::resolv2x2(double a, double b, double c,
                                   double d, double e, double f)
{
    double dx = 0;
    double dy = 0;

    double m = e * a - d * b;
    if (m == 0)
    {
        return {1};
    }
    if (a != 0)
    {
        dy = (a * f - d * c) / m;
        dx = dx = (c - b * dy) / a;
    }
    else
    {
        dx = b * f - e * a;
        dy = (c - a * dx) / b;
    }
    return {dx, dy};
} // resolve 2x2

vector<double> ParteMat::calc_reflexao(vector<double> n, vector<double> r)
{
    n = unitario(n);
    r = unitario(r);
    double tmp = n[0] * r[0] + n[1] * r[1];
    vector<double> ref = {r[0] - 2 * tmp * n[0],
                          r[1] - 2 * tmp * n[1]};
    return ref;
}
