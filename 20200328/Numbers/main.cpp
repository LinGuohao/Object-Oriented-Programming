//Given a file containing integer numbers in an increasing order.
//Print out the the numbers contained in the file together with
//their number of occurrences

#include <iostream>
#include "enor.h"

using namespace std;

int main()
{
    try
    {
        Enor t("in.txt");
        for( t.first(); !t.end(); t.next() ){
            cout << t.current().number << " " << t.current().count << endl;
        }
    }
    catch (Enor::Errors)
    {
         cerr<<"Problem with opening the input file!" << endl;
         exit(1);

    }
    return 0;
}
