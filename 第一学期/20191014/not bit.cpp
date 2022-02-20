#include<iostream>
using namespace std;

int main()
{
	// variables
	int n,ind = -1;
	do {
		cout << "days";
		cin >> n;
		if(n<1 || n>100)
		cout << "error" << endl;		
	} while (n<1 || n > 100);
	int x[n];
	// read numbers
	for (int i = 0; i<n; i++)
	{    do{
		  cout << i + 1 << ".fish number:";
			cin >> x[i];
			if (x[i]<0 || x[i] >30) 
			cout<< "error" << endl ;
	} while (x[i]<0 || x[i]>30);
		
	}
	// searching
	int i =0;
	while(i<n && x[i]!=0) // >0
	{
		i++ ;
	}
	if (i<n)
	{
		ind = i+1;
	}
	
	cout << ind << endl; 
	
	
	
 } 
