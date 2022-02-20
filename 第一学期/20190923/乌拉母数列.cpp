#include<iostream>

using namespace std;
int main()
{
  int n,b;
  cin >>n;
  
while(n>1)
{

	if((n%2)==0)
	{
		
		n= n/2;
		cout << n<<endl;
	}
	else
	{
		
		n= 3*n+1;
		cout <<n<<endl;
	}
	
}
  cout << 1;
return 0;	
}

 
