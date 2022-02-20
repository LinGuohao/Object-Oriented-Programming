//Problem: Check whether the input file contains
//consecutive equal elements.
#include <iostream>
#include "pairEnor.h"

using namespace std;

int main()
{
    PairEnor enor("in.txt");
    pair<int, int> elem;

    //linear search
    //cond: the first and second member of an enumerated pair equal
    bool l = false;
    enor.first();
    while(!l && !enor.end())
    {
        elem = enor.current();
//        cout << elem.first << " " << elem.second << endl;
        l = elem.first == elem.second;
        enor.next();
    }
    if(l)
    {
        cout << "The first element of the file that equals to its consecutive element is " << elem.first << endl;
    }
    else
    {
        cout << "There are no consecutive duplicates in the input file." << endl;
    }
}
