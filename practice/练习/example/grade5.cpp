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
            if(e.name == "highjump")
            {
                return Num(true,1);
            }else
            {
                return Num(false,1);
            }
            
            
        }
        Num neutral() const override {return Num(false,0);}
        Num add (const Num &a,const Num &b) const override {return Num(a.istrue||b.istrue, a.num +b.num);}
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

class School 
{
    public:
    string name;
    int num;
    int numofjumper;
    School(string tname, int tnum, int tnumofjumper)
    {
        name =tname;
        num =tnum;
        numofjumper = tnumofjumper;
    }
    School ()
    {

    }
};

class getSchool : public  Summation<Line,School>
{
    private:
        string _name;
    public:
        getSchool(const string &name) : _name(name) {}
    protected:
        School func(const Line &e) const override 
        {
            if(e.istrue == true)
            {
                return School(e.school,1,1);
            }else
            {
                return School (e.school,1,0);
            }
            
        }
        School neutral() const override {return School("",0,0);}
        School add(const School &a,const School &b) const override {return School(b.name, a.num + b.num ,a.numofjumper+b.numofjumper);}
        bool whileCond(const Line &e) const override {return e.school == _name;}
        void first() override {}

};


class Schoolenum : public Enumerator<School>
{
   private:
        SeqInFileEnumerator<Line> *_f;
        School _school;
        bool _end;
    public:
        Schoolenum (const string &fname){_f = new SeqInFileEnumerator<Line>(fname);}
        ~Schoolenum(){delete _f;}
        void first() override {_f -> current(),next();}
        void next() override ;
        School current() const override {return _school;} 
        bool end() const override {return _end;}


};

void Schoolenum :: next()
{
    if (_f->end())
    {
        _end=true;
    }
    else
    {
        _end=false;
        _school.name = _f->current().school;
        getSchool gs(_school.name);
        gs.addEnumerator(_f);
        gs.run();
        _school = gs.result();


    }    
};

class Write : public Summation<School,ostream>
{
    public:
        Write(ostream *o): Summation<School,ostream> (o) {}
    protected:
        string func(const School &e) const override
        {
            ostringstream os;
            os<< e.name << " "<<e.num<<endl;
            return os.str();
        }
        bool cond (const School &e) const override {return e.numofjumper>=10;}
};




int main()
{
    try
    {
        Schoolenum enor("input.txt");
        Write w(&cout);
        w.addEnumerator(&enor);
        w.run();
        

    }
    catch(SeqInFileEnumerator<Line>::Exceptions err)
    {
         cout << "Cant open this file"<<endl ;
    }
    return 0;
        
}
