#ifndef DRIVER_H
#define DRIVER_H

#include<iostream>
#include"Station.h"
using namespace std;

class Driver
{
    public:
      void refuel(Station &s, int num , int liter )
       {
            s.pumplist[num]->fill(liter);
            s.cashlist[0]->pay(s.getunit(),s.pumplist[num]);
       }

};

#endif // DRIVER_H
