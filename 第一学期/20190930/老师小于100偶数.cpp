#include<iostream>
using namespace std;
int main()

{
	int n,x[n],cnt;
	cin >> n;
for(int i=0;i<n;i++)
{
cin>> x[i];
}
cnt =0;
for(int i=0;i<n;i++)
{
	if((x[i]%2)==0){
		cnt++;
		
	}
	cout<< cnt;
}
	return 0;

}
