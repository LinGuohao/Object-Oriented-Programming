#include <iostream>

using namespace std;



int main()
{
	int days;
	cout<<"days:"<<endl;
	do {
	cin >> days;
	if(days<1||days>20)
	cout << "error"<<endl;
    }while (days<1||days>20);
	int callimit = 1800;
	int calories [days+1];
	bool overlimit;
	int dayscount;
	cout<< "give the calories"<<endl;
	for (int i=1; i<=days ; i++)
	{
		do {
		cin >> calories[i];  
		if (calories[i]>3000||calories[i]<1000) 
		cout << "error" <<endl;
	}while (calories[i]>3000||calories[i]<1000);
	}
	//a
	int i = 1;
	while (i<=days&&calories[i]<1800)
	{
		i++;
	}
	if(overlimit = (i<=days))
	
	cout << "Yes" << endl;
	else
	 cout <<"No"<<endl;
	
	//b
	
	dayscount = 0;
	
	for(i=1;i<=days;i++)
	{
		if(calories[i]<callimit*0.9)
		dayscount ++;
	}
	cout << dayscount<<endl;
}







