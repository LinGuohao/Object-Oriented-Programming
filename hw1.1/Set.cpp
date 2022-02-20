#include <iostream>
#include"Set.h"

using namespace std;
void Seq::in(int x)
{
    a.push_back(x);
}

void Seq:: prout(int x)
{
    cout <<a[x]<<endl;
}
