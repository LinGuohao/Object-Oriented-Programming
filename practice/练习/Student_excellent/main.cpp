#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"
using namespace std;


class Part
{
    public:
        string name;
        double mark;
        friend istream & operator >> (istream &is, Part &part)
        {
            is>> part.name >> part.mark;
            return is;
        }
};


class Subjectgrade 
{
    public:
        double number;
        double total;
        Subjectgrade(double tnumber, double ttotal)
        {
            number = tnumber;
            total = ttotal;
        }
        Subjectgrade(){}
};



class getSubjectgrade : public Summation<Part,Subjectgrade>
{
    public:
        Subjectgrade func (const Part& e) const override{return Subjectgrade(1,e.mark);} 
        Subjectgrade neutral() const override {return Subjectgrade(0,0);}
        Subjectgrade add(const Subjectgrade&a, const Subjectgrade&b) const override {return Subjectgrade(a.number+b.number, a.total + b.total);}

};

class Line 
{
    public:
        string name;
        string subject;
        double gpa;
        friend istream & operator >> (istream &is , Line &line )
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss >> line.name >> line.subject;
            getSubjectgrade gs;
            StringStreamEnumerator<Part> enor(ss);
            gs.addEnumerator(&enor);
            gs.run();
            if(gs.result().number ==0)
            {
                line.gpa = 0;
            }else
            {
                line.gpa = gs.result().total/ gs.result().number;
                
            }
            return is;



        }
};


class Student 
{
    public:
    string name;
    double number; 
    double total;
    Student (string tname, double tnumber, double ttoal)
    {
        name = tname;
        number = tnumber;
        total = ttoal;
    }
    Student(){}
    
};



class getStudent : public Summation<Line,Student>
{
    private:
        string _name;
    public:
        getStudent (const string&name) : _name(name){}
    protected:
        Student func (const Line &e) const override {return Student(e.name,1,e.gpa);}
        Student neutral() const override {return Student("",0,0);}
        Student add(const Student &a , const Student &b) const override {return Student(b.name,a.number+b.number,a.total+b.total);}
        bool whileCond(const Line&e) const override {return e.name ==_name;}
        void first() override {}
        
};

class finalstudent
{
    public:
        string name;
        double finalgrade;
        finalstudent(string tname, double tfinalgrade)
        {
            name = tname;
            finalgrade = tfinalgrade;
        }
        finalstudent(){}
};


class finalstudentenum : public Enumerator<finalstudent>
{
    private:
        SeqInFileEnumerator<Line> *_f;
        finalstudent _finalstudent;
        bool _end;
    public:
        finalstudentenum (const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}
        ~finalstudentenum(){delete _f;}
        void first() override {_f->first(),next();}
        void next() override;
        finalstudent current() const override {return _finalstudent;}
        bool end() const override{return _end;}

};



void finalstudentenum :: next()
{
    if(_f->end())
    {
        _end = true;
    }else
    {
        _end=false;
        _finalstudent.name = _f->current().name;
        getStudent gs (_finalstudent.name);
        gs.addEnumerator(_f);
        gs.run();
        if(gs.result().number == 0)
        {
            _finalstudent.finalgrade = 0;
        }else
        {
            _finalstudent.finalgrade = gs.result().total / gs.result().number;
            
        }
        



    }
    
}


class getAnswer : public MaxSearch<finalstudent,double>
{
    public:
        double func(const finalstudent&e) const override{return e.finalgrade;}
        bool cond (const finalstudent&e) const override {return true;}
};


int main()
{
    try
    {
        finalstudentenum enor ("input.txt");
        getAnswer ga;
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            cout << "The highest grade is " << ga.optElem().name <<" "<<ga.optElem().finalgrade<<endl;
        }else
        {
            cout << "Didnt find!!"<<endl;
        }

    }
    catch(SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout<< "Can not open file!!"<<endl;
    }
    
}
