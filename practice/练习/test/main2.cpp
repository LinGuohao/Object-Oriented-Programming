#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"
using namespace std;

class anglerWithFish
{
    public:
        string name;
        bool caught;
        anglerWithFish(string tname, bool tcaught)
        {
            name = tname;
            caught = tcaught;
        }
        anglerWithFish(){}
};

class Part
{
    public:
        string fishname;
        int num;
         friend istream & operator >> (istream &is, Part &part)
        {
            is>> part.fishname>>part.num;
            return is;
        }
};


class getCaughtOrNot: public Summation<Part,bool>
{
    public:
        bool func(const Part& e) const override{
            if (e.fishname == "catfish" && e.num>30)
            {
                return true;
            }else
            {
                return false;
            }
            }
        bool neutral() const override{return false;}
        bool add(const bool&a,const bool &b) const override{return a||b;}
};

class Line
{
    public:
        string name;
        string game;
        bool caught;
        friend istream & operator >> (istream &is , Line &line )
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>>line.name>>line.game;
            getCaughtOrNot gf;
            StringStreamEnumerator<Part> enor(ss);
            gf.addEnumerator(&enor);
            gf.run();
            line.caught = gf.result();
            return is;
        }
};

class getAllCaughtOrNot:public Summation<Line,anglerWithFish>
{
    private:
        string _name;
    public:
        getAllCaughtOrNot (const string&name) : _name(name){}
    protected:
        anglerWithFish func(const Line&e) const override {return anglerWithFish(e.name,e.caught);}
        anglerWithFish neutral() const override {return anglerWithFish("",false);}
        anglerWithFish add(const anglerWithFish &a,const anglerWithFish &b ) const override {return anglerWithFish(b.name,a.caught||b.caught);}
        bool whileCond(const Line&e) const override {return e.name ==_name;}
        void first() override {}

};

class anglerenor : public Enumerator<anglerWithFish>
{   
    private:
        SeqInFileEnumerator<Line> *_f;
        anglerWithFish _anglerWithFish;
        bool _end;
    public:
        anglerenor(const string &fname){_f = new SeqInFileEnumerator<Line>(fname);}
        ~anglerenor(){delete _f;}
        void first()override{_f->first(),next();}
        void next() override;
        anglerWithFish current() const override {return _anglerWithFish;}
        bool end() const override{return _end;}
};

void anglerenor::next()
{
     if(_f->end())
    {
        _end = true;
    }else
    {
        _end=false;
        _anglerWithFish.name = _f -> current().name;
        getAllCaughtOrNot ga(_anglerWithFish.name);
        ga.addEnumerator(_f);
        ga.run();
         _anglerWithFish.caught = ga.result().caught;
        

    }
};


class getAnswer : public Summation<anglerWithFish,bool>
{
    public:
        bool func(const anglerWithFish& e) const override{ return e.caught;}            
        bool neutral() const override{return true;}
        bool add(const bool&a,const bool &b) const override{return a&&b;}
};

int main()
{
    anglerenor enor("input.txt");
    getAnswer ga;
    ga.addEnumerator(&enor);
    ga.run();
    if(ga.result())
    {
        cout<<"Every angler caught"<<endl;
    }else
    {
        cout<<"Not every angler caught"<<endl;
    }
}