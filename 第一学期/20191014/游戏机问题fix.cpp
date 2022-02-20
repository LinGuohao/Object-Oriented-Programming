#include <iostream>

using namespace std;

typedef struct {
	int a ;
	int b;
	int c;
}note;

int main ()
{

	int n;
	cin >> n;
	string cam[n];
	for(int i=0;i<n;i++)
	{
		cin >> cam[i] ;
	}

   int notes;
   cin >> notes;
   note note1[notes];
   for(int i=0;i<notes;i++)
   {
   	cin >> note1[i].a >> note1[i].b >> note1[i].c;
   }


   string tem[notes];
   int cnt=0;
   for(int i=0;i<notes;i++)
   {
   	if(note1[i].b==7)
   	{
   		int ind=note1[i].a-1;
   		tem[cnt] =cam[ind];
   		cnt++;
	   }
   } cout << cnt;
   if(cnt==0)
   {
   	cout<< " NINCS" << endl;
   }
   else
   {
   	for(int i=0;i<cnt;i++)
   	{

   	cout<< " " << tem[i];
    }cout << endl;
	 }
return 0;
}
