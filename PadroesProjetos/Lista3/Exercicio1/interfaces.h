#include <iostream>
using namespace std;

class Beverage
{
public:
    virtual ~Beverage(){};
    string description = "";
    virtual string getDescription()
    {
        return this->description;
    }

    virtual double getCost() = 0;
};

class CondimentDecorator : public Beverage
{
public:
    virtual ~CondimentDecorator(){};
    virtual string getDescription() = 0;
};