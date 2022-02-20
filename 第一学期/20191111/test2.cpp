#include<iostream>
using namespace std;
int main(){
	int a[10]={1,1,5,3,5,7,6,9,7,0};
	int b[10]={0};
	int i,j;
	for(i=0;i<10;i++){
		j=a[i];
		b[j] = b[j]+1;	
	} 
	
	for(i=0;i<10;i++){
		if(b[i]>0){
			cout<<i<<"\t";
		}
	}
	
	return 0;
 
}

