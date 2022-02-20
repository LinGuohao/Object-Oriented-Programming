#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/counting.hpp"

using namespace std;



class Animal
{
    public:
     string name;
     int num;
     friend istream & operator >> (istream &is , Animal &am)
     {
        is>> am.name >> am.num;
        return is;
     }
};


class Makebool : public Counting<Animal>
{
    bool cond (const Animal &e) const override
      {
           return e.name == "bear";
      } 
        
};


class Line
{
    public :
    string name;
    string data;
    bool shotbeal;
    friend istream & operator >>(istream &is , Line &line)
    {
        string str;
        getline(is,str);
        stringstream ss(str);
        ss >> line.name >> line.data;
        Makebool tmp ;
        StringStreamEnumerator<Animal>enor(ss);
        tmp.addEnumerator(&enor);
        tmp.run();
        if(tmp.result() >0)
        {
            line.shotbeal = true;
        }else
        {
            line.shotbeal = false;
        }
        
       return is;


       
    }

};






class Hunter
{
    public:
     string name;
     bool shotbeal;
     Hunter(string tmpname,bool tmpbool)
     {
         name = tmpname;
         shotbeal = tmpbool;
     }
     Hunter()
     {

     }

};


class getHunter : public Summation<Line,Hunter>
{
   private:
       string _name;
    public:
        getHunter(const string &name) : _name(name) {}
    protected:
        Hunter func(const Line &e) const override {return Hunter(e.name,e.shotbeal );}
        Hunter neutral () const override {return Hunter("", false);}
        Hunter add(const Hunter &a , const Hunter &b) const override {return Hunter(a.name, a.shotbeal || b.shotbeal);}
        bool whileCond(const Line&e) const override {return _name == e.name;}
        void first() override {}
};

class Hunterenum : public Enumerator<Hunter>
{
    private :
      SeqInFileEnumerator<Line> *_f;
      Hunter _hunter;
      bool _end;
    public:
      Hunterenum (const string &fname) {_f = new SeqInFileEnumerator <Line> (fname);}
      ~Hunterenum() {delete _f;}
      void first() override{_f -> first();next();}
      void next() override;
      Hunter current() const override {return _hunter;}
      bool end() const override {return _end;}


};



void Hunterenum :: next()
{
    if (_f->end())
    {
        _end=true;
    }
    else
    {
        _end=false;
        _hunter.name = _f-> current().name;
        getHunter tmp(_hunter.name);
        tmp.addEnumerator(_f);
        tmp.run();
        _hunter = tmp.result();


    }
}

class getanswer : public Summation<Hunter,bool>
{
    public :
     bool func(const Hunter &e) const override {return e.shotbeal;}
     bool neutral() const override {return true;}
     bool add(const bool &a , const bool &b) const override  {return a && b;}

     

};



int main()
{
    bool l;
    getanswer ga;
    Hunterenum enor ("input.txt");
    ga.addEnumerator(&enor);
    ga.run(); 
    if(ga.result() ==true )
    {
        cout << "Yes" <<endl;
    }else
    {
        cout << "No" <<endl;
    }
   
}