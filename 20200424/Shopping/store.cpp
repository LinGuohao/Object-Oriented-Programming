#include "Store.h"

using namespace std;

Store::Store(const string &fname, const string &tname)
{
    _foods = new Department(fname);
    _technical = new Department(tname);
}

