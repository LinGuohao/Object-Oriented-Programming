#include<iostream>

using namespace std;

int main()

{
	cout<<"number"<<endl;
	int n,sum,i;
	cin >> n;
	sum =0;
	for(i=1;i<=n;i++)
	{
	if(i%2==1)
		sum= i+sum;
	}
	cout<< sum<<endl;
	return 0;
}



