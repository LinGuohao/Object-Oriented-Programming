#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"
#include "../library/linsearch.hpp"
using namespace std;

class Part
{
public:
    string programming;
    double ranking;
    friend istream &operator>>(istream &is, Part &part)
    {
        is >> part.programming >> part.ranking;
        return is;
    }
};

class AllInfo
{
public:
    bool ishave;
    int number;
    AllInfo(bool tishave, int tnumber)
    {
        ishave = tishave;
        number = tnumber;
    }
    AllInfo() {}
};

class getAllInfo : public Summation<Part, AllInfo>
{
public:
    AllInfo func(const Part &e) const override
    {
        if (e.programming == "Haskell")
        {
            return AllInfo(true, 1);
        }
        else
        {
            return AllInfo(false, 1);
        }
    }
    AllInfo neutral() const override {return AllInfo(false,0);}
    AllInfo add(const AllInfo&a, const AllInfo&b) const override {return AllInfo(a.ishave||b.ishave, a.number + b.number);}
};

class Line
{
public:
    string name;
    string month;
    bool ishave;
    int number;
    friend istream &operator>>(istream &is, Line &line)
    {
        string str;
        getline(is, str);
        stringstream ss(str);
        ss >> line.name >> line.month;
        getAllInfo gi;
        StringStreamEnumerator<Part> enor(ss);
        gi.addEnumerator(&enor);
        gi.run();
        line.ishave = gi.result().ishave;
        line.number = gi.result().number;
        return is;

    }
};

class getAnswer:public MaxSearch<Line,int>{
    public:
        int func(const Line&e) const override{return e.number;}
        bool cond(const Line&e) const override {return e.ishave;}
};

int main()
{
    try
    {

        SeqInFileEnumerator<Line> enor("input2.txt");
        getAnswer ga;
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            cout << "The answer is " << ga.optElem().name <<" contains "<<ga.optElem().number<<" languages"<<endl;
        }else
        {
            cout << "Didnt find!!"<<endl;
        }
    }
    catch (SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout << "Can not open file!!" << endl;
    }
}