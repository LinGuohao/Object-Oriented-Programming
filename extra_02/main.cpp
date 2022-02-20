#include <iostream>
#include<vector>
#include<fstream>
#include"rectangle.h"

using namespace std;

int main(int argc, char** argv) {
	
	vector <Rec> a;
	int x , y;
	ifstream f("input.txt");
	while(f>>x>>y)
	{
		Rec tmp(x,y);
		a.push_back(tmp);
	}
	int cnt =0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i].area() <30)
		{
			cnt ++;
		}
	}
	
	
	cout<<cnt <<endl;
	
	
	
	
	
	return 0;
}
