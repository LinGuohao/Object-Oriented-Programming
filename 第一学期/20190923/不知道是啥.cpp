#include <iostream>

using namespace std;

int main()
{
	int n ,in;
	cout<< "give the length of the sequence";
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cout<<"give the " <<i << ".item";
		
		cin>> in;
		if(in==0){
			in =5;
		}
		
		cout<< in<< endl;
		
			}
	
return 0; 
}
