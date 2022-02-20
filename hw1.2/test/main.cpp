#include <iostream>
#include"Set.h"

using namespace std;

class Meau{
	public :
		void run();
	//	void running(int tmp, Seq first);

};


int main()
{
    Seq first;
    Meau a;
    int tmp;
    while(tmp != 0)
	{
	   a.run();
	   cin >> tmp;
	  // a.running( tmp,first);
	    if(tmp ==1)
	    {
	    	first.in();
		}
		if(tmp==7)
		{
			first.prout();
		}
		if(tmp==4)
		{
			first.isEit();
		}
		if(tmp == 2)
		{
			first.rem();
		}
		if(tmp == 3)
		{
			first.isEmp();
		}
		if(tmp == 5)
		{
			first.rade();
		}
		if(tmp==6)
        {
            first.Evnum();
        }
	}

}


void Meau::run(){
	cout<<endl<<endl;
	cout << " =====Integers set==========         "<<endl;
	cout <<"1.--Insert an element " <<endl;
	cout <<"2.--Removing an element "<<endl;
	cout << "3.--Whether  the  set  is  empty" <<endl;
	cout << "4.--Whether  the  set  contains  an  element" <<endl;
	cout << "5.--Returning a random element " <<endl;
	cout << "6.--The number of even numbers in the set" <<endl;
	cout << "7.--Print set" <<endl;
	cout <<"0.--Quit        "<<endl<<endl<<endl;
	cout <<">>>> " ;


}


