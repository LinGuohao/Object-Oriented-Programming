#include <iostream>
#include <string>
#include <sstream>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;


class Grade
{
    public:
        string name;
        double num;
        friend istream & operator >> (istream &is, Grade &grade)
        {
            is>> grade.name>>grade.num;
            return is;

        }
};


class finalgrade
{
    public :

       double grade;
       double num;
       finalgrade(double tgrade, double tnum)
       {
           grade = tgrade;
           num = tnum;
       }
       finalgrade()
       {

       }
};

class getfinalgrade : public Summation<Grade,finalgrade>
{
    public:
        finalgrade func (const Grade &e) const override {return finalgrade(e.num,1);}
        finalgrade neutral() const override {return finalgrade(0,0);}
        finalgrade add(const finalgrade&a, const finalgrade &b) const override{return finalgrade(a.grade+b.grade,a.num+b.num);}
};





class Line
{
    public :
   string name;
   string subject;
   double average;
   friend istream & operator >> (istream &is , Line &line)
     {
        string str;
        getline(is,str);
        stringstream ss(str);
        ss>> line.name >> line.subject;
        StringStreamEnumerator<Grade> tmp (ss);
        getfinalgrade gf ;
        gf.addEnumerator(&tmp);
        gf.run ();
        if(gf.result().num == 0)
        {
            line.average = 0;
        }else
        {
            line.average = gf.result().grade/gf.result().num;
        }

        return is;








     }

};

class getAnswer : public MaxSearch<Line,double>
{
   public :
        double func(const Line &e) const override {return e.average;}
        bool  cond(const Line&e) const override{return true;}
};



int main()
{
    try
    {
        getAnswer ga;
        SeqInFileEnumerator<Line> enor ("in.txt");
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            cout << ga.optElem().name << " "<< ga.optElem().subject<<" "<<ga.optElem().average<<endl;
            double tmp ;

        }else
        {
            cout << "Didnt find !!"<<endl;
        }


    }
    catch(SeqInFileEnumerator<Line> ::Exceptions exception)
    {
        cout << "Can not open file !!"<< endl;
    }
    return 0;
}
