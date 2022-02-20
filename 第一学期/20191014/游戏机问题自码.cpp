#include<iostream>
using namespace std;
typedef struct {
	int a ;
	int b;
	int c;
}note;

int main()
{
	int num ;
	cin >> num;
	string cam[num-1];
	for (int i=0;i<num;i++)
	{
		cin >> cam[i];
	}
	for (int i =0;i<num;i++)
	 {
	 
	 cout << cam[i]<<endl;
     }

	int notes;
	cin >> notes;
	note note1[notes];
	for(int i=0;i<notes;i++)
	{
		cin >>note1[i].a >> note1[i].b >>note1[i].c;
	}
	
	int e,f;
     cin>>e>>f;
	//search
	int i,cont;
	cont=0;
	for(i=0;i<notes;i++)
	{
		if (note1[i].b == 7)
		{
			cont++;
			
		}
   
	}
	if(cont==0)
	cout << "NONE";
	else
	{
		cout << note1[i].c <<" "<<cam[note1[i].a-1];
	}
	
}
