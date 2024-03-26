#include <iostream>
using namespace std;

class Observer
{
public:
    virtual ~Observer(){};
    virtual void update() = 0;
};

class DisplayElement
{
public:
    virtual ~DisplayElement(){};
    virtual void display() = 0;
};

class Subject
{
public:
    virtual ~Subject(){};
    virtual void registerObserver(Observer *algumDisplay) = 0;
    virtual void removeObserver(Observer *algumDisplay) = 0;
    virtual void notifyObservers() = 0;
};