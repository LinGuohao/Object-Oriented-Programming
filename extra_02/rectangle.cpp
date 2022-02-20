#include <iostream>
#include"rectangle.h"
using namespace std;

Rec::Rec(int x ,int y)
{
	Length = x;
	Width = y;
}



int Rec::area(){
	int size;
	size = Length * Width;
	
	return size; 
}
