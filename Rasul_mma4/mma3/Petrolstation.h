#pragma once
#include <vector>
#include "Pump.h"
#include "Cash.h"

class Petrolstation{
    public:
        Petrolstation(int unit);
        int getUnit(){return _unit;}
        //std::vector<Pump> getPumps(){return pumps;}
        //std::vector<Cash> getCash(){return cash;}
        std::vector <Pump> pumps;
        std::vector <Cash> cash;
    private:
        int _unit;


};
