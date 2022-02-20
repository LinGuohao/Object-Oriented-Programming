#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int s[n+1];
	
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
	}
	for (int i=0;i<n;i++)
	{
		if(s[i]==0){
			s[i]=5;
		}
	}
	for (int i=0;i<n;i++){
		cout << s[i]<<endl;
	}
}

