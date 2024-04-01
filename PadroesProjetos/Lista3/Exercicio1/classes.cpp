#include <iostream>
using namespace std;

#include "interfaces.h"

class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        description = "HouseBlend";
    }

    double getCost() override
    {
        return 0.5;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        description = "DarkRoast";
    }

    double getCost() override
    {
        return 0.4;
    }
};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        description = "Espresso";
    }

    double getCost() override
    {
        return 0.35;
    }
};

class Decaf : public Beverage
{
public:
    Decaf()
    {
        description = "Decaf";
    }

    double getCost() override
    {
        return 0.75;
    }
};

class Milk : public CondimentDecorator
{
public:
    Beverage *beverage;
    Milk(Beverage *beve)
    {
        beverage = beve;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Milk";
    }

    double getCost()
    {
        return beverage->getCost() + 0.25;
    }
};

class Mocha : public CondimentDecorator
{
public:
    Beverage *beverage;
    Mocha(Beverage *beve)
    {
        beverage = beve;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Mocha";
    }

    double getCost()
    {
        return beverage->getCost() + 0.50;
    }
};

class Soy : public CondimentDecorator
{
public:
    Beverage *beverage;
    Soy(Beverage *beve)
    {
        beverage = beve;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Soy";
    }

    double getCost()
    {
        return beverage->getCost() + 0.65;
    }
};

class Whip : public CondimentDecorator
{
public:
    Beverage *beverage;
    Whip(Beverage *beve)
    {
        beverage = beve;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Whip";
    }

    double getCost()
    {
        return beverage->getCost() + 1;
    }
};