#include <iostream>
using namespace std;

#include "interfaces.h"

class HouseBlend : public Beverage
{
public:
    Beverage *beverage = NULL;
    HouseBlend()
    {
        description = "HouseBlend";
        sizes();
    }

    HouseBlend(Beverage *beve)
    {
        description = ", HouseBlend ";
        beverage = beve;
        this->setSize(beve->getSize());
        sizes();
    }

    string getDescription() override
    {
        if (beverage != NULL)
            return beverage->getDescription() + this->description;
        return this->description;
    }

    void sizes()
    {
        this->tamanhos['P'] = 0.50;
        this->tamanhos['M'] = 0.75;
        this->tamanhos['G'] = 1.00;
    }

    double getCost() override
    {
        if (beverage != NULL)
            return this->tamanhos[this->getSize()] + beverage->getCost();
        return this->tamanhos[this->getSize()];
    }
};

class DarkRoast : public Beverage
{
public:
    Beverage *beverage = NULL;
    DarkRoast()
    {
        description = "DarkRoast";
        sizes();
    }

    DarkRoast(Beverage *beve)
    {
        description = ", DarkRoast ";
        beverage = beve;
        this->setSize(beve->getSize());
        sizes();
    }

    string getDescription() override
    {
        if (beverage != NULL)
            return beverage->getDescription() + this->description;
        return this->description;
    }

    void sizes()
    {
        this->tamanhos['P'] = 0.40;
        this->tamanhos['M'] = 0.60;
        this->tamanhos['G'] = 0.80;
    }

    double getCost() override
    {
        if (beverage != NULL)
            return this->tamanhos[this->getSize()] + beverage->getCost();
        return this->tamanhos[this->getSize()];
    }
};

class Espresso : public Beverage
{
public:
    Beverage *beverage = NULL;
    Espresso()
    {
        description = "Espresso";
        sizes();
    }

    Espresso(Beverage *beve)
    {
        description = ", Espresso ";
        beverage = beve;
        this->setSize(beve->getSize());
        sizes();
    }

    string getDescription() override
    {
        if (beverage != NULL)
            return beverage->getDescription() + this->description;
        return this->description;
    }

    void sizes()
    {
        this->tamanhos['P'] = 0.20;
        this->tamanhos['M'] = 0.30;
        this->tamanhos['G'] = 0.40;
    }

    double getCost() override
    {
        if (beverage != NULL)
            return this->tamanhos[this->getSize()] + beverage->getCost();
        return this->tamanhos[this->getSize()];
    }
};

class Decaf : public Beverage
{
public:
    Beverage *beverage = NULL;
    Decaf()
    {
        description = "Decaf";
        sizes();
    }

    Decaf(Beverage *beve)
    {
        description = ", Decaf ";
        beverage = beve;
        this->setSize(beve->getSize());
        sizes();
    }

    string getDescription() override
    {
        if (beverage != NULL)
            return beverage->getDescription() + this->description;
        return this->description;
    }

    void sizes()
    {
        this->tamanhos['P'] = 0.60;
        this->tamanhos['M'] = 0.90;
        this->tamanhos['G'] = 1.20;
    }

    double getCost() override
    {
        if (beverage != NULL)
            return this->tamanhos[this->getSize()] + beverage->getCost();
        return this->tamanhos[this->getSize()];
    }
};

class Milk : public CondimentDecorator
{
public:
    Beverage *beverage;
    Milk(Beverage *beve)
    {
        beverage = beve;
        this->setSize(beve->getSize());
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
        this->setSize(beve->getSize());
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
        this->setSize(beve->getSize());
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
        this->setSize(beve->getSize());
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