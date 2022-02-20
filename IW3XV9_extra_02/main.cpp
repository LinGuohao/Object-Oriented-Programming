#include <iostream>
#include<vector>
#include<fstream>
using namespace std;

class Rec{
	private:
	int Length=0;
	int Width=0;
	public:
		Rec(int x,int y);
		int area();




};


Rec::Rec(int x ,int y)
{
	Length = x;
	Width = y;
}



int Rec::area(){
	int siz;
	siz = Length * Width;

	return siz;
}



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
