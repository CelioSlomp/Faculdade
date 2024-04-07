#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class ParteMat
{
public:
    vector<int> convCoord(vector<int> coord);
    vector<double> resBhask(double a, double b, double c);
    vector<double> unitario(vector<double> vet);
    double modulo(vector<double> vet);
    vector<double> resolv2x2(double a, double b, double c,
                             double d, double e, double f);
    vector<double> calc_reflexao(vector<double> n,
                                 vector<double> r);
};
