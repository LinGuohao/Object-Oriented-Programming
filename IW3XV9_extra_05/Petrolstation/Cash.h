#ifndef CASH_H
#define CASH_H
#include<iostream>
#include"Station.h"
using namespace std;

class Cash
{
public:
    Cash(int tmp)
    {
        number = tmp;
    }
    void pay(int unit, Pump * a)
    {

         cout<<"This is the "<<number<<"th counter , you paid "<< unit * (a->getdisplay())<<endl;
        a-> setzero();
    }

private :
    int number;
};

#endif // CASH_H
