#include <iostream>
#include <string>

using namespace std;
typedef struct
{
int grade;
string name;
}Tstudent;

int main()
{
/* Tstudent st;
st.grade=2;
st.name="Troy";
cin >> st.name;*/

int n,ind;
bool exists;
cout << "n: ";
cin >> n;
Tstudent X[n];

//asking for grades
for (int i=0;i<n;i++){
do {
cout << i+1 << "th grade: ";
cin >> X[i].grade;
if (X[i].grade<1 || X[i].grade>5) {cout << "error" << endl;}
} while(X[i].grade<1 || X[i].grade>5);
cout << "name: ";

getline(cin,X[i].name,'\n');
cin.ignore();
}
// searching
int i=0;
while((i<n-1)&&(X[i].grade!=X[i+1].grade)){
i++;
}
exists=(i<n-1);
if (exists){
ind=i;
cout << ind+1 << ". student, grade: "
<< X[ind].grade << "with name: "
<< X[ind].name <<endl;
} else {
cout << "no ..." << endl;
}

return 0;
}

 
