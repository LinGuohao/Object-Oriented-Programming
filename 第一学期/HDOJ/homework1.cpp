#include<iostream>
using namespace std;

int main()
{   int i,n,sum[2000];
    cout<< "give the length of the sequence,the number must <= 2000";
	cin>>  n;


	for(i=0;i<=(n-1);i++)
	{
		cin >> sum[i];
	    	
	}
	for (int i=0;i<=(n-1);i++)
	{
		if(sum[i]==0){
		cout<<"give the " <<i+1 << ".item"<<endl;
		
		cout << 5<<endl;
		 
		}
		else
		{
		cout<<"give the " <<i+1 << ".item"<<endl;
		cout << sum[i]<<endl;
	}
			}
	return 0;
}
