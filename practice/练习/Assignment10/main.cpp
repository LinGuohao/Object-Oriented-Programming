#include <iostream>
#include "../library/seqinfileenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/enumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/linsearch.hpp"
using namespace std;



class Fish
{
    public:
        string name;
        string num;
        friend istream & operator>>(istream &is, Fish&fish)
        {
            is >> fish.name >> fish.num;
            return is;
        }
};



class makeLine : public Summation<Fish,bool>
{
    public:
        bool func(const Fish &e) const override 
        {
            if(e.name == "Tuna")
            {
                return true;
            }else
            {
                return false;
            }
        }
        bool neutral() const override {return false;}
        bool add(const bool&a,const bool&b) const override {return a||b;}
};




class Line
{
    public:
        string name;
        string championship;
        bool iscaught;
        friend istream & operator >> (istream &is, Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss >> line.name>>line.championship;
            StringStreamEnumerator<Fish> tmp (ss);
            makeLine ml;
            ml.addEnumerator(&tmp);
            ml.run ();
            line.iscaught = ml.result();
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
};



class getAngler : public Summation<Line,Angler>
{
    private:
        string _name;
    public:
        getAngler(const string& name) : _name(name){}
    protected:
        Angler func(const Line &e) const override 
        {
            if(e.iscaught == true)
            {
                return Angler(e.name,1);
            }else
            {
                return Angler(e.name,0);
            }
            
        } 
        Angler neutral() const override {return Angler("",0);}
        Angler add(const Angler&a,const Angler&b) const override {return Angler(b.name,a.num+b.num);}
        bool whileCond(const Line& e) const override {return e.name == _name;}
        void first() override {}
};


class Anglerenum : public Enumerator<Angler>
{
    private:
        SeqInFileEnumerator<Line>*_f; 
        Angler _angler;
        bool _end;
    public:
        Anglerenum(const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}
        ~Anglerenum() {delete _f;}
        void first() override {_f -> first(), next();}
        void next() override;
        Angler current() const override {return _angler;}
        bool end() const override {return _end;}
};


int main
{

}

void Anglerenum :: next()
{
    if(_f -> end())
    {
        _end = true;
    }else
    {
        _end = false;
        _angler.name = _f -> current().name;
        getAngler ga (_angler.name);
        ga.addEnumerator(_f);
        ga.run();
        _angler = ga.result();
    }
    
}

class Result 
{
    public:
    int num;
    bool iscaught;
    Result(int tnum , bool tiscaught)
    {
        num = tnum;
        iscaught = tiscaught;
    }
    Result(){}
};





class getresult : public Summation<Angler,bool>
{
    public:
        bool func(const Angler& e) const override {return e.num >=2;}
        bool neutral() const override {return true;}
        bool add(const bool&a , const bool&b) const override { return a && b;}
};


int main ()
{
    Anglerenum enor ("intput.txt");
    getresult gs ;
    gs.addEnumerator(&enor);
    gs.run();
    if(gs.result() == true)
    {
        cout << "It is true that all anglers caught tuna at at least two championships" <<endl;
    }else
    {
        cout << "Not true"<<endl;
    }
    
    
}






int main()
{
    try
    {
        Anglerenum enor("");
        getresult gr ;
        gr.addEnumerator(&enor);
        gr.run();
        if(gr.result().iscaught == true && gr.result().num != 0)
        {
            
            cout << "Yes !" <<endl;
        }else
        {
            cout << "No !" <<endl;
        }
        
    }
    catch(SeqInFileEnumerator<Angler> :: Exceptions exception)
    {
        cout<< "Can not open file !" << endl;
    }
    
}


class getAnswer : public LinSearch<Line>
{
    public :
        bool cond (const Line& i) const override
        {
            return i.iscaught == true;
        }
};

int main
{
    SeqInFileEnumerator<Line>enor("intput.txt");
    getAnswer ga;
    ga.run();
    g
    
}