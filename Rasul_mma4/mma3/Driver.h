#pragma once
#include <string>
#include "Petrolstation.h"
#include "Pump.h"

class Driver{
    public:
        Driver(std::string name);
        void refuel(Petrolstation b, int no, int liter);
    private:
        std::string _name;
};
