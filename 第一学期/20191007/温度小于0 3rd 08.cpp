#include<iostream>

using namespace std;

int main()
{
	int n ,cnt;
	cin >> n;
	int X[n];
	// asking temperatures
	for (int i=0;i<n;i++)
	{
		cout << "give the "<< i+1 << "th temperature";
		
		cin >> X[i];
		
	 } 
	 cnt = 0; 
	 for (int i=0;i<n;i++){
	 	
		 if(X[i]<0)
		 cnt ++;
	}	 
	 	cout << "temp..."<<cnt <<endl;
	 
	 
	 
}
