#include<iostream>
#include <cstring>
using namespace std;

typedef struct 
{
	string status;
	string name;
	int hour ;
	int min ;

}use;
typedef struct
{
	string status;
	int hour;
	int min ;
}sort;

typedef struct
{
	int hout;
	int min; 
}time;

int main()
{
	int n ;
	cin >> n;
	use user[n];
	for(int i=0;i<n;i++)
	{
		cin >> user[i].status >> user[i].name >> user[i].hour >> user[i].min;
	}
	
	
	//sort
	sort sorted[n];
	int tmp = 0;	
	for(int i=0;i<24;i++)
	{
		for(int j=0;j<59;j++)
		{
			for(int a = 0;a<n;a++)
			{
				if(user[a].hour == i && user[a].min == j)
				{
					sorted[tmp].hour = i;
					sorted[tmp].min = j ;
					tmp++;
					goto tere;
				}
				
			}
			tere: ;
		}
	}
	
	use newuser[n];
	int col = 0;
	for (int i=0;i<tmp;i++)
	{
		for(int j=0;j<n ;j++)
		{
			if(user[j].hour == sorted[i].hour && user[j].min == sorted[i].min)
			{
				newuser[col].status = user[j].status;
				newuser[col].name = user[j].name;
				newuser[col].hour = user[j].hour;
				newuser[col].min = user[j].min;
				col++;
			
			}
		}
	}
	/*
	for (int i=0;i<col;i++)
	{
		cout << newuser[i].hour << newuser[i].min<<endl;
	}

	
*/	
	
	string namecopy [n];
    for(int i=0;i<n;i++)
    {
       namecopy[i] = newuser[i].name;
       
	}
	
/*	for (int i=0;i<n;i++)
	{
		cout<<namecopy[i] << endl;
	}
*/	
	
	int cnt1=0;
    string tmp1 ;
    for(int i=0;i<n;i++)
    {
    	
    	tmp1 = namecopy[i];
		for(int j=i+1;j<n;j++)
    	{
    		if(namecopy[j] == tmp1)
    		{
    			namecopy[j] = "a";
    			
			}
		}
	}
	/*	for (int i=0;i<n;i++)
	{
		cout<<namecopy[i] << endl;
	}
	*/
	
	
     string name[n];
     
     for(int i=0;i<n;i++)
     {
     	if(namecopy[i] != "a")
     	{
     		name[cnt1] = namecopy[i];
     		cnt1++;
		 }
	 }

 /*  for(int i=0;i<cnt1;i++)
	{
		cout << name[i] <<endl;
	}
	*/
	int until[n] ;
	int add=0;
    int contal= 0;
    do{
    	tmp1 = name[contal];
    	for(int i=0 ;i<n;i++)
    	{
    		if(name[contal] == newuser[i].name && newuser[i].status == "KI")
    		{
    			until[add] = i;
    		    add++ ;
				goto here;	
			}
    		if(name[contal] == newuser[i].name && newuser[i].status == "BE")
    		{
    			goto here;
			}
		}
    	here : ;
    		
    		contal++;
     }while(contal<cnt1);
     
	 //cout << add;
  	  //find until
      int till = until[0];
      for(int i=0;i<add;i++)
      {
      	if(till < until[i])
      	{
      		till = until[i];
		  }
      	
	  }
	  
	//  cout << add<<endl;
	  //give index
	  
	  int index[n];
	  int mark = 0;
	  if(newuser[0].status == "BE")
	  {
	  	mark = 1 + add;
	  }
	  else
	     mark = add - 1 ;
	     index[0] = mark ;
	     //cout << index[0]<<endl;
	 for(int i=1;i<n;i++)
	 {
	 	if(newuser[i].status == "BE")
	 	{
	 		mark = mark + 1 ;
	 		index[i] = mark;
		 }
		 if(newuser[i].status == "KI"&&newuser[i+1].status == "KI" && newuser[i].name == newuser[i+1].name)
		 {
		 	mark = mark - 1 ;
		 	index[i] = mark;
		 	index[i+1] = mark;
		 	i = i+1;
		 	goto there;
		 }
		 if(newuser[i].status == "KI")
		 {
		 	mark = mark - 1;
		 	index[i] = mark;
		 }
		 there:
		 	;
//		 cout << i <<endl;
		 
	 }
/*	  cout << endl;
	  for(int i=0;i<n;i++)
	  {
	  	cout << index[i]<<endl;
	  }
	  
*/	  

      int max = index[0];
      for(int i=0;i<n;i++)
      {
      	if(max<index[i])
      	{
      		max = index[i];
		}
	  }
	  //cout << max;
     int people[n];
     tmp= 0;
	 for(int i=0;i<n;i++)
	 {
	 	if(index[i] == max)
	 	{
	 		people[tmp] = i ;
	 		tmp++;
		 }
      }	  
	  
	  for(int i=0;i<n;i++)
	  {
	  	cout << index[i]<<endl;
	  }
	  
	 

	  
	  
	  //output
	  int maxnum = index[0];
	  for(int i=0;i<n;i++)
	  {
	  	if(maxnum<index[i])
	  	{
	  		maxnum=index[i];
		  }
	  }
      
       //cout<< maxnum;
      time tmptime;
      for(int i=0;i<n;i++)
      {
      	if(index[i] == maxnum &&tmptime.hout != sorted[i].hour)
      	{
      		tmptime.hout = sorted[i].hour;
			tmptime.min = sorted[i].min;
			cout <<tmptime.hout<< " "<< tmptime.min; 
		  }
	  }
      
      
}













