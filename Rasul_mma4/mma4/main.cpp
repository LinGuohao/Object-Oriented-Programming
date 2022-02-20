#include <iostream>
#include "Driver.h"
using namespace std;

int main()
{
  Driver driver("K",30);
  Station station(3);
  driver.refuel(station);
}
