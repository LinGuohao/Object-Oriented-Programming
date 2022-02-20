#include<iostream>
#include <cstring>
using namespace std;
typedef struct 
{
	string pn;
	int fd,ld;
}Trental;
int answerA2(int n, Trental Rentals[])
{
	int sum=0;
	for (int i = 0 ;i<n ; i++)
	{
	   sum = Rentals[i].ld - Rentals[i].fd + sum + 1; 
	   	}
cout << "#" << endl ;
return sum;
}


int*creatarray(int n, Trental Rentals[])
{
	int s[100];
	int a=0;
	for(int i= Rentals[n].fd ; i <= Rentals[n].ld ; i++)
	{
	s[a] = i;
	a++;
	}
	cout << s[100] ;
	return s;
	
}





void ReadRentals(int cnt,Trental A[]){
for (int i=0 ;i<cnt;i++)
{
	cin >> A[i].pn >> A[i].fd >> A[i].ld;
	}	
}



void answerA (int n, Trental Rentals[])
{
   int sum=0;
	for (int i = 0 ;i<n ; i++)
	{
	   sum = Rentals[i].ld - Rentals[i].fd + sum + 1; 
	   	}
cout << "#" << endl ;
cout << sum << endl;

}


void answerB (int n ,Trental Rentals[])
{
	cout << "#"<<endl;
	string store[n];
	string uniq[n];
    //copy 
    for(int i = 0 ;i<n;i++)
    {
    	store[i] = Rentals[i].pn;
	}
	//Search unique
	for (int j=0;j<n-1;j++)
	{
	string name = Rentals[j].pn;
	for(int i = j+1 ;i<n;i++)
	{
		if(name == store[i])
		{
			store[i] = "a";
		}
	}
	
   }
   int con = 0;
   for(int i=0 ;i<n;i++)
   {
   	if(store[i]!= "a")
   	{
   		uniq[con] = store[i];
   		con++;
	   }
   }
   //search
   int num = 0 ;
   int maxval = 0;
   int tmp = 0;
   for(int i= 0 ;i<n ;i++)
   {
   	if(uniq[0] == Rentals[i].pn)
   	{
   		maxval = maxval + Rentals[i].ld - Rentals[i].fd +1;
   		num = 0;
	   }
   }
   for(int i = 0 ;i<con ;i++)
   {
   	tmp = 0;
   	for(int j = 0 ; j< n ; j++) 
	   {
	   	 if(uniq[i] == Rentals[j].pn)
   	   {
   		tmp = tmp + Rentals[j].ld - Rentals[j].fd +1;
   		
	   }
      }
	   if(tmp > maxval)
	   {
	   	maxval = tmp ;
	   	num = i;
	   }
   
   }
   cout << uniq[num]<<endl;
    
   
}

int* answerC(int sum ,int n, Trental Rentals[]) 
{
	int set[sum];
	int z = 0;
	for(int i=0;i<n;i++)
	{
		 for(int a = Rentals[i].fd; a<= Rentals[i].ld; a++)
		 {
		 	
		 	set[z] = a;
		 	z++;
		 	
		 }
	}
    /*for (int i = 0 ; i< sum ;i++)
	{
		cout << set [i] <<endl ;
		} */   
		
		//cout << set[0]<<endl;
// search
     static int num[32];
     
	 int point = 1 ;
	 for (int j = 0 ; j< 31 ;j++)
	 {
	 
     int cnt = 0;
     for(int i=0 ; i<sum; i++)
     {
     	if(set[i] == point )
     	{
     		cnt ++;
		 }
		
	 }
	 
     num[point] = cnt ;
	 point ++ ; 
     }
	 /*for (int i = 1 ; i<= 31 ;i++)
	 {
	 	cout << num [i] <<endl;
	 }
	 */
	 //cout << num [0] <<endl;
// output 
    int max = 1 ;
    int maxva = 0;
    for (int i =1 ; i<=31 ;i++)
    {
    	if((num[i] > num[i-1])&& num[i]>maxva)
        {
		  max = i ;
		 maxva = num[i]	;
	    }
	}
	cout << max <<endl;
	return num;
    
    
    
	 
	  
    /* for (int i = 1 ; i<= 31 ; i++)
     {
     	cout << num[i]<<endl;
	 }
	*/
}
void answerD(int num[])
{
	/*for (int i = 1 ; i<= 31 ; i++)
     {
     	cout << num[i]<<endl;
	 }*/
	 int spec = 0;
	 cout <<"#"<<endl;
	 int bigger = 0  ;
	 for (int i = 2 ; i <= 31 ;i++)
	 {
	 	if(num[i] > num[i-1] && num[i]>bigger)
	 	{
	 	 	cout << i <<" ";
	 	 	bigger = num[i];
	 	 	spec++;
	    }
	 }
	 if(spec==0)
	 cout<<0;
	 cout<<endl;
}

void answerF(Trental Rentals[],int n) 
{
	cout << "#"<<endl;
	string store[n];
	string uniq[n];
    //copy 
    for(int i = 0 ;i<n;i++)
    {
    	store[i] = Rentals[i].pn;
	}
	//Search unique
	for (int j=0;j<n-1;j++)
	{
	string name = Rentals[j].pn;
	for(int i = j+1 ;i<n;i++)
	{
		if(name == store[i])
		{
			store[i] = "a";
		}
	}
	
   }
   int con = 0;
   for(int i=0 ;i<n;i++)
   {
   	if(store[i]!= "a")
   	{
   		uniq[con] = store[i];
   		con++;
	   }
   }
   
 //test
	/*for(int i = 0 ;i<n;i++)
	{
		cout << uniq[i] <<endl;
	}*/


	for (int i=0;i<con;i++)
	{
	    int days = 0;
	    int number = 0;	
		for(int j=0 ; j<n ;j++)
		{
			if(uniq[i] == Rentals[j].pn)
			{
				days = days + (Rentals[j].ld - Rentals[j].fd +1);
				number ++;
			}
		}
		cout<<uniq[i]<<" "<<number<<" "<<days<<endl;
	}
	
	
	
	
}
 




int main ()
{
	int n; // =8
	int sum ;// =56
	int* num; // record how many cars are rented each day
	cin >> n;
	Trental Rentals[n];
	ReadRentals(n,Rentals);
	
	answerA(n,Rentals);
     
    answerB(n,Rentals);
    



    sum = answerA2(n,Rentals);
    num = answerC(sum,n,Rentals);
    answerD(num);
	answerF(Rentals,n);
	
	/*for (int i = 1 ; i<= 31 ; i++)
     {
     	cout << num[i]<<endl;
	 }
	 */
    

	
}
	
	
	
	

