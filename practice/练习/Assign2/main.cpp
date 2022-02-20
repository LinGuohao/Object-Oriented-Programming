#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"
#include "../library/counting.hpp"

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
        bool func(const Fish& e) const override {return true;}
        bool neutral() const override {return false;}
        bool add (const bool &a,const bool &b) const override { return a||b;}

};




class Line
{
    public:
        string name;
        string championship;
        bool hasfish;
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
            line.hasfish = ml.result();
            return is;

        }
};




class Championship
{
    public:
        string name;
        bool hasfish;
        Championship()
        {

        }
        Championship(string tname, int thasfish)
        {
            name = tname;
            hasfish = thasfish;
        }
        
};


class getChampionship : public Summation<Line,Championship>
{
    private:
        string _name;
    public:
        getChampionship(const string &name) : _name (name){}
       // getChampionship(){}
    protected:
        Championship func (const Line &e) const override {return Championship(e.championship,e.hasfish );}
        Championship neutral() const override {return Championship("",false);}
        Championship add (const Championship&a, const Championship &b) const override {return Championship(b.name,a.hasfish||b.hasfish);}
        bool whileCond (const Line&e) const override {return e.championship == _name;}
        void first()override{}
};



class Championshipenum : public Enumerator<Championship>
{
    private:
        SeqInFileEnumerator<Line> * _f;
        Championship _championship;
        bool _end;
    public:
        Championshipenum(const string &fname){_f = new SeqInFileEnumerator<Line>(fname);}
        ~Championshipenum() {delete _f;}
        void first() override {_f -> first(),next();}
        void next() override;
        Championship current() const override {return _championship;}
        bool end() const override {return _end;}

};

void Championshipenum :: next()
{
    if (_f->end())
    {
        _end=true;
    }
    else
    {
        _end=false;
        _championship.name = _f -> current().championship;
        getChampionship gc(_championship.name);
        gc.addEnumerator(_f);
        gc.run();
        _championship = gc.result();



    }
}

class getAnwer : public Counting<Championship>
{
    public:
        
        bool cond (const Championship&e) const override {return e.hasfish == false;} 
};


int main()
{
    try
    {
        Championshipenum enor ("t13.txt");
        getAnwer ga;
        ga.addEnumerator(&enor);
        ga.run();
        cout<< ga.result()<< " championships has no fish been caught" <<endl;
        
    }
    catch(SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout << "Can not open file !!"<<endl;
    }
    return 0;
    
}
