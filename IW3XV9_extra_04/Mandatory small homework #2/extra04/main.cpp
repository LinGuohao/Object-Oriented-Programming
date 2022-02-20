#include <iostream>
#include"enor.h"
using namespace std;

int main()
{
    try{
         Gradeenor t("input.txt");
         Grade y;
         t.read();
         t.next();
         y.cunt=t.current().cunt;
         y.name=t.current().name;
         //cout<<y<<endl;
         t.next();
         while(!t.end())
         {
             if(y.cunt<t.current().cunt)
             {
                 y = t.current();
             }
             t.next();

         }
        cout<<y<<endl;

    }catch(Gradeenor::Error FILE_OPEN_FAILED)
    {
        cout<<"No such file!!"<<endl;
    }
}
