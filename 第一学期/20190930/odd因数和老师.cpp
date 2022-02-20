#include<iostream>
using namespace std;

int main()
{
	int n, cnt;
	cout << "n: ";
	cin >> n;
	int Divisors[n];
	cnt =0;
	for (int i=1;i<=n;i+=2)
	{
		if((n%i)==0)
		{
			cnt++;
			Divisors[cnt]=i;
		}
	 } 
	 for(int i=0;i<cnt;i++)
	 {
	 	cout<< i+1<<".item"<<Divisors[i+1]<< endl;
	 	
	 }
	 return 0;
}
