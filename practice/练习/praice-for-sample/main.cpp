#include <iostream>
#include <vector>
#include <sstream>
#include "library/library/linsearch.hpp"
#include "library/library/seqinfileenumerator.hpp"
#include "library/library/stringstreamenumerator.hpp"
#include "library/library/summation.hpp"
#include "library/library/maxsearch.hpp"
using namespace std;
struct contestant {
    string name;
    string school;
    bool highjump;
};
struct contest {
    string sport;
    int place;

};
class MyMaxSearch : public MaxSearch<contest, int, Less<int>>
{
protected:
    int  func(const contest &e) const override { return e.place;}
};
class MySearch : public LinSearch<contest>
{
protected:
    bool cond(const contest &e) const override { return e.sport == "highjump"; }
};
int main()
{
    SeqInFileEnumerator<contest> enor("input1.txt");
    MyMaxSearch pr;
    pr.addEnumerator(&enor);
    pr.run();
    if(pr.found()&&pr.opt()==2){
        contest p= pr.optElem();
        cout<< "who participated in highjump: " << p.place<< endl;
        }
    else
        cout<< "no participant who has the best place is silver medal and participated in highjump" << endl;

    return 0;
}

istream& operator>>(istream& in,   contestant &e)
{
    string line;
    getline(in, line);
    stringstream is(line);
    is >> e.name >> e.school;
    StringStreamEnumerator<contest> tmp (is);
    MySearch pr;
    pr.addEnumerator(&tmp);
    pr.run();
    e.highjump=pr.found();
    return in;
}
istream& operator>>(istream& in, contest &e)
{
    in >> e.sport >> e.place;

    return in;
}

