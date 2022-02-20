#include "Driver.h"
#include "Pump.h"
#include "Cash.h"
#include <iostream>

Driver::Driver(std::string name,int amount)
{
    _name = name;
    _amount = amount;
}

void Driver::refuel(Station p1){
    Pump pump;
    pump.fill(_amount);
    Cash cash;
    cash.pay(p1,pump);
    std::cout << "The amount you need to pay: "<<cash.getCash() << std::endl;
}
