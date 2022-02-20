#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<fstream>
using namespace std;

int main()
{
	const int Max = 100000;
	const int MIN = 1000;
	srand(time(NULL));
	freopen("out.txt","w+",stdout);
	for(int i=0;i<1000000;i++)
	{
		
		unsigned long data = rand()%MIN;
		cout <<data <<" ";
	}
	fclose(stdout);
}
