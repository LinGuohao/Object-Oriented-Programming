#include <iostream>
#include <vector>
#include <fstream>

int a[1000000];
using namespace std;
void quicksort(int arry[],int L ,int R);
void BubbleSort1(int array[], int n);
int main()
{
	//cout<< a[0]<<endl;
    ifstream f;
	f.open("out.txt");
	int tmp ;
	int i=0;
	while(f>>tmp)
	{
		a[i] = tmp;
		i++;
	}
	f.close();
	int L=0,R= 999999;
  
   int n = 1000000;
   BubbleSort1(a,n);
   //cout<< a.Length<<endl;
	//quicksort(a,L,R);
  for(int j=0;j<1000000;j++)
	{
		cout<<a[j]<<" ";
	}

}
void swap(int array[], int i, int j)
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
void BubbleSort1(int array[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n-1; j++)
		{
			if (array[i]>array[j])
				swap(array,j,i);
		}
	}
}


void quicksort(int array[],int L ,int R)
{
	if(L>=R)
	{
		return ;
	}
	int left = L ;
	int right = R;
	int pivot = array[left];
	while(left<right)
	{
		while(left<right&&array[right] >= pivot)
		{
			right-- ;
		}
		if(left<right)
		{
			array[left] = array[right];
		}
		while(left<right &&array[left] <= pivot)
		{
			left++;
		}
		if(left<right)
		{
			array[right] = array[left];
		}
		if(left >=right)
		{
			array[left] = pivot;
		}
	}
	quicksort(array,L,right-1);
	quicksort(array,left+1,R);
	
}
