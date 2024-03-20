#include <iostream>
using namespace std;

#include "interfaces.cpp"

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    virtual void update()
    {
    }
};