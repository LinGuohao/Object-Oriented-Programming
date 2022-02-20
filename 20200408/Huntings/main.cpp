/*Problem:
Each line of a sequential input file contains the name of the hunter, the date of the hunting and the
animals shot by the hunter as (kind, weight) pairs. The lines of
the file are ordered by hunters.
Is it true that every hunter has shot bear on at least one of his hunts? */

#include <iostream>
#include "hunterenor.h"

using namespace std;

int main()
{
    try
    {
        HunterEnor t("input.txt");

        bool l = true;
        for (t.first() ; l && !t.end() ; t.next())
        {
            l = t.current().bear;
        }
        if (l) cout << "Every hunter has shot bear.\n";
        else cout << "Not every hunter has shot bear.\n";
    }
    catch (HunterEnor::Exception error)
    {
        cerr<<"Input file open error.\n";
    }
    return 0;
}
