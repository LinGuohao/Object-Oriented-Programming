#include<iostream>
using namespace std;

typedef struct {
int cid, gen ,cnt ; 	
} Tline ; 

int main()
{
	int n;
	//cerr << "n: ";
	cin >> n ;
	string comp[n];
	for (int i =0 ; i< n;i++)
	{
		cin >> comp[i];
	 } 
	int notes;
	cin >> notes ;
	Tline IA[notes];
	for (int i =0; i<notes; i++){
		cin >> IA[i].cid >> IA[i].gen >> IA[i].cnt;
	}
	int  a,b;
	cin >> a >> b;
	int cnter = 0;
	string outa [notes]; 
	for (int i =0;i< notes; i++)
	{
		if(IA[i].gen == 7)
		{
		
		int ind =IA[i].cid-1;
		outa[cnter] = comp[ind];
		cnter++;}
	}
	if (cout == 0)
	cout<<"NONE"<<endl;
	else
	{
		cout << cnter ;
		for (int i=0 ; i<cnter;i++)
		{
			cout<<'I'<<outa[i];
		}
	}cout << endl;
}
