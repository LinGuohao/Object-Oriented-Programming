#include <iostream>
#include<vector>
#include"Set.h"

using namespace std;

class Meau{
	public :
		void run();
	//	void running(int tmp, Seq first);

};

#define NORMAL_MODE
#ifdef NORMAL_MODE


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
	        int tmp2 ;
	        cout<<endl;
	        cout << " Give a integers"<<endl;
	        cout << ">>>> " ;
	        cin >> tmp2;
	    	first.in(tmp2);
		}
		if(tmp==7)
		{
			first.prout();
		}
		if(tmp==4)
		{
		    if(first.isEmp() == true)
            {
              cout<<endl<<"Set is empty!"<<endl;
            }else
            {
                int tmp2;
	            cout<<endl;
	            cout <<"Which element do you want to know if it exists"<<endl;
	            cout << ">>>> " ;
	            cin >> tmp2 ;
                first.isEit(tmp2);
            }

		}
		if(tmp == 2)
        {
              if(first.isEmp() == true)
            {
              cout<<endl<<"Set is empty!"<<endl;
            }
            else
	        {
	            int tmp2;
                cout<<endl;
	            cout << "Which element do you want to remove" <<endl;
	            cout << ">>>> ";
	//int tmp;
	            cin >> tmp2 ;
			    first.rem(tmp2);
		     }
        }
		if(tmp == 3)
		{
			bool Emp = first.isEmp();
			if(Emp == false)
	         {
		        cout << endl << "Set is not empty"<<endl;
              }
	        else
             {
                cout << endl << "Set is empty"<<endl;
              }
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
	cout << "   --------  Integers set  --------         "<<endl;
	cout <<"1. - Insert an element " <<endl;
	cout <<"2. - Removing an element "<<endl;
	cout << "3. - Whether  the  set  is  empty" <<endl;
	cout << "4. - Whether  the  set  contains  an  element" <<endl;
	cout << "5. - Returning a random element " <<endl;
	cout << "6. - The number of even numbers in the set" <<endl;
	cout << "7. - Print set" <<endl;
	cout <<"0. - Quit        "<<endl<<endl<<endl;
	cout <<">>>> " ;


}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include"Set.h"

TEST_CASE("insert")
{
    Seq first;
    CHECK(first.in(5) == true);
    CHECK(first.in(5) == false);
}
TEST_CASE("isEmpty")
{
    Seq first;
   CHECK(first.isEmp() == true);
    first.in(5);
    CHECK(first.isEmp()==false);

}
TEST_CASE("Remove")
{
    Seq first;
    CHECK(first.rem(5)==false);
    first.in(5);
    CHECK(first.rem(5)==true);
    CHECK(first.rem(5)==false);

}
TEST_CASE("Exist")
{
    Seq first;
    first.in(5);
    CHECK(first.isEit(5)==true);
    CHECK(first.isEit(4)==false);
}
TEST_CASE("Rand")
{
    Seq first;
    CHECK(first.rade()== -1);
    first.in(5);
    CHECK(first.rade()== 5);
   /*
    first.in(6);
    CHECK(first.rade()== 6 || 5);
    first.in(7);
    CHECK(first.rade()== 6 || 5|| 7);
    */
}

TEST_CASE("Even number")
{
    Seq first;
    CHECK(first.Evnum()==-1);
    first.in(5);
    CHECK(first.Evnum()==0);
    first.in(6);
    CHECK(first.Evnum()==1);
}

TEST_CASE("Print")
{
    Seq first;
    CHECK(first.prout() == false);
    first.in(5);
    CHECK(first.prout() == true);
}




#endif // NORMAL_MODE


