#include <iostream>
#include "classes.cpp"
using namespace std;

int main()
{

    FlyBehavior *x = new FlyWithWIngs();

    x->fly();

    return 0;
}