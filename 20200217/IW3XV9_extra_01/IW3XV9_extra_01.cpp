#include <iostream>
#include <vector>
#include <fstream>
#include<cmath>
#include <string>
using namespace std;
void input(vector<int>&array);
void find (vector<int>&array,int &ind , int &max);
int main()
{
	vector<int>array;
	input(array);
	int ind = 2 , max = abs(abs(array[1])-abs(array[0]));
	find(array,ind,max);
	cout<< "position of the greatest jump is " <<ind <<" The value is "<<max;

}

void input(vector<int>&array)
{
	int n;
	int cnt;
	string filename;
	do{
		n=0;
	cout<< "Give the file name"<<endl;
	cin>> filename;
	ifstream f(filename.c_str()); 
	if(!f)
	{
		n = 1;
		cout<< "No this file , please reinput file name"<<endl;
	}else
	{
		cnt = 0;
		ifstream f(filename.c_str());
		int tmp ;
		while(f >> tmp)
		{
			array.push_back(tmp);
			cnt++;
		}
		if(cnt <2)
		{
			cout<<"There must be at least two integers in the file,please reinput the file name"<<endl; 
		}
		f.close();
	}
    }while(n==1||cnt <2);
}
void find (vector<int>&array,int &ind , int &max)
{
	for(int i = 2 ; i<array.size();i++)
	{
		if(max <abs(abs(array[i])-abs(array[i-1])))
		{
			ind = i+1;
			max = abs(abs(array[i])-abs(array[i-1]));
		}
	}
}



