#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"

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

class makeLine : public Summation<Fish,int>
{
    public:
        int func(const Fish& e) const override 
        {
            if(e.name == "Tuna")
            {
                return e.num;
            }else
            {
                return 0;
            }
            
        }



        int neutral() const override {return 0;}
        int add (const int &a,const int &b) const override { return a+b;}

};




class Line
{
    public:
        string name;
        string championship;
        int num;
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
            line.num = ml.result();
            return is;

        }
};




class Angler
{
    public:
        string name;
        int num;
        Angler(string tname, int tnum)
        {
            name = tname;
            num = tnum;
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
        Angler func (const Line &e) const override {return Angler(e.name,e.num);}
        Angler neutral() const override {return Angler("",0);}
        Angler add (const Angler&a, const Angler &b) const override {return Angler(b.name,a.num+b.num);}
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

class getAnwer : public MaxSearch<Angler,int>
{
    public:
        int func(const Angler&e) const override {return e.num;}
        bool cond (const Angler&e) const override {return true;} 
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
            if(ga.optElem().num != 0)
            {
                cout<< ga.optElem().name<<endl;
            }else
            {
                cout << "Didnt find"<<endl;
            }
            
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
