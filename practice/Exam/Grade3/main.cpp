#include <iostream>
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/counting.hpp"

using namespace std;




class Detail
{
    public:
    string city;
    int type;
    int ticket;
     friend istream &operator >>(istream &is,Detail &detail )
     {
         is >> detail.city >> detail.type >> detail.ticket;
         return is;
     }
};


class getisindoor : public Summation<Detail,bool>
{
    public:
        bool func(const Detail &e) const override
        {
            if(e.type == 1)
            {
                return true;
            }else
            {
                return false;
            }
        }
        bool neutral() const override {return false;}
        bool add(const bool &a, const bool &b) const override {return a||b;}

};



class Line
{
    public:
        string name;
        string genre;
        bool isindoor;
        friend istream & operator>> (istream &is, Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>> line.name >> line.genre;
            StringStreamEnumerator<Detail> enor (ss);
            getisindoor gi;
            gi.addEnumerator(&enor);
            gi.run();
            line.isindoor = gi.result();
            return is;


        }
};



class getAnswer : public Counting<Line>
{
    bool cond(const Line &e) const override {return e.isindoor == true;}
};



int main()
{
    try
    {
        SeqInFileEnumerator<Line>enor("test5.txt");
        getAnswer ga;
        ga.addEnumerator(&enor);
        ga.run();
        cout << ga.result() <<"  bands are there with at least one indoor concerts."<<endl;
    }
    catch(SeqInFileEnumerator<Line> ::Exceptions exception)
    {
        cout << "Can not open file!"<<endl;
    }

}
