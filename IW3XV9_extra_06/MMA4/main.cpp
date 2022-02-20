#include <iostream>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/counting.hpp"

using namespace std;

struct Line
{
    string name;
    string subject;
    int grade;
    friend istream& operator>>(istream &is, Line &line)
    {
        string str;
        getline(is,str);
        stringstream ss(str);
        ss>> line.name  >> line.subject>>line.grade;
        return is;
    }
};

struct student
{
    string name;
    int num;
};


class countnum : public Counting <Line>
{
     private:
       string _name;
     public:
       countnum(const string&name) : _name(name){}
     protected:
       bool cond(const Line&e) const override{return e.grade == 5 ;}
      bool whileCond(const Line&e)  const override {return e.name == _name;}
      void first() override{}
};


class studentenum : public Enumerator<student>
{
   private:
      SeqInFileEnumerator<Line> *_f;
      student _student;
      bool _end;
    public:
      studentenum(const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}
      ~studentenum(){delete _f;}
      void first() override {_f -> first();next();}
      void next() override;
      student current() const override {return _student;}
      bool end() const override {return _end;}

};

void studentenum :: next ()
{
    if(_f ->end())
    {
        _end =true;
    }else
    {
        _end = false;
        _student.name = _f -> current().name;
        countnum tmp(_student.name);
        tmp.addEnumerator(_f);
        tmp.run();
        _student.num = tmp.result();

    }
}


class studentanswer : public MaxSearch<student,int>
{
    int func(const student &e) const override
    {
        return e.num;
    }
};

int main()
{
     try
     {
         studentanswer answer;
         studentenum enor("input.txt");
         answer.addEnumerator(&enor);
         answer.run();
         if(answer.found())
         {
             cout<<answer.optElem().name<<" "<<answer.optElem().num<<endl;
         }
         else
         {
             cout<< "No one get 5"<<endl;
         }
     }
     catch(SeqInFileEnumerator<Line>::Exceptions exc)
     {
         cout << "Can not open this file"<<endl;
     }


}




