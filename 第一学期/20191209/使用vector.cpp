#include <iostream>
#include <vector>

using namespace std;

const int MaxN=1000;

typedef struct {
    string plate;
    int first;
    int last;
}car;

typedef struct {
    string plate;
    int cnt;
    int days;
}carstat;

int totaldays(const int N, car array[]);
int intheset(car X, vector<carstat> v);
string max_select(vector<carstat> v);

int main()
{
    /* Intro to VECTOR
    vector<int> v;
    int a=5;
    int b=7;
    v.push_back(a); v.push_back(b);
    cout << v.size() << endl;
    for (unsigned int i=0;i<v.size();i++) {
        cout << v[i] << endl;
    }
    */


    //Input
    car cars[MaxN];
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> cars[i].plate >> cars[i].first >> cars[i].last;
    }

    //Task 1
    int total;
    total=totaldays(N,cars);
    cout << "#" << endl;
    cout << total << endl;

    //Restructuring for Task 2 and 5
    vector<carstat> carset;
    for(int i=0;i<N;i++) {
        int index=intheset(cars[i],carset);
        if (index==-1) {
            carstat c;
            c.plate=cars[i].plate;
            c.cnt=1;
            c.days=cars[i].last-cars[i].first+1;
            carset.push_back(c);
        }
        else {
            carset[index].cnt++;
            carset[index].days+=cars[i].last-cars[i].first+1;
        }
    }

    //Task 2
    string maxcar;
    maxcar=max_select(carset);
    cout << "#" << endl;
    cout << maxcar << endl;


    //Restructuring for Task 3 and 4
    vector<int> D(31,0); //size: 31, filled with zeros
    for(int i=0;i<N;i++) {
        for (int j=cars[i].first;j<=cars[i].last;j++) {
            D.at(j)++;
        }
    }


    //Task 3
    int maxday=1;
    for (unsigned int i=2;i<D.size();i++) {
        if (D.at(i)>D.at(maxday)) {
            maxday=i;
        }
    }
    cout << "#" << endl;
    cout << maxday << endl;


    //Task 4
    int currmax=D.at(1);
    vector<int> maxs;
    for (unsigned int i=2;i<D.size();i++) {
        if (D.at(i)>currmax) {
            maxs.push_back(i);
            currmax=D.at(i);
        }
    }
    cout << "#" << endl;
    for (unsigned int i=0;i<maxs.size();i++) {
        cout << maxs.at(i) << " ";
    }
    if (maxs.size()==0) {cout << 0;}
    cout << endl;

    //Task 5 - after previous restructoring, it's just writing out
    cout << "#" << endl;
    for (unsigned int i=0;i<carset.size();i++) {
        cout << carset.at(i).plate << " " << carset.at(i).cnt << " " << carset.at(i).days << endl;
    }

    return 0;
}

int totaldays(const int N, car array[]) {
    int sum=0;
    for (int i=0;i<N;i++) {
        sum=sum+(array[i].last-array[i].first+1);
    }
    return sum;
}

string max_select(vector<carstat> v) {
    string max_plate;
    int max=0;
    for(unsigned int i=0;i<v.size();i++) {
        if (v.at(i).days>max) {
            max=v.at(i).days;
            max_plate=v.at(i).plate;
        }
    }
    return max_plate;
}

int intheset(car X, vector<carstat> v) {
    int index;
    unsigned int i=0;
    while (i<v.size() && v[i].plate!=X.plate) {
        i++;
    }
    if(i<v.size()) {
        index=i;
    }
    else{
        index=-1;
    }
    return index;
}


