#include <iostream>
#include "cactus.h"
#include "cactusenor.h"

using namespace std;

int main()
{
    CactusEnor enor("in.txt");
    /// Conditional MaxE:\C++\IW3XV9_extra_03\Extra03\main.cppimum Search
    bool l =false;
    enor.first();
    Cactus maxi;
    while(!enor.end()){
        if(enor.current().getCountry()=="Hungary" && l){
            if(maxi<enor.current()){
                maxi=enor.current();
            }
        }
        else if(enor.current().getCountry()=="Hungary" && !l){
            l=true;
            maxi=enor.current();
        }
        enor.next();
    }
    if(!l){
        cout << "There is no Hungarian cactus" << endl;
    }
    else{
    cout << maxi << endl;
    }
    return 0;
}
