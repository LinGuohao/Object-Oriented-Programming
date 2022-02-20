#include <iostream>

using namespace std;

typedef struct {
string name;
int allowed, consumed;
} patient;

int main()
{
int n,i; // how many patient
string answer;
bool exists;
do {
cout << "give n: ";
cin >> n;
if (n>50 || n<2) cout << "error" << endl;
} while(n>50 || n<2);
patient data[n];
// read the input
for (i=0;i<n;i++){
cout << "give the " << i+1 << ".name: ";
cin.ignore();
getline(cin,data[i].name,'\n');
cout << "alloved and consumed: ";
cin >> data[i].allowed >> data[i].consumed;
}
for (i=0;i<n;i++){
cout << data[i].name << " " <<
data[i].allowed << " " <<
data[i].consumed << endl;

}
// task a)
int maxind=-1;
int maxval=0;
for (i=0;i<n;i++){
int exc=data[i].consumed-data[i].allowed;
if (exc>maxval){
maxind=i;
maxval=exc;
}
}
if (maxval>0){
answer=data[maxind].name;
} else answer="None";
//output the result in task a)
cout << answer << endl;

// task b)
int cnt=0;
i=0;
while(i<n && cnt<3){
if (data[i].consumed<=data[i].allowed) {
cnt++;
}
i++;
}
exists=(cnt==3);
//output the result in task b)
if (exists){
cout << "exists" << endl;}
else {cout << "not exists" << endl;}

return 0;
}
