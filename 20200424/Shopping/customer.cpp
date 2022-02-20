#include <iostream>
#include <fstream>
#include <string>

#include "customer.h"
#include "product.h"

using namespace std;
Customer::Customer(const string &fname)
{
    ifstream f;
    f.open(fname.c_str());
    f >>_name;
    string s;
    while(f >> s) {
        _list.push_back(s);
    }
}

void Customer::purchase(const Store &store)
{
    cout << _name << " customer has bought the following products: \n";
    for (string productName : _list) {
        Product *product;
        if (linsearch(productName, store._foods, product)) {
            _cart.push_back(product);
            cout << product->getName() << " " << product->getPrice() << endl;
            store._foods->takeOutFromStock(product); // instead of store._foods->_stocks->remove()
        }
    }
    for (string productName : _list) {
        Product *product;
        if (minsearch(productName, store._technical, product)) {
            _cart.push_back(product);
            cout << product->getName() << " " << product->getPrice() << endl;
            store._technical->takeOutFromStock(product); // instead of store._foods->_stocks->remove()
        }
    }
}

bool Customer::linsearch(std::string name, Department* d, Product* &product) const
{
    bool l = false;
    for(Product* p : d->_stock ) {
        if ( ( l = (name == p->getName()) ) ) {
            product = p; break;
        }
    }
    return l;
}

bool Customer::minsearch(std::string nev, Department* d, Product* &product) const
{
    bool l = false;
    int min;
    for(Product* p : d->_stock )  {
        if (p->getName() != nev) continue;
        if (l) {
            if (min > p->getPrice()) {
                min = p->getPrice();
                product = p;
            }
        }
        else  {
            l=true;
            min = p->getPrice();
            product = p;
        }
    }
    return l;
}
