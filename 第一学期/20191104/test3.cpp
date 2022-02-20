#include<iostream>

using namespace std;

int main()
{
	int babies;
	do{
		cin >> babies;
		if(babies<=0 || babies >100)
		{
			cout << "error";
		}
	}while (babies<=0 || babies >100);
	int bornw[babies+1];
	int onemonthw[babies+1];
    for (int i=1;i<=babies;i++)
	{ 
	do
	{
	cin >> bornw[i] >> onemonthw[i];
	if(bornw[i] < 800 || bornw[i] > 7000 || onemonthw [i]< 800|| onemonthw[i] > 9000)
	cout << "error";
		
	}while (bornw[i]<800 || bornw[i]>7000 ||onemonthw[i] <800|| onemonthw[i]> 9000);
		
    }
    //a
    bool bigbaby;
    int i;
    while(i<= babies &&bornw[i]<=4000)
    {
    	i++;
	}
		
		bigbaby=(i<=babies);
		if(bigbaby ==1)
		cout << "Yes \n";
		else 
		cout << "No \n";
		
		//b
		int leastgain;
		leastgain=1;
		for (int i=2;i<=babies;i++)
		{
			if((onemonthw[i]-bornw[i])<(onemonthw[leastgain]-bornw[leastgain]))
			leastgain=i;
		}
			cout << leastgain;
}
