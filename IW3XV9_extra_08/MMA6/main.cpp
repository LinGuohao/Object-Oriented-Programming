#include <iostream>
#include<string>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/Enumerator.hpp"

using namespace std;

class Hunting
{
    public:
    string name;
    int number;
    friend istream &operator>>(istream& is,Hunting &a)
    {
        is>>a.name>>a.number;
        return is;
    }

};



class Morebear : public Summation<Hunting, int>
{
    int func(const Hunting&e) const override {  }
    int neutral()const override{return 0;}
    int add(const int&a,const int&b) const override {return a + b;}
    bool cond(const Hunting&e) const override {return e.name == "bear";}
};


class Hunter
{
    public:
     string name;
     string date;
     bool l =false;
     friend istream &operator>>(istream& is,Hunter &st)
     {
         string line;
         getline(is,line);
         stringstream ss(line);
         ss>>st.name;
         ss>>st.date;
         Morebear myboolsummation;
         StringStreamEnumerator<Hunting>enor(ss);
         myboolsummation.addEnumerator(&enor);
         myboolsummation.run();
         //cout<<myboolsummation.result()<<endl;
         if(myboolsummation.result()>=2)
         {
             st.l = true;
         }else
         {
             st.l = false;
         }

         return is;

     }
};






class MyHunter: public Summation<Hunter,ostream>
{
    public:
    MyHunter(ostream*o) : Summation<Hunter,ostream>(o){}
    protected:
    string func(const Hunter &e)const override{
        ostringstream os;
        os<<e.name<<endl;
        return os.str();
    }
    bool cond(const Hunter&e)const override {return e.l;}
};




int main()
{
   try
   {
    SeqInFileEnumerator<Hunter>enor("input.txt");
    MyHunter writer(&cout);
    writer.addEnumerator(&enor);
    writer.run();
   }
   catch(SeqInFileEnumerator<Hunter> :: Exceptions exc)
   {
       cout<<"The file not exists."<<endl;

   }
   return 0;




}
