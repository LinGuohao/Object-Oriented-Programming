#include<iostream>
using namespace std;
typedef struct{
 int a,b;
}wall;


int main()
{
	int n;
	wall space[2];
	cin >> n; 
	cin >> space[0].a >> space[0].b >> space[1].a >> space[1].b;
	wall wall1[n] ;
	wall wall2[n] ;
	for(int i=0;i<n;i++)
	{
		cin >> wall1[i].a >> wall1[i].b >> wall2[i].a >> wall2[i].b;
	}
	cout << n;
	//test
	cout << space[0].a << space[0].b << space[1].a << space[1].b;
	for (int i=0; i<n ;i++)
	{
		cout << wall1[i].a << wall1[i].b << wall2[i].a << wall2[i].b;
	}

   for(int i = 0;i<n;i++)
    {
    	cout << i <<endl;
	}
    

    
    
    
    
    
    
    
    
    
    
	 
    
	
	
	
	/*//search
	int cntr,cntt,cntb,cntl;
	cntl = 0;
	for(int i=0;i<n;i++)
	{
		if(space[0].a == wall1[i].a )
		{
			cntl++;
		}
		else
		cntl = 0;
	}
	if (cntl >0)
	cout << cntl-1;
	else
	cout << cntl;
*/	
return 0 ;
} 

