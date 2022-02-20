#include <iostream>
#include "../library/seqinfileenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/enumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/counting.hpp"

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


class makebool 
{
    public:
        bool iscaught;
        int num;
        makebool(int tnum, bool tiscaught)
        {
            num = tnum;
            iscaught = tiscaught;
        }
        makebool(){}
};




class makeLine : public Summation<Fish,makebool>
{
    public:
        makebool func(const Fish &e) const override 
        {
            if(e.name == "Tuna")
            {
                return makebool(1,true);
            }else
            {
                return makebool(1,false);
            }
        }
        makebool neutral() const override 
        {
          return   makebool(0,true);
        }
        makebool add(const makebool&a,const makebool &b) const override {return makebool(a.num+b.num , a.iscaught && b.iscaught);}
};




class Line
{
    public:
        string name;
        string championship;
        bool iscaught;
        int num;
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
            line.num = ml.result().num;
            line.iscaught = ml.result().iscaught;
            



            return is;

        }
};


class Angler
{
    public:
        string name;
        bool iscought;
        int num;
        Angler(string tname, bool tiscought, int tnum)
        {
            name = tname;
            iscought = tiscought;
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
            return Angler(e.name,e.iscaught,e.num);
        } 
        Angler neutral() const override {return Angler("",true,0);}
        Angler add(const Angler&a,const Angler&b) const override {return Angler(b.name,a.iscought && b.iscought,a.num+b.num);}
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


class getresult : public Counting<Angler>
{
    public:
        bool cond(const Angler &e) const override 
        {
             if(e.num !=0 && e.iscought == true)
             {
                 return true;
             }else
             {
                 return false;
             }
             
        }
};






int main()
{
    try
    {
        Anglerenum enor("input.txt");
        getresult gr ;
        gr.addEnumerator(&enor);
        gr.run();
        if(gr.result() != 0)
        {
            cout<< gr.result()<<endl;
        }else
        {
            cout<< "No one!"<<endl;
        }
        
        
    }
    catch(SeqInFileEnumerator<Angler> :: Exceptions exception)
    {
        cout<< "Can not open file !" << endl;
    }
    
}
