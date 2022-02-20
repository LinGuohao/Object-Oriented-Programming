#include<iostream>  
#include<string>  
#include<cstdio> 
using namespace std; 

int main()
{
	string a ,b;
	 
	int j,k,m,n;
	int sum[2000],temp,temp2=0;
	cin >> a>>b;
	j=a.length();
	k=a.length();
	
	
	
	
	
	
	for(;j>0;j--)
	{
		
		m=a[j-1]-'0';
		n=b[k-1]-'0';
		temp=a[j-1]+b[k-1];
		sum[j]= temp% 10 +temp2;
		temp2=temp/10;
		k=k-1;
	}
     
    
	
	for(int i=1;i<=j;i++)
      cout << sum[i];
 
      return 0;
}

 
