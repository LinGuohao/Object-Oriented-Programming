#include<iostream>
using namespace std;
typedef struct {
	int a ;
	int b;
	int c;
}note;

int main ()
{
	//campany
	int n;
	cin >> n; 
	string cam[n];
	for(int i=0;i<n;i++)
	{
		cin >> cam[i] ;
	}
	/*test
	for (int i=0;i<n;i++)
	{
		cout << cam[i] << endl;
			}
*/  
   // notes
   int notes;
   cin >> notes;
   note note1[notes];
   for(int i=0;i<notes;i++)
   {
   	cin >> note1[i].a >> note1[i].b >> note1[i].c;
   }
   int a,b;
   cin>>a>>b;
   /* test
   for(int i=0;i<notes;i++)
   {
   	cout << note1[i].a << note1[i].b << note1[i].c;
   }*/
   //search
   int tem[notes],cnt;
   cnt=0;
   for(int i=0;i<notes;i++)
   {
   	if(note1[i].b==7)
   	{
   		tem[cnt] =i;
   		cnt++;
	   }
   }
   if(cnt==0)
   {
   	cout<< cnt<< " NINCS";
   }
   else
   {
   	cout<< cnt;
   	for(int i=0;i<cnt;i++)
   	{
	   
   	cout <<" "<< cam[note1[tem[i]].a-1];
    }
	 }cout << endl;
	 
}

   
   
   
   
   /*int tem[notes] ;
   int cnt;
   cnt =0;
   for(int i=0;i<notes;i++)
   {
   	if(note1[i].b == 7 );
   	{
	   tem[cnt] = i;
	   cnt++;
     }
	}
	if (cnt==0)
	cout << "Nincs";
	else
	{
	for(int i =0;i<cnt;i++)
     {
     	cout<<note1[tem[i]].a<<" "<< cam[note1[tem[i]].c-1]<<endl;
	   }  
}
}
   
   /*do{
   	tem = tem +1;
   }while(note1[tem].b != 7 || tem ==notes);
if(tem<notes)
cout << note1[tem].c <<" "<< cam[note1[tem].a-1];
   if(tem == notes )
   cout << "Nincs";

 } //5 
*/
 
