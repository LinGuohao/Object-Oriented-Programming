#include <iostream>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"

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
        bool func(const Fish& e) const override {return e.name == "Tuna";}
        bool neutral() const override {return false;}
        bool add (const bool &a,const bool &b) const override {return a || b;}

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




class Championship
{
    public:
        string name;
        bool iscaught;
        Championship()
        {

        }
        Championship(string tname, bool tiscaught)
        {
            name = tname;
            iscaught = tiscaught;
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
        Championship func (const Line &e) const override {return Championship(e.championship,e.iscaught);}
        Championship neutral() const override {return Championship("",false);}
        Championship add (const Championship&a, const Championship &b) const override {return Championship(b.name,a.iscaught||b.iscaught);}
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
        gc.run();;
        _championship = gc.result();



    }
}

class Write : public Summation<Championship , ostream>
{
    public:
        Write(ostream *o) : Summation<Championship,ostream>(o){}
    protected:
        string func(const Championship&e)const override
        {
            ostringstream os;
            os<<e.name<<endl;
            return os.str();
        }
        bool cond(const Championship &e) const override {return e.iscaught == true;}
};

int main()
{
    try
    {
        Championshipenum enor ("input.txt");
        Write w (&cout);
        w.addEnumerator(&enor);
        w.run();
    }
    catch(SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout << "Can not open file !!"<<endl;
    }
    return 0;
    
}
