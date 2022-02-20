#include <iostream>
#include "enor.h"

using namespace std;

ostream& operator<<(ostream& o, const Balance &e);

int main()
{
    string file;
    try{
        cout<<"Enter the name of the input file: "; cin>>file;
        Enor t(file);
        for( t.first(); !t.end(); t.next() ){
            //cout << 1 <<endl;
            //cout << t.current().balance<<endl;;
            //cout << "*trial::  "<<t.current()<< endl;
            if(t.current().balance<-100000)
                cout << t.current();

        }
    }catch(Enor::Errors err)
    {
        if(err==Enor::FILEERROR)
            cout<<file<<"The file is not available or cannot be opened.\n";
    }

    return 0;
}

// void write(ostream& o, const Statistic &e)
ostream& operator<<(ostream& o, const Balance &e)
{
    o << e.number << " " << e.balance << endl;
    return o;
}
