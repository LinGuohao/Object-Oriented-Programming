#include<iostream>
#include <cstring>
using namespace std;
typedef struct Rom{
	int x1,y1,x2,y2;
}Rom;

int main()
{
	int n;//number of the room;
	cin >> n ;
	int x1, y1 , x2 ,y2; 
	cin >> x1 >> y1>>x2>>y2;
	int size [x2-x1+1] [y2-y1+1];
	//input 
	Rom room[n];
	for (int i=0; i<n;i++)
	{
		cin >> room[i].x1 >> room[i].y1 >> room[i].x2 >> room[i].y2 ;
	}
	//test input 
    /*
	 	for (int i=0; i<n;i++)
	{
		cout <<room[i].x1 << room[i].y1 << room[i].x2 << room[i].y2 ;
	}
	 */
     
	 //givev 1 ;
     for(int i = 0 ;i< n ;i++)
     {
     	for(int j = room[i].y1;j<=room[i].y2;j++)
     	{
     		for(int m = room[i].x1 ; m <= room[i].x2;m++)
     		{
     			size[m][j] = 1;     
			 }
		 }
	 }
     //test give1
     
     //cout << size[10][3];
     
     // store roomsize 
     int space[10000];
     for(int i = x1; i<= x2 ;i++ )
     {
     	for(int j=y1 ;j<= x2 ;j++)
     	{
     		if(size[i][j]==0)
     		{
     			
			 }
		 }
	 }
     
     
     
	
	
	
	
}
