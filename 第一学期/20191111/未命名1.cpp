#include<iostream>
#include <cstring>
using namespace std;


void f1(int a ,int &b,int c)
{
	a *= 2;
	b *= 2;
	c *= 2;
	
	
}

int main(){
	int x = 1,y=3,z=7;
	f1(x,y,z);
	cout<< x<<y<<z;
	return 0;
}
