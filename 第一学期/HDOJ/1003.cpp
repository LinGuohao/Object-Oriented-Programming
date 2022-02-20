#include<iostream>  
#include<string>  
#include<cstdio> 
using namespace std; 


int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int num;
		cin>>num;
		int a[num+1];
		//input
		for(int j=1;j<=num;j++)
		{
		   cin>> a[j];
		}
	
	
		// test 
	/*	for(int j=1;j<=num;j++)
		{
			cout<< a[j]<<endl;
		}
	*/	
		int tmp[num+1];
		for(int j=1;j<=num;j++)
		{
			if(j==1)
			{
				tmp[1] = a[1];
			}
			else
			{
				tmp[j] = a[j] +tmp[j-1];
			}
		}
		
		int max,maxind;
		max = tmp[1];
		maxind=1;
		for(int j=2;j<=num;j++)
		{
			if(max<tmp[j])
			{
				max=tmp[j];
				maxind=j;
			    	
			}
		}
		
		cout<<"Case"<<" "<<i<<":"<<endl;
		cout<<max<<" "<<"1"<<" "<<maxind<<endl<<endl;
		
		
		
	}
	    
	  
	 
	
	
	
}
