#include <iostream>

using namespace std;

int main()
{
int n;
do {
cout << "give n: ";
cin >> n;
if (n<1) {cout << "error" << endl;}
} while (n<1);

/* cout << "give n: ";
cin >> n;
while (n<1){
cout << "error" << endl;
cout << "give n: ";
cin >> n;
}*/


int S[n];

for(int i=0;i<n;i++){
do{
cout << i+1 << ". number: ";
cin >> S[i];
if (S[i]>10 || S[i]<0){ cout << "error" << endl;}
} while(S[i]>10 || S[i]<0);
}
// modify items
for (int i=0;i<n;i++){
if (S[i]==0){
S[i]=5;
}
}
// write out
for (int i=0;i<n;i++){
cout << S[i] << " ";
}

return 0;
}
