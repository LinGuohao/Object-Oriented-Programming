#include<iostream>
#include <cstring>
using namespace std;

typedef struct 
{
	int factory;
	int type ;
	int price;
}item;


void givenumber(item items[],int n)
{
	for (int i= 1 ; i<=n ;i++)
	{
		cin >> items[i].factory >> items[i].type >> items[i].price;
	}
}


void answerA(item items[],int n)
{
	int cheapest = items[1].price;
	int ind = 1;
	for (int i =1 ;i<= n ;i++)
	{
		if(cheapest> items[i].price)
		{
			cheapest = items[i].price;
			ind = i;
		}
	}
	cout << items[ind].factory <<" "<< items[ind].type<<endl;
}

void answerB(item items[],int n,int f,int c)
{
   int number[f];
   int cnt ;
   int type ;
   
   for(int i= 1 ; i<=f ;i++)
   {
   	cnt = 0;
   	type = 1;
   do{
	   
   	 for(int j=1;j<=n;j++)
   	 {
   	 	
   	 	if(items[j].factory == i && items[j].type == type)
   	 	{
   	 		cnt++;
   	 		goto here;
   	 		
		}
		
	}
     here: type++ ; 
	 }while (type <= c);
	
	 number[i] = cnt;
   	}
  
   int max = number[1];
   int index1 = 1 ;
   for(int i=1 ;i<=f;i++)
   {
   	if(max< number[i])
   	{
   		max = number[i];
   		index1 = i;
	   }
   }
   cout << index1 <<endl;
   	
   }
   
void answerC(item items[],int n,int f)
{
	int number[f];
	int col = 0;
	int index2;
	for(int i=1 ;i<=f ;i++)
	{
		for(int j= 1 ;j<=n;j++)
		{
			if(i == items[j].factory)
			{
				number[col] = i;
			    col ++ ;
				goto here;
				  
			}
			
		}
		here: ;
		
	}
	cout << col ;
    //cout << number[3];
	//test
	//cout << (col-1);
	int max;
	for(int i = 0 ;i< col ;i++)
	{
		max = 0;
	  index2 = number[i];
	  for(int j =1  ; j<= n ;j++)
	  {
	  	if(index2 == items[j].factory)
	  	{
	  		if(max < items[j].price)
	  		{
	  			max = items[j].price;
			  }
		  }
	  }
	  cout <<" " <<index2 << " " << max ;
	  
	  	
	}
	cout <<endl;
}
void answerD(item items[],int n,int c)
{

	int cnt = 0;
	int col = 0;
	for (int i=1 ; i<= c ;i++)
	{
		
		for(int j=1;j<=n;j++)
		{
			if(i == items[j].type)
			{
			  	col ++;
			  	goto here;
			}
		}
	   here: ;
	}
	cout << col <<endl ;
	
}

void answerE(item items[],int n,int c)
{
	int number[c];
	int col ;
	int cnt = 0;
	for(int i=1 ;i<=c;i++)
	{
		col = 0;
		for(int j=1;j<=n;j++ )
		{
			if(i == items[j].type)
			{
			 col ++ ;	
			}
			
			
		}
		if(col == 1)
		{
			number[cnt] = i ;
			cnt++ ;
			
		}
	}
	
	cout << cnt <<" ";
	for(int i=0;i<cnt;i++)
	{
		cout << number[i]<<" ";
	}
	
}

int main()
{
	int n,f,c;
	cin >> n >> f >> c ;
	item items [n];
	givenumber(items,n);
	//test
/*	for (int i=1 ;i<=n;i++)
	{
		cout << items[i].factory << items[i].type <<items[i].price <<endl;
	}
*/	
  cout<< "===================OUTPUT==================="<<endl;
   answerA(items,n);
   answerB(items,n,f,c);
   answerC(items,n,f);
   
   answerD(items,n,c);
  answerE(items,n,c);
   

}
