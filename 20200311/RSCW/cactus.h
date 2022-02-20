#ifndef CACTUS_H
#define CACTUS_H

#include <string>
#include <iostream>

class Cactus {
private:
    std::string _name;
    std::string _country;
    std::string _color;
    int _size;
public:
    friend std::istream& operator>>(std::istream& in, Cactus& c);
    friend std::ostream& operator<<(std::ostream& out, const Cactus& c);
    friend bool operator<(const Cactus& c1, const Cactus& c2);
    std::string getCountry() const;
};

#endif // CACTUS_H

