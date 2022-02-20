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











int main()
{
	int n ;
	cin >> n;
	use user[n];
	for(int i=0;i<n;i++)
	{
		cin >> user[i].status >> user[i].name >> user[i].hour >> user[i].min;
	}
	



	
	
/*
	for (int i=0;i< n ;i++)
	{
		cout << user[i].status << user[i].name << user[i].hour << user[i].min<<endl;
	}
*/ 
    string namecopy [n];
    for(int i=0;i<n;i++)
    {
       namecopy[i] = user[i].name;
	}
    int cnt=0;
    string tmp ;
    for(int i=0;i<n;i++)
    {
    	
    	tmp = namecopy[i];
		for(int j=i+1;j<n;j++)
    	{
    		if(namecopy[j] == tmp)
    		{
    			namecopy[j] = "a";
    			
			}
		}
	}
     string name[n];
     
     for(int i=0;i<n;i++)
     {
     	if(namecopy[i] != "a")
     	{
     		name[cnt] = namecopy[i];
     		cnt++;
		 }
	 }
	 
	 
	 int col = 0;
	 int num = 0;
	 int index[n];
	 do{
	 	tmp = name[col];
	 	
	 		for(int i=0;i<n;i++)
	 		{
	 			if(user[i].name == tmp &&user[i].status =="KI")
	 			{
	 				
	 				
	 					index[num] = i;
	 					num++;
	 					goto here;
					 
				 }
				 if(user[i].name == tmp)
				 {
				 	goto here;
				 }
			 }
		here:	 
		col++; 
	 	
	 	
	 }while (col < cnt);
	 int max = index[0];
	 for (int i=0;i<num;i++)
	 {
	 	if(max < index[i])
	 	{
	 		max = index[i];
		 }
	 }
	 
	 
	 cout << max <<endl;
	 
	 
	 
	 
	 
	 
	 
	 
	 //max = 1;
	 //num = 1;
	 // search the most users
	 int data = 0;
	 int people[n];
	 
	 for(int i=0;i<n;i++)
	 {
	 	people[data] = 0;
	 	if(i<=max)
	 	{
	 		people[data] = people[data] + num;
		 }
		 
	 	data++;
	 }
	 
     int tmp2 = people[0];
     for(int i=0;i<n;i++)
     {
     	
		 if(user[i].name != user[i-1].name || user[i].status != user[i-1].status) 
		{
		  
		 if(user[i].status == "BE")
     	{
     		people[i] = tmp2 + 1;
     		tmp2 = people[i];
		 }
		 else
		 { people[i] = tmp2 - 1;
		  tmp2 = people[i];
		 }
	    }
	 }
	/* 
	 for(int i=0;i<n;i++)
	 {
	 	cout << people[i]<<endl;
	 }
	 */
	 // output 
	 int maxvala = people[0];
	 for(int i=1;i<n;i++)
	 {
	 	if(maxvala < people[i])
	 	{
	 		maxvala = people[i];
		 }
	 }
	 cout << maxvala ;
	 for(int i = 0;i<n;i++)
	 {
	 	if(people[i-1] != maxvala && people[i] == maxvala)
	 	cout << " "<< user[i].hour<<" "<< user[i].min;
		 if(people[i+1]!= maxvala && people[i] == maxvala)
		 cout << " "<< user[i+1].hour<<" "<< user[i+1].min; 
	 	
	 	
	 }
	 

     
        
     


/*
    for (int i=0 ;i<cnt;i++)
    {
    	cout << name[i]<<endl;
	}

  */  
    
    
    


}
