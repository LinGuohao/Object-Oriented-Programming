#pragma once
#include "store.h"
#include <string>
#include <vector>

class Customer
{
    public:
        Customer(const std::string &fname);
        void purchase(const Store &store);

    private:
        std::string _name;
        std::vector<std::string> _list;
        std::vector<Product*> _cart;

        bool linsearch(std::string name, Department* r, Product *&product) const;
        bool minsearch(std::string nev, Department* r, Product *&product) const;
};
