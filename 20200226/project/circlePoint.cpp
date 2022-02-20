#include <iostream>
#include<vector>
#include<fstream>
#include"circle.h"
#include"point.h"
using namespace std;

int main()
{
	
	vector<Point> p ;
    ifstream f("input.txt");
    double x , y ;

    while(f>>x>>y){
    Point tmp (x,y);
	p.push_back(tmp);
	}

	bool ans = false;
	Circle c(Point(0,0),5);
    unsigned int i=0;
    while(ans == false && i<p.size()  )
    {
    	ans = c.isInside(p[i]);
    	i++;
	}
	if(ans == true)
	{
		Point tmp2 ;
		int t = tmp2.getX();
		int z = tmp2.getY();
		cout << "x:"<<t << " z:"<< y <<endl;
	}
	
	return 0 ; 
	
	
	
	
	
	
}
