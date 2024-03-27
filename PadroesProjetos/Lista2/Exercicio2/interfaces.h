#include <iostream>
using namespace std;

class Observer
{
public:
    virtual ~Observer(){};
    virtual void update() = 0;
};

class Subject
{
public:
    virtual ~Subject(){};
    virtual void registerObserver(Observer *algumObserver) = 0;
    virtual void removeObserver(Observer *algumObserver) = 0;
    virtual void notifyObservers() = 0;
};