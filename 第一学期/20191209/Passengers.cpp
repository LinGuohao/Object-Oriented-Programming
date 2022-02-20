#include<iostream>
#include <cstring>
using namespace std;

typedef struct {
  int down;
  int up;
	
}people;


void answerA(int n,people Number[])
{
	int cnt = 0;
	for(int i=1;i<n-1;i++)
	{
		cnt = cnt + Number[i].up;
	}
	cout << cnt<<endl;
}

void answerB(int n,people Number[])
{
	int cnt =0;
	for(int i=1;i<n-1;i++)
	{
		if(Number[i].up == 0&&Number[i].down == 0)
		cnt++;
	}
	cout << cnt <<endl;
}
void answerC(int n,people Number[])
{
	int tmp=0;
	int max=Number[1].up - Number[1].down;
	for(int i=1;i<n-1;i++)
	{
		tmp=tmp+Number[i].up - Number[i].down;
		if(max < tmp)
		{
			max = tmp;
		}
		
		
	}
	cout << max <<endl;
	
}
void answerD (int n,people Number[] )
{
	
	int tmp = 0;
	int col = 0;
	int num[n] ;

	for(int i=1;i<n-1;i++)
	{
		tmp=tmp + Number[i].up - Number[i].down;
		if(tmp == 0)
		{
			num[col] = i;
			col = col +1;
		}
		
	}
    
	for(int i=0;i<col;i++)
	{
		cout << num[i]<<endl;
		}	
	
	
}
void answerE(int n,people Number[])
{
	int heap[n];
	for(int i=0;i<n;i++)
	{
		if(Number[i].up > Number[i].down)
		{
			heap[i] = heap[i-1] + 1; 
		}else
		{
			heap[i] = 0;
		}
	}
	int index=0;
	int max=heap[0];
	for(int i=1;i<n;i++)
	{
		
		if(max<heap[i])
		{
			max = heap[i];
			index=i+1;
		}
		
	}
	
	
	
	cout<< index - max +1 << " "<<index<<endl;
	
	
	
	
}

int main()
{
	int n;

	cin >> n;
	people Number[n];
	for(int i=0;i<n;i++)
	{
		cin >> Number[i].down >> Number[i].up;
		
	}
	answerA (n,Number);
	answerB(n,Number);
	answerC(n,Number);
	answerD(n,Number);
	answerE(n,Number);
	
	
	
	
}
