#include<iostream>
using namespace std;

int main()
{
	int n;
	cout << "Input n 1<=n<=100"<<endl;
	cin>> n;
	int sum=0;
	if(n<1)
	{cout<<"error"<<endl;
	}
	for(int i=0;i<=n;i++)
	{
		if(i%2==0)
		{
			sum=sum+1;
		}
	 } cout << sum;
	
}
