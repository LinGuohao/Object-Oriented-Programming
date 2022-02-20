#pragma once
#include "Station.h"
#include "Pump.h"


class Cash
{
    public:
        Cash(){}
        void pay(Station &station,Pump &pump);
        int getCash(){return  _cash;}
    private:
        int _cash;
};
