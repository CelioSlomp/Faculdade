#include <iostream>
using namespace std;

#include "classes.cpp"

int main()
{

    Beverage *bebida1 = new HouseBlend();
    bebida1->setSize('G');
    bebida1 = new Milk(bebida1);
    bebida1 = new Mocha(bebida1);
    bebida1 = new Whip(bebida1);

    cout << bebida1->getDescription() << "\n";
    cout << bebida1->getCost() << "\n";

    return 0;
}