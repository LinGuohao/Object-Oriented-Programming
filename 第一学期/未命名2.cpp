#include <iostream>

using namespace std;




int main()


{
    int a,num;
    int c[1000];
    cout << "give the length of sequence-number: ";
    cin >> a;
    if (a>1000)
    {
        cout << "the length of sequence-number must smaller than 1000" << endl;
    }
    else if (a<1000)

    {
        for (num=1;num<a+1;num++)
        {
        cout <<"num" << num << ":";
        cin >> c[num];
        }
    cout << "the new sequence-number is: " << endl;
    for (num=1;num<a+1;num++)
        {

        if (c[num]==0)
        cout <<"num"<< num << ": " << 5 << endl;

        else
        cout <<"num"<< num << ": " << c[num] << endl;
        }
    }
        return 0;
}
