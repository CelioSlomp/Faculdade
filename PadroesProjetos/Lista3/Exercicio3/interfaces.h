#include <iostream>
#include <map>
using namespace std;

class Beverage
{
public:
    virtual ~Beverage(){};
    string description = "";
    char size = 'P';
    map<char, double> tamanhos;

    virtual string getDescription() = 0;

    virtual double getCost() = 0;

    virtual void setSize(char siz)
    {
        this->size = siz;
    };

    virtual char getSize()
    {
        return this->size;
    }
};

class CondimentDecorator : public Beverage
{
public:
    virtual ~CondimentDecorator(){};
    virtual string getDescription() = 0;
};