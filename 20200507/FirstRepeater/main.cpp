/*
Problem: given an array containing integer numbers. Find the first element (by providing its position) that
occurs again in the array. The elements of the array should be read from a file.
*/

#include <iostream>
#include <vector>

#include "../library/seqinfileenumerator.hpp"
#include "../library/intervalenumerator.hpp"
#include "../library/linsearch.hpp"
#include "../library/summation.hpp"
#include "../library/intervalenumerator.hpp"

using namespace std;

// The vector of the elements is constructed by applying the Summation algorithmic pattern.
// func(e)=e for any e element, it is inserted into the vector by using the push_back method in the body()
// method of the Summation class.
// In this version of the template class (where the second parameter is a vector), we do not define
// the add() and neutral() methods. See lecture slides, week 10 slide 24 for more details.
class Copy : public Summation<int, vector<int> >
{
    int  func(const int &e) const override { return e; }
};

class InnerSearch : public LinSearch<int>
{
private:
    vector<int> _x;
    int _i;
public:
    InnerSearch(vector<int> x, int i) : _x(x), _i(i) {}
    bool cond(const int &j) const override { return _x[_i] == _x[j]; }
};

class OuterSearch : public LinSearch<int>
{
private:
    vector<int> _x;
public:
    OuterSearch(vector<int> x) : _x(x) {}

    // Property we are looking for: there exists an element upto the position i-1 that equals to x[]i
    bool cond(const int &i) const override
    {
        InnerSearch pr(_x, i);
        IntervalEnumerator enor(0, i-1);
        pr.addEnumerator(&enor);
        pr.run();
        return pr.found();
    }
};

int main()
{
    // Filling in the vector using the summation algorithmic pattern
    vector<int> x;
    Copy pr1;
    SeqInFileEnumerator<int> enor1("input.txt");
    pr1.addEnumerator(&enor1);
    pr1.run();
    x = pr1.result();

    // We are looking for the first element in the vector that occurs again.
    // The element will be given by providing its index. To do so, we traverse the interval of
    // indexes.
    OuterSearch pr2(x);
    IntervalEnumerator enor2(1, x.size()-1);
    pr2.addEnumerator(&enor2);
    pr2.run();

    if(pr2.found())
        cout  << x[pr2.elem()] << " occured again first.";
    else
        cout << "There are only unique elements, none of them is repeated.\n";
    return 0;
}







