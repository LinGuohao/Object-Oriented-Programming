#ifndef PUMP_H
#define PUMP_H

#include<iostream>

using namespace std;


class Pump
{
public :
    void fill(int liter)
    {
        display = liter;
    }
    int getdisplay()
    {
        return  display;
    }
    void setzero()
    {
        display = 0;
    }
private:
    int display = 0;
};

#endif // PUMP_H
