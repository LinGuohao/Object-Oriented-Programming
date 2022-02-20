#include <iostream>
#include "../library/maxsearch.hpp"
#include"../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/summation.hpp"


using namespace std;

class Line
{
  public:
    string name;
    string hour;
    string min;
    int price;
    int num;
    friend istream& operator>>(istream &is, Line &line)
    {
        string str;
        getline(is,str);
        stringstream ss(str);
        ss >> line.name>>line.hour>>line.min >> line.price>>line.num;
        return is;
    } 
};

class food
{
    public:
     string name;
     int income;
};

class incomesum : public Summation<Line,int>
{
   private :
     string _name;
    public :
      incomesum(const string &name) : _name(name){}
    protected:
      int func (const Line&e) const override {return e.num * e.price ;}
      int neutral () const override {return 0;}
      int add(const int&a , const int &b) const override {return a + b;}
      bool whileCond(const Line&e) const override {return _name == e.name;}
      void first() override {}
};

class foodenum : public Enumerator<food>
{
       private:
         SeqInFileEnumerator<Line> *_f;
         food _food;
         bool _end;
       public:
         foodenum (const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}
         ~foodenum(){delete _f;}
         void first() override {_f -> first();next();}
         void next() override;
         food current() const override {return _food;}
         bool end() const override {return _end;}

};


void foodenum :: next()
{
     if(_f ->end())
    {
        _end =true;
    }else
    {
       _end = false;
       _food.name = _f ->current().name;
       incomesum tmp(_food.name);
       tmp.addEnumerator(_f);
       tmp.run();
       _food.income = tmp.result();
    }
}





class answergetter : public MaxSearch<food,int>
{
    int func(const food &e) const override
    {
        return e.income ;
    }
};


int main()
{
    try
    {
        answergetter ag;
        foodenum fe("in.txt");
        ag.addEnumerator(&fe);
        ag.run();
        if(ag.found ())
        {
              cout << ag.optElem().name<< " "<< ag.optElem().income<<endl;
        }else
        {
            cout << "Didnt find !"<<endl;
        }


    }
    catch(SeqInFileEnumerator<Line>::Exceptions exc)
     {
         cout << "Can not open this file"<<endl;
     }
    
}
