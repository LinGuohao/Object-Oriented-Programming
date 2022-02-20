#include "department.h"
#include <fstream>

using namespace std;

Department::Department(const string &fnev)
{
    ifstream f(fnev);
    int i;
    string s;
    while (f >> s >> i) {
        _stock.push_back(new Product(s,i));
    }
}

void Department::takeOutFromStock(Product *product)
{
    bool l = false;
    int ind;
    for( unsigned int i = 0; !l && i < _stock.size(); ++i) {
        l = _stock[i] == product;
        ind = i;
    }
    if (l)  _stock.erase(_stock.begin()+ind);
}


