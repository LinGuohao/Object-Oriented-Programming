#include "Cash.h"

Cash::Cash(int number){
    _number =  number;
}

void Cash::pay(int unit, int display){
    _price = unit * display;
}
