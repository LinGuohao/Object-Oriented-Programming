#include <iostream>
#include "enor.h"
#include "valley.h"
using namespace std;

int main()
{
    int max;
    bool l = false;
   try{
    Vaenor t("input.txt");
     t.first();
    Valley tmp;
    //bool cond = (tmp._e>tmp._a && tmp._a < tmp._k);
    while( !t.end())
    {
        //cout << 1 <<endl;
        tmp = t.current();
      // cout<<tmp._a<<endl;
       //cout<<tmp._k<<endl<<endl;
        if((tmp._e>tmp._a && tmp._a < tmp._k)== true && l == true )
        {
            if(max < tmp._a)
            {
                max =tmp._a;
            }
        }
            if((tmp._e>tmp._a && tmp._a < tmp._k) == true && l == false )
        {
            l = true;
            max = tmp._a;
        }

        t.next();

    }
    cout<<max<<endl;
   }
   catch (Vaenor::Errors)
    {

        cout<< "No such file!"<<endl;
        exit(1);

    }




}
