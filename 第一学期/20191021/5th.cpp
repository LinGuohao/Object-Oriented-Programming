#include<iostream>
using namespace std;
typedef struct {
	string spec;
	int age;
	string color;
}Tanimals;

int main()
{
 int n;
 cin >> n;
 Tanimals Animals[n];
 int cnt;//output for a
 bool exits;//out for b
 for(int i=0;i<n;i++)
 {
   cout << i+1<<".animal(species,age,color):";
   cin>> Animals[i].spec;
   cin>> Animals[i].age;
   cin>> Animals[i].color;
 }
 	//a How many pigs are there?
 	cnt=0;
 	for(int i=0;i<n;i++)
 	{
 		if(Animals[i].spec == "pig")
 		cnt++;
	 }
	 cout << cnt <<"pig(s) we have"<<endl;
	 //b Are there any black lambs among the animals?
	 int i =0;
	 while(!(Animals[i].color == "black" &&Animals[i].spec == "lamb") &&i<n)
	 {
	 	i++;
	 	exits = (i<n);
	 }
	 if (exits)
	 cout << "Yes"<<endl;
	 else
	 cout << "No"
	 //c Give the age of each animal one year from now.
	 int Age[n];
	 for (i=0;i<n;i++)
	 {
	 	Age[i]=Animals[i].age+1;
	 }
	 for(i=0;i<n;i++)
	 {
	 	cout<< i+1<<".."<<Age[i]<<endl;
	 }
	 //d Give all the cows that are at least 2 years old.
    int cntc = 0;
    int Cows[n];
    for(i=0;i<n;i++){
	
	if(Animals[i].age >=2 && Animals[i].spec =="cow")
    {
    Cows[cntc]=i;
    
	cntc++;	
	}
	
}
     int ind=Cows[i];
	for(i=0;i<cntc;i++)
	cout <<i+1 <<Animals[ind].spec<< ".."<<Animals[ind].age<<endl;   
}

