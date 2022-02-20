#include <iostream>
#include "Driver.h"

using namespace std;

int main()
{
    Driver driver("Kazim");
    Petrolstation SOCAR(2);
    driver.refuel(SOCAR, 2 ,5);
    return 0;
}
