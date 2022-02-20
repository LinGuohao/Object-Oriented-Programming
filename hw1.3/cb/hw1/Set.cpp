#include <iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include"Set.h"

using namespace std;
bool Seq::in(int tmp)
{

    bool rpt = false;
    int i=0;
    while(i<a.size() && rpt == false)
    {
        if(a[i] ==tmp)
        {
        	rpt = true;
		}
    	i++;
	}

	if(rpt == false)
	{
		a.push_back(tmp);
		cout<<endl;
		cout<< "Successful!!"<<endl;
		cout<<"--------------------------------";
	}
	else
	{
		cout<<endl;
		cout<<"Existing duplicate element"<<endl;
		cout<<"----------------------------------";
	}
return !rpt;
}

bool Seq::rem(int tmp)
{

	bool isctain = false;
	int i=0;
	while(i<a.size()&&isctain == false)
	{
		if(a[i] == tmp)
		{
			isctain = true ;
			vector<int>::iterator ai = a.begin()+i;
			ai = a.erase(ai);
		}
		i++;
	}
	if(isctain == true)
	{
		cout<<endl;
		cout << "Successfully removed element!"<<endl;
		cout <<"--------------------------------"<<endl;
		return isctain;
	}
	else
	{
		cout<<endl;
		cout<<"Element does not exist"<<endl;
		cout<<"--------------------------------";
		return false;
	}




    }


bool Seq::isEit(int tmp)
{

	bool isctain = false;
	int i=0;
	while(i<a.size()&&isctain == false)
	{
		if(a[i] == tmp)
		{
			isctain = true ;

		}
		i++;
	}
	if(isctain == true)
	{
		cout<<endl;
		cout << "Element exists"<<endl;
		cout<<"------------------------------------";
		return isctain;
	}
	else
	{
		cout<<endl;
		cout<<"Element does not exist"<<endl;
		cout<<"-------------------------------------";
		return isctain;
	}

    }






bool Seq:: prout()
{
	if (a.size()==0)
    {
        cout<<endl<<"Set is empty!"<<endl;
        return false;
    }
	else{cout <<endl<< "Set is shown below:" <<endl;
    for(int i=0;i<a.size();i++)
    {
    	cout << a[i] <<" ";
	}
	cout<<endl <<"--------------------------------------"<<endl;
     }
     return true;
}

bool Seq::isEmp()
{
	bool Emp = false;
	if(a.size() == 0 )
	{
		Emp = true ;
	}
	return Emp;

}

int  Seq::rade()
{

	if(a.size() == 0)
    {
        cout<<endl<<"Set is empty"<<endl;
        return -1;
    }

	else
    {
        int tmp;
	srand(time(NULL));
	tmp = rand() % (a.size());
	if(a.size()!=0 && a.size() !=1)
	{
		cout <<endl <<"Random element specified"<<endl;
		cout << a[tmp] <<endl;
		return a[tmp];
	}
    else if (a.size()==1)
	{
		cout <<endl <<"Random element specified"<<endl;
		cout << a[0] <<endl;
		return a[0];
	}

	cout<< "-------------------"<<endl;
    }
}


int Seq::Evnum()
{


    if(a.size()==0)
    {
        cout<<endl<< "Set is empty"<<endl;
        return -1;
    }

   else
    { int cnt=0;

	for( int i=0;i<a.size();i++)
	{
		if(a[i] % 2 == 0)
        {
            cnt++;
        }

	}
	cout<<"The number of the even numbers is: "<<cnt<<endl;


	cout<<"----------------------------------------"<<endl;
	return cnt;
     }
}
