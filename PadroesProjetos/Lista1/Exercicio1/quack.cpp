#include <iostream>
using namespace std;

class QuackBehavior
{
public:
    virtual ~QuackBehavior(){};
    virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
    virtual void quack()
    {
        cout << "Quack!\n";
    }
};

class Squeak : public QuackBehavior
{
public:
    virtual void quack()
    {
        cout << "Assobio!\n";
    }
};

class MuteQuack : public QuackBehavior
{
public:
    virtual void quack(){};
};