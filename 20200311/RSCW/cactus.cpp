#include <iostream>
#include "cactus.h"

std::istream& operator>>(std::istream& in, Cactus& c)
{
    in >> c._name >> c._country >> c._color >> c._size;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Cactus& c)
{
    out << "Name: " << c._name << " Country: " << c._country << " Color: " << c._color << " Size: "
        << c._size << std::endl;
    return out;
}

//overloading the < operator in order to be able to compare two cacti by their size
//in the maximum search algorithmic pattern used in the main program
bool operator<(const Cactus& c1, const Cactus& c2)
{
    return c1._size<c2._size;
}

std::string Cactus::getCountry() const
{
    return _country;
}
