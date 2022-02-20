#include <iostream>
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Gas.h"

class Ozone: public Gase
{
public:
    char givename(){return 'Z';};
     Ozone(double tmpthickness)
    {
        thickness=tmpthickness;
        _name = 'Z';
    }
};
class Carbon: public Gase
{
public:
     Carbon(double tmpthickness)
    {
        thickness=tmpthickness;
        _name = 'C';
    }
    char givename(){return 'C';};
};

class Oxygen: public Gase
{
   public:
        Oxygen(double tmpthickness)
    {
        thickness=tmpthickness;
        _name = 'X';
    }
    char givename(){return 'X';};
};




