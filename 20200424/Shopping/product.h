#pragma once
#include <string>

class Product
{
    public:
        Product(std::string n, int a) : _name(n), _price(a) {}
        std::string getName() const { return _name; }
        int getPrice() const { return _price; }

    private:
        std::string _name;
        int _price;
};
