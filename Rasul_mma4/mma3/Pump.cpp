#include "Pump.h"

Pump::Pump(int number){
    _number = number;
}

void Pump::fill(int liter){
    _display = liter;
}
