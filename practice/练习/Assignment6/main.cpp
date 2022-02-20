#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"
#include "../library/linsearch.hpp"

using namespace std;



class Fish
{
    public:
        string name;
        int num;
        friend istream &operator >> (istream &is , Fish &fish)
        {
            is >> fish.name >> fish.num;
            return is;
        }
        
};

class makeLine : public Summation<Fish,bool>
{
    public:
        bool func(const Fish& e) const override {
            if(e.name == "Sardine")
            {
                return true;
            }else
            {
                return false;
            }
            
        }
        bool neutral() const override {return false;}
        bool add (const bool &a,const bool &b) const override { return a || b;}

};




class Line
{
    public:
        string name;
        string championship;
        bool iscaught;
        friend istream &operator >>(istream &is , Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>> line.name>>line.championship;
            StringStreamEnumerator<Fish> enor (ss);
            makeLine ml;
            ml.addEnumerator(&enor);
            ml.run();
            line.iscaught = ml.result();
            return is;

        }
};




class Angler
{
    public:
        string name;
        bool iscaught;
        int num;
        Angler(string tname,bool tiscaught,int tnum)
        {
            name = tname;
            num = tnum;
            iscaught = tiscaught;
        }
        Angler(){}

} ;



class getAngler : public Summation<Line,Angler>
{
    private:
        string _name;
    public:
        getAngler(const string &name) : _name (name){}
       // getChampionship(){}
    protected:
        Angler func (const Line &e) const override {return Angler(e.name,e.iscaught,1);}
        Angler neutral() const override {return Angler("",true,0);}
        Angler add (const Angler&a, const Angler &b) const override {return Angler(b.name,a.iscaught && b.iscaught,a.num+b.num);}
        bool whileCond (const Line&e) const override {return e.name == _name;}
        void first()override{}
};



class Anglerenum : public Enumerator<Angler>
{
    private:
        SeqInFileEnumerator<Line> * _f;
        Angler _angler;
        bool _end;
    public:
        Anglerenum(const string &fname){_f = new SeqInFileEnumerator<Line>(fname);}
        ~Anglerenum() {delete _f;}
        void first() override {_f -> first(),next();}
        void next() override;
        Angler current() const override {return _angler;}
        bool end() const override {return _end;}

};

void Anglerenum :: next()
{
    if (_f->end())
    {
        _end=true;
    }
    else
    {
        _end=false;
        _angler.name = _f -> current().name;
        getAngler gc(_angler.name);
        gc.addEnumerator(_f);
        gc.run();
        _angler = gc.result();



    }
}

class getAnwer : public LinSearch<Angler>
{
    public:
        
        bool cond (const Angler&e) const override {return e.iscaught == true && e.num!=0;} 
};


int main()
{
    try
    {
        Anglerenum enor ("t13.txt");
        getAnwer ga;
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            cout<<ga.elem().name<<" caught a sardine at all "<<ga.elem().num<<" championships"<<endl;
            
        }else
        {
            cout << "Didnt find"<<endl;
        }
        
    }
    catch(SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout << "Can not open file !!"<<endl;
    }
    return 0;
    
}
