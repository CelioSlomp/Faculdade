#include <iostream>
#include "duck.cpp"
using namespace std;

int main()
{
    Duck *patoMallard = new MallardDuck();
    Duck *patoCabeca = new RedHeadDuck();
    Duck *patoBorracha = new RubberDuck();
    Duck *patoDecoy = new DecoyDuck();

    patoMallard->display();
    patoMallard->performFly();
    patoBorracha->display();
    patoCabeca->display();
    patoDecoy->display();

    return 0;
}