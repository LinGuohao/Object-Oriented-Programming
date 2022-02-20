#include<iostream>  
#include<string>  
#include<cstdio>  
using namespace std; 

int main()
{
	string a,b;
	int temp,temp2,i,j,k;
	int num,sum[2000],kw;
	cin>>num;
	for(i=1;i<=num;i++)
	{
		cin>>a>>b;
		j=a.length();
		k=b.length();
		while(j<=k)
		{
			for(;k>=0;k--)
			{
				for(;j>=0;j--)
				{
					temp=b[k-1]+a[j-1]; 
				    temp2= temp/10;
					sum[j]=temp%10+temp2 ;
				    
				    
				}
			}
		}
		
	}
	for(j=0;i>num;j++)
	cout << sum[j];
}
