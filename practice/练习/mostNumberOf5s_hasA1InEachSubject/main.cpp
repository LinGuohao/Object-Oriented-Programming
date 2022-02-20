#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/summation.hpp"
#include "../library/counting.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/maxsearch.hpp"
using namespace std;


class Task
{
    public:
        string name;
        int grade;
        friend istream & operator >> (istream &is, Task& task)
        {
            is >>task.name >> task.grade;
            return is;
        }
};


class  Taskinline
{
    public:
        int num;
        bool hasone;
        Taskinline(int tnum, bool thasone)
        {
            num = tnum;
            hasone = thasone;
        }
        Taskinline(){}
};

class getTaskinline : public Summation<Task,Taskinline>
{
    public:
        Taskinline func (const Task & e) const override 
        {
            if(e.grade == 5)
            {
                return Taskinline(1,false);
            }else if(e.grade == 1)
            {
                return Taskinline(0,true);
            }else
            {
                return Taskinline(0,false);
            }
            
        }
        Taskinline neutral() const override {return Taskinline(0,false);}
        Taskinline add(const Taskinline &a , const Taskinline &b )const override{ return Taskinline(a.num+b.num, a.hasone||b.hasone);} 


};

class Line
{
    public:
        string name;
        string subject;
        int num;
        bool allhasone;
        friend istream & operator >> (istream &is, Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>> line.name >> line.subject;
            StringStreamEnumerator<Task> enor (ss);
            getTaskinline gt;
            gt.addEnumerator(&enor);
            gt.run();
            line.num = gt.result().num;
            line.allhasone = gt.result().hasone;
            return is;
            


        }

};






class Student 
{
    public:
        string name;
        int num;
        bool allhasone;
        Student(string tname, int tnum , bool tallhasone)
        {
            name = tname;
            num = tnum;
            allhasone = tallhasone;
        }
        Student(){}
};


class Studentenum : public Enumerator<Student>
{
    private:
        SeqInFileEnumerator<Line> *_f;
        Student _student;
        bool _end;
    public:
        Studentenum(const string &fname){ _f = new SeqInFileEnumerator<Line>(fname);}
        ~Studentenum(){delete _f;}
        void first() override {_f->first(),next();}
        void next() override;
        Student current() const override {return _student;}
        bool end() const override {return _end;}

};



class getStudent : public Summation<Line,Student>
{
    private:
        string _name;
    public:
        getStudent(const string &name) : _name(name){}
    protected:
        Student func (const Line&e) const override{return Student(e.name,e.num,e.allhasone); }
        Student neutral()const override {return Student("",0,true);}
        Student add(const Student&a , const Student&b) const override {return Student(b.name,a.num+b.num,a.allhasone && b.allhasone);}
        bool whileCond(const Line&e) const override {return e.name == _name;}
        void first() override{}
};

void Studentenum :: next()
{
    if(_f ->end())
    {
        _end = true;
    }else
    {
        _end = false;
        _student.name = _f -> current().name;
        getStudent gs(_student.name);
        gs.addEnumerator(_f);
        gs.run();
        _student = gs.result();
        
    }
    
};

class getAnswer : public MaxSearch<Student,int>
{
    public:
        int func(const Student&e) const override {return e.num;}
        bool cond (const Student &e) const override {return e.allhasone == true;}
};



int main()
{
    Studentenum enor ("input.txt");
    getAnswer ga;
    ga.addEnumerator(&enor);
    ga.run();
    if(ga.found())
    {
        cout<< ga.optElem().name<< " obtained the most total number of 5 grades among the students who obtained grade 1"<<endl;
        cout <<"The number of 5 is " <<ga.optElem().num<<endl;
    }else
    {
        cout << "Didnt find !"<<endl;
    }
    
}