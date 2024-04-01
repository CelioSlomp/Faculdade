#include <iostream>
using namespace std;

#include "interfaces.h"

class HouseBlend : public Beverage
{
public:
    HouseBlend()
    {
        description = "HouseBlend ";
        tamanhos['P'] = 0.50;
        tamanhos['M'] = 0.75;
        tamanhos['G'] = 1.00;
    }

    double getCost() override
    {
        return tamanhos[this->getSize()];
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast()
    {
        description = "DarkRoast ";
        tamanhos['P'] = 0.40;
        tamanhos['M'] = 0.60;
        tamanhos['G'] = 0.80;
    }

    double getCost() override
    {
        return tamanhos[this->getSize()];
    }
};

class Espresso : public Beverage
{
public:
    Espresso()
    {
        description = "Espresso ";
        tamanhos['P'] = 0.20;
        tamanhos['M'] = 0.30;
        tamanhos['G'] = 0.40;
    }

    double getCost() override
    {
        return tamanhos[this->getSize()];
    }
};

class Decaf : public Beverage
{
public:
    Decaf()
    {
        description = "Decaf ";
        tamanhos['P'] = 0.60;
        tamanhos['M'] = 0.90;
        tamanhos['G'] = 1.20;
    }

    double getCost() override
    {
        return tamanhos[this->getSize()];
    }
};

class Milk : public CondimentDecorator
{
public:
    Beverage *beverage;
    Milk(Beverage *beve)
    {
        beverage = beve;
        tamanhos['P'] = 0.25;
        tamanhos['M'] = 0.35;
        tamanhos['G'] = 0.50;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Milk";
    }

    double getCost()
    {
        return beverage->getCost() + tamanhos[beverage->getSize()];
    }
};

class Mocha : public CondimentDecorator
{
public:
    Beverage *beverage;
    Mocha(Beverage *beve)
    {
        beverage = beve;
        tamanhos['P'] = 0.35;
        tamanhos['M'] = 0.45;
        tamanhos['G'] = 0.60;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Mocha";
    }

    double getCost()
    {
        return beverage->getCost() + tamanhos[beverage->getSize()];
    }
};

class Soy : public CondimentDecorator
{
public:
    Beverage *beverage;
    Soy(Beverage *beve)
    {
        beverage = beve;
        tamanhos['P'] = 0.45;
        tamanhos['M'] = 0.55;
        tamanhos['G'] = 0.70;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Soy";
    }

    double getCost()
    {
        return beverage->getCost() + tamanhos[beverage->getSize()];
    }
};

class Whip : public CondimentDecorator
{
public:
    Beverage *beverage;
    Whip(Beverage *beve)
    {
        beverage = beve;
        tamanhos['P'] = 0.25;
        tamanhos['M'] = 0.35;
        tamanhos['G'] = 0.50;
    }

    string getDescription()
    {
        return beverage->getDescription() + ", Whip";
    }

    double getCost()
    {
        return beverage->getCost() + tamanhos[beverage->getSize()];
    }
};