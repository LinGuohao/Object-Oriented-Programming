#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct
{
	int grade;
	string name;
} Tstudent;

int main()
{
	/*Tstudent st;
	st.grade=2;
	st.name="Troy";
	cin >> st.name;*/
	int n,ind;
	bool exists;
	cout << "n: ";
	cin >> n;
	Tstudent x[n];
	
	string name [n];
	//asking for grades
	for (int i=0;i<n;i++)
	{
		do{
		
		cout << i+1 <<" th grade : ";
		cin >> x[i].grade;
		//string tmp ;
		//getline (cin,tmp,'\n');
		
		if(x[i].grade <1 || x[i].grade>5)
		{cout <<"error"<<endl;
		}
	} while(x[i].grade<1 || x[i].grade>5);
	cout << "name :";
	cin.ignore();
	getline (cin,x[i].name,'\n') ;
	/*
	getline(cin,tmp,'\n') ;
	x[i].grade=atoi(tem.c)*/
	}
	//searching
	int i=0;
	exists = ((i<n-1) && (x[i].grade!=x[i+1].grade) == 0);
	while(exists == false){
		i++;
	}
	if (i<n-1)
	{
		ind = i+1;
		cout << ind +1 << ". student,grade:"
		<<x[ind].grade << "with name: "
		<< x[ind].name<<endl;
	}  // i forget it , ask question office
	else{
		cout << "no..."<<endl;
		
	}
}
