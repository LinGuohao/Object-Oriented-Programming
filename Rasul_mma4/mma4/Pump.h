#pragma once
#include "Driver.h"

class Pump
{
    public:
        Pump(){}
        void fill(int amount);
        int getDisplay(){return _display;}

    private:
        int _display;
};

