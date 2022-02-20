#pragma once
#include<string>
#include "Station.h"
class Driver
{
    public:
        Driver(const std::string name,  int amount);
        void refuel(Station p1);
        int getAmount(){return _amount;}
        std::string getName(){return _name;}
    private:
        int _amount;
        std::string _name;
};


