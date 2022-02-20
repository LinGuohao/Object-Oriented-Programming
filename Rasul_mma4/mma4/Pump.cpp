#include "Pump.h"
#include<iostream>
using namespace std;

/*
Pump::Pump(int display)
{
    _display=display;
}*/


void Pump::fill(int amount){
    _display = amount;
cout << "The amount of litres: " << _display << endl;
}
