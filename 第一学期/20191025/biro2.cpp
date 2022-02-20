#include <iostream>

using namespace std;
typedef struct {
	float a;
	float b ;
}data;

int main()
{
	int n ;
	cin >> n;
	data data1[n];
	for(int i=0 ; i<n;i++)
	{
		cin >> data1[i].a >> data1[i].b ;
	}
    //search
    int cnt = 0;
    int num [n];
    for(int i=0;i<n;i++)
    {
     if ((data1[i].b/data1[i].a)>100.0)
	 {
	 num[cnt] = i+1;
	 cnt++	;
     }
	}
	//cout
	cout<<cnt<<" ";
	for(int i=0;i<cnt;i++)
	{
		cout<<num[i]<<" ";
	}

}
