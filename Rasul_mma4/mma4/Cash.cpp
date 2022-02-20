#include "Cash.h"
/*
Cash::Cash(int cash)
{
 _cash=cash;
}*/
void Cash::pay(Station &station,Pump &pump){
_cash = station.getUnit() * pump.getDisplay();
}
