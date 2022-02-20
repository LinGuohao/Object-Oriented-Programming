#include<iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef struct
{
	int com;
	int type;
	int price;
}item;

int main()
{
	int c,t,n;
	cin>>c>>t>>n;
	item items[n];
	for(int i=0;i<n;i++)
	{
		cin >> items[i].com >> items[i].type >> items[i].price;
	}
	
	int company[c+1];
	int cnt;
    for(int i=1;i<=c;i++)
    {
    	cnt=0;
    	for(int j=0;j<n;j++)
    	{
    		if(i==items[j].com)
    		{
    			cnt++;
			}
		}
		company[i] = cnt;
		
	}
	
	int max=company[1];
	int maxind=1;
	for(int i=2;i<=c;i++)
	{
		if(max<company[i])
		{
			max=company[i];
			maxind = i;
		}
		
	}
	cout<<maxind;
	
	
}

