/*
Given a file containing integer numbers. Calculate the sum of the numbers.
*/
#include <iostream>
#include "../library/seqinfileenumerator.hpp"
#include "../library/summation.hpp"

using namespace std;

class MySum : public Summation<int>
{
protected:
    int neutral() const override { return 0; }
    int add(const int &a, const int &b) const override { return a+b; }
    int func(const int &e) const override { return e;}
};

int main()
{
    MySum pr;
    SeqInFileEnumerator<int> enor("input.txt");
    pr.addEnumerator(&enor);

    pr.run();

    cout << "Sum: " << pr.result() << endl;

    return 0;
}
