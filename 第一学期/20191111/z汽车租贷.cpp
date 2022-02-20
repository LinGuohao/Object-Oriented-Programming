#include <iostream>

using namespace std;
typedef struct {
string pn;
int fd,ld;
}Trental;
typedef struct {
string pn;
int su,sumd;
}Tr2;

/* */
void ReadRentals(int cnt,Trental A[]);
/* seq. calculation */
int Subtsk1(int cnt,Trental A[]);
/* max. selection */
void SeqToSet(int cntA,Trental A[],
int &cntO,Tr2 O[]);
bool Element(string what,Tr2 Where[],
int cntW, int &ind);
/* max. sel for Helper array */
string Subtsk2(int cnt,Tr2 A[]);

int main()
{
int n;
// input
cin >> n;
Trental Rentals[n];
ReadRentals(n,Rentals);
int cnt1 = Subtsk1(n,Rentals);
cout << "#" << endl;
cout << cnt1 <<endl;
int cnt2=0;
Tr2 HelpS[n];
SeqToSet(n,Rentals,cnt2,HelpS);
string str = Subtsk2(cnt2,HelpS);
cout << "#" << endl;
cout << str << endl;

cout << "#" << endl;

cout << "#" << endl;
cout << "#" ;


return 0;
}
void ReadRentals(int cnt,Trental A[]){
for (int i=0;i<cnt;i++){
cin >> A[i].pn >> A[i].fd >> A[i].ld;
}
}
int Subtsk1(int cnt,Trental A[]){
int hv=0;
for (int i=0;i<cnt;i++){
hv += A[i].ld-A[i].fd+1;
}
return hv;
}

string Subtsk2(int cnt,Tr2 A[]){
int maxind=0;
//string maxval=A[0].pn;
for (int i=1;i<cnt;i++){
if (A[maxind].sumd<(A[i].sumd)){
maxind=i;
// maxval=A[i].pn;
}
}
// return maxval;
return A[maxind].pn;
}
/* I would find "what" in "Where" and give back
the index ("ind") where I have found...*/
bool Element(string what,Tr2 Where[],
int cntW, int &ind){
int i=0;
while(i<cntW && Where[i].pn!=what){
i++;
}
if(i<cntW) {
ind = i;
}
return (i<cntW);
}


void SeqToSet(int cntA,Trental A[],
int &cntO,Tr2 O[]){
int j=0;
cntO=0;
for (int i=0;i<cntA;i++){
if(Element(A[i].pn,O,cntO,j)){
O[j].sumd += A[i].ld-A[i].fd+1;
} else {
O[cntO].pn=A[i].pn;
O[cntO].sumd=A[i].ld-A[i].fd+1;
cntO++;
}
}
}

int Subtsk3(int cnt, Trental A[])
{
	int maxind = 1, maxval = 0 ;
	for(int i=1 ; i<=31;i++)
	{
		//cout how many cars...
		Cntdays=0;
		for(int j=0;j<cnt;j++)
		{
			if((A[j].fd <=i)&&(A[j].ld<=i))
			{
				cntdays++;
			}
		}
		if(cntdays>maxval)
		{
			maxind = i;
			maxval = cntdays;
		}
	}
}


