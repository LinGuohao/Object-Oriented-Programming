#include<iostream>

using namespace std;

int main ()
{
	int exam ;
	cout << "Number of exams  [0<number of exams <=8]";
	do{
		cin >> exam;
		if (exam<=0 || exam > 8)
		cout << "error";
	}while (exam<=0 || exam > 8);
	int grades[exam+1];
	bool certificate;
	bool existsfive;
	for(int i=1;i<=exam;i++)
	{
		do
		{
			cout << "Input "<<i<<" th " <<" grade "<<" [1¡Ügrades ¡Ü5] "; 
			cin >> grades[i];
			if(grades[i]<1 || grades[i]>5)
			cout << "error";
			
			
		}while (grades[i]<1 || grades[i]>5);
	}
	//a
	int sum;
	sum=0;
	for(int i=1 ;i<= exam;i++)
	{
		sum=sum+grades[i];
	}
     certificate = ((sum/exam) >=2);
     if (certificate ==1)
     cout << "Yes   [answer to task a] \n";
     else
     cout << "No     [answer to task a] \n";
     //b
     int i=1;
     while(i<=exam && grades[i] !=5)
     {
     	i++;
	 }
	 existsfive = (i<=exam);
     if(existsfive == 1)
	 cout << "Yes  [answer to task b] \n";
	 else
	 cout << "No   [answer to task b] \n";
     
     
}
