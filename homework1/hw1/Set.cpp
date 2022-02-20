#include <iostream>
#include<vector> 
#include<time.h>
#include<stdlib.h>
#include"Set.h"

using namespace std;
void Seq::in()
{
	int tmp ;
	cout<<endl;
	cout << " Give a integers"<<endl;
	cout << ">>>> " ;
	cin >> tmp;
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
	
}

void Seq::rem()
{
	cout<<endl;
	cout << "Which element do you want to remove" <<endl;
	cout << ">>>> ";
	int tmp;
	cin >> tmp ;
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
		cout << "Successfully removed element£¡"<<endl;
		cout <<"--------------------------------"<<endl;
	}
	else
	{
		cout<<endl;
		cout<<"Element does not exist"<<endl;
		cout<<"--------------------------------";
	}

	
    
    
}

void Seq::isEit()
{
	int tmp;
	cout<<endl;
	cout <<"Which element do you want to know if it exists"<<endl;
	cout << ">>>> " ;
	cin >> tmp ;
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
	}
	else
	{
		cout<<endl;
		cout<<"Element does not exist"<<endl;
		cout<<"-------------------------------------";
	}

}





void Seq:: prout()
{
	cout <<endl<< "Set is shown below:" <<endl;
    for(int i=0;i<a.size();i++)
    {
    	cout << a[i] <<" ";
	}
	cout<<endl <<"--------------------------------------"<<endl;
}

void Seq::isEmp()
{
	bool Emp = false;
	if(a.size() == 0 )
	{
		Emp = true ;
	}
	if(Emp == false)
	{
		cout << endl << "Set is not empty"<<endl;
		
	}
	else
	{
		cout << endl << "Set is empty"<<endl;
	}
}

void Seq::rade()
{
	int tmp;
	srand(time(NULL));
	tmp = rand() % (a.size());
	if(a.size()!=0 && a.size() !=1)
	{
		cout <<endl <<"Random element specified"<<endl;
		cout << a[tmp] <<endl;
	}
	else if(a.size() == 0)
	{
		cout <<endl <<"Empty set!!"<<endl;
	}
	else if (a.size()==1)
	{
		cout <<endl <<"Random element specified"<<endl;
		cout << a[0] <<endl;
	}
	
	cout<< "-------------------"<<endl;
}


void Seq::Evnum()
{
	vector<int>tmp;
	for(unsigned int i=0;i<a.size();i++)
	{
		if(a[i] % 2 == 0)
		{
			tmp.push_back(a[i]);
		}
	}
	cout<<"The even numbers shown below"<<endl;
	
	for(unsigned int j=0;j<tmp.size();j++);
	{
		cout<< tmp[j]<<" ";
	}
	cout<<"----------------------------------"<<endl;
}
