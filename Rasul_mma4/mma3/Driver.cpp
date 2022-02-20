#include "Driver.h"
#include <iostream>

Driver::Driver(std::string name){
    _name = name;
}

void Driver::refuel(Petrolstation b, int no, int liter){
    Pump p(no);
    b.pumps.push_back(p);
    b.pumps[0].fill(liter);
    //b.getPumps()[0].fill(liter);
    std::cout << " Display: " << b.pumps[0].getDisplay() << std::endl;
    b.cash.push_back(no);
    b.cash[no].pay(b.getUnit(), b.pumps[0].getDisplay());
    std::cout << " Pay: " << b.cash[no].getPrice() << " AZN" << std::endl;
    b.cash.pop_back();
    b.pumps.pop_back();
}
