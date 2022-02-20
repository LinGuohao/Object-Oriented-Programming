#include <iostream>

using namespace std;
struct data{
	string status;
	string name;
	int hour ;
	int minu ;
};

int main()
{
    int N;
    cin >> N;
    struct data arr[N];
    for (int i = 0; i < N; i++){
        cin>>arr[i].status>>arr[i].name>>arr[i].hour>>arr[i].minu;
    }
    int d,a=0,b=0;
   
   
   
    for (int i = 0 ; i<N ; i++){
                    here:
       for (int j = 0 ; j < N ; j++ ){
            if(arr[i].name==arr[j].name){
               if(arr[j].status=="BE"){
                   for (int z = j+1 ; z < N ; z++ ){
                       if(arr[z].status=="KI" && arr[j].name==arr[z].name){
                         a=a+(arr[z].hour-arr[j].hour)*60+(arr[z].minu-arr[j].minu);
                           goto here;
                           //break;
                         }
                   }
               }



            }
        }
            if (a>b){
                   d=i;
                    b=a;
          }

    }

    cout << arr[d].name;
    return 0;
}
