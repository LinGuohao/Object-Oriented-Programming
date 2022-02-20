#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"

using namespace std;


class Result
{
      public:
          string name;
          int grade;
          friend istream & operator>>(istream &is , Result&result)
          {
             is>>result.name >> result.grade;
             return is;
          }
};

class finalresult
{
     public :
         int num;
         bool isfail;
         finalresult(int tmpnum,bool tmpisfail)
         {
             num = tmpnum;
             isfail = tmpisfail;
         }
         finalresult()
         {

         }
};

class getfinalresult : public Summation<Result,finalresult>
{
      public:
          finalresult func(const Result &e) const override
          {
              if(e.grade == 5)
              {  
                 return  finalresult(1,false);
              }else if(e.grade == 1)
              {
                 
                 return finalresult(0,true);
              }else
              {
                  return finalresult(0,false);
              }
          }
         finalresult neutral() const override {return finalresult(0,false);}
         finalresult add(const finalresult &a , const finalresult &b) const override
         {
             return finalresult(a.num + b.num , a.isfail || b.isfail);
         }
         
             
};


class Line
{
    public:
     string name;
     string subject;
     int num;
     bool isfail;
     friend istream & operator >> (istream &is , Line &line)
     {
        string str;
        getline(is,str);
        stringstream ss(str);
        ss>> line.name >> line.subject;
        StringStreamEnumerator<Result>tmp(ss);
        getfinalresult gf;
        gf.addEnumerator(&tmp);
        gf.run();
        line.num = gf.result().num;
        line.isfail = gf.result().isfail;
         return is;

        


        
     }
};

class Student 
{
     public:
         string name;
         int num;
         bool isfail;
         Student(string tmpname,int tmpnum, bool tmpisfail)
         {
             name = tmpname;
             num = tmpnum;
             isfail = tmpisfail;
         }
         Student()
         {

         }
};


class getstudent : public Summation<Line,Student>
{
      private:
          string _name;
      public:
          getstudent(const string &name) : _name(name){}
      protected:
          Student func(const Line & e) const override {return Student(e.name,e.num,e.isfail);}
          Student neutral() const override { return Student("",0,true);}
          Student add(const Student&a , const Student&b) const override {return Student(b.name,a.num+b.num,a.isfail && b.isfail);}
          bool whileCond(const Line&e) const override {return e.name == _name;}
          void first() override{} 
};

class Studentenum : public Enumerator<Student>
{
    private:
        SeqInFileEnumerator<Line> *_f;
        Student _student;
        bool _end;
    public:
        Studentenum(const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}
        ~Studentenum() {delete _f;}
        void first() override {_f -> first(), next();}
        void next() override;
        Student current() const override {return _student;}
        bool end() const override {return _end;}
};

void Studentenum :: next()
{
    if (_f->end())
    {
        _end=true;
    }
    else
    {
        _end=false;
        _student.name = _f -> current().name;
        getstudent gs(_student.name) ;
        gs.addEnumerator(_f);
        gs.run();
        _student = gs.result();
        
    } 

};


class Write : public Summation<Student,ostream>
{
    public:
        Write(ostream* o) : Summation<Student,ostream>(o){}
    protected:
        string func(const Student &e) const override
        {
            ostringstream os;
            os<< e.name << " " << e.num<<" " <<endl;
            return os.str();
        }
        bool cond (const Student &e) const override {return e.isfail == true;}
};


int main()
{
    try
    {
        Studentenum enor("input.txt");
        Write w(&cout);
        w.addEnumerator(&enor);
        w.run();

    
    }
    catch(SeqInFileEnumerator<Line> ::Exceptions exc)
    {
         cout << "Can not open file"<<endl;
    }
    return 0;

}
