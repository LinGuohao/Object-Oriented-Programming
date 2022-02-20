#include <iostream>

using namespace std;
int main()
{
	int n,i,a,summa=0;
	cin>> n;
    for(i=1;i<=n;i++)
    {
    	if((n%i)==0)
    	summa +=i;
	}
	cout << summa;
	return 0;
	}
   
