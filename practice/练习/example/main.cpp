#include <iostream>
#include "../library/linsearch.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
using namespace std;


class Record
{
    public:
        string name;
        int grade;
        friend istream & operator >> (istream &is, Record &record)
        {
            is >> record.name >> record.grade;
            return is;
        }
};

class Num 
{
    public:
        bool istrue;
        int num;
        Num(bool tistrue, int tnum)
        {
            istrue = tistrue;
            num = tnum;
        }
        Num ()
        {

        }
};

class getNum : public Summation<Record,Num>
{
    public:
        Num func (const Record &e) const override
        {
            if(e.grade == 3  && e.name == "highjump")
            {
                return Num(true,0);
            }else if(e.grade == 2 && e.name =="highjump")
            {
                return Num(true,1);
            }else if(e.grade  == 2 &&e.name != "highjump")
            {
                return Num(false,1);
            }
            else if(e.grade == 1 || e.name !="highjump")
            {
                return Num(false,0);
            }else
            {
                return Num (false ,0 );
            }
            
        }
        Num neutral() const override {return Num(false,0);}
        Num add (const Num &a,const Num &b) const override {return Num(a.istrue||b.istrue, a.num +b.num);}
};


class isMeet : public Summation<Record, bool>
{
      public:
        bool func(const Record &e)const override {return e.name == "highjump" && e.grade == 2;}
        bool neutral () const override { return false;}
        bool add (const bool &a, const bool &b)  const override {return a || b; }
};

class Line
{
    public:
        string name;
        string school;
        bool istrue;
        int num;
        friend istream & operator >> (istream &is , Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>>line.name>>line.school;
            StringStreamEnumerator<Record> tmp (ss);
            getNum gm;
            gm.addEnumerator(&tmp);
            gm.run();
            line.istrue = gm.result().istrue;
            line.num = gm.result().num;
            return is;

        }
};


class getanswer: public LinSearch<Line>
{
    public:
       bool cond (const Line &i) const override
       {
           return i.istrue==true;
       }
};


int main()
{
    try
    {
        SeqInFileEnumerator<Line>enor("input.txt");
        getanswer ga;
        ga.addEnumerator (&enor);
        ga.run();
        if(ga.found() == true)
        {
            cout << ga.elem().school<<" " << ga.elem().num <<endl;
        }else
        {
            cout << "Didnt find !!" <<endl;
        }
        

    }
    catch(SeqInFileEnumerator<Line>::Exceptions err)
    {
         cout << "Cant open this file"<<endl ;
    }
        
}
