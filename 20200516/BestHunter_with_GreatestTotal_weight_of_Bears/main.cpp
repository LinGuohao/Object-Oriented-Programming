// This is a grade 3 level problem.
/*
Given a file containing data of huntings. Each line of the file consists of the
name of a hunter (string not containing spaces), the date of the hunting and the
animals - as (kind, weight) pairs - shot by the given hunter at the given hunting.

Find the hunter, who shot animals with the highest total weight of bears
at any of his/her huntings. Also provide the date of hunting.
*/
#include <iostream>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;

struct Animal
{
    string name;
    int weight;
    friend istream &operator>>(istream& is,Animal &a)
    {
        is >> a.name >> a.weight;
        return is;
    }
};

// An algorithmic pattern will be used to calculate the total weight of bears shot at a given hunting.
// Please note, in order to calculate this sum, Animal type of elements will be enumerated. The f function (called by func in the Summation
// class) of the summation takes an Animal and gives the weight of the animal.
// Please also note that we do not want to calculate the sum of Animals, instead we want to sum the values of f, which are integer
// numbers (weight of animals). Therefore, the operands of add() method are integer numbers.
class TotalWeightOfBears : public Summation<Animal,int>
{
    int func(const Animal& e) const override { return e.weight; }
    int neutral() const override { return 0; }
    int add( const int& a, const int& b) const override { return a+b; }
    // It is a special summation that does not take all the animals shot at a hunting into account, but only bears.
    bool cond(const Animal& e) const override { return e.name=="bear"; }
};

// A Hunting type of element stores the essential information of a line of the inputfile:
// name of the hunter, date of the hunting, the total weight of bears shot
struct Hunting
{
    public:
    string name;
    string date;
    int totalweight;
    friend istream &operator>>(istream& is,Hunting &h)
    {
        string line;
        getline(is,line);
        stringstream ss(line);
        ss >> h.name;
        ss >> h.date;

        TotalWeightOfBears pr;
        StringStreamEnumerator<Animal> enor(ss);
        pr.addEnumerator(&enor);
        pr.run();
        h.totalweight = pr.result();
        return is;
    }
};

class BestHunter : public MaxSearch<Hunting,int>
{
    int func(const Hunting& e) const override
    {
        return e.totalweight;
    }
    // in case the total weight of bears shot is 0, then the given hunter did not shot a bear at his/her given hunting
    bool cond(const Hunting& e) const override
    {
        return e.totalweight>0;
    }
};

int main()
{
    try
    {
        SeqInFileEnumerator<Hunting> enor("input.txt");

        BestHunter bs;
        bs.addEnumerator(&enor);
        bs.run();
        if (bs.found())
        {
            cout << "Best hunter: "<< bs.optElem().name << ", date of the hunting: " << bs.optElem().date << endl;
            cout     << "Total weight of bears shot: "<< bs.opt() << endl;
        } else
        {
            cout << "Bears were not shot at all.";
        }
    }
    catch (SeqInFileEnumerator<Hunting>::Exceptions err)
    {
        cout<<"File not found.";
    }
    return 0;
}
