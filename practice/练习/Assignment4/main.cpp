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
        Fish(string tname, int tnum)
        {
            name = tname;
            num = tnum;
        }
        Fish(){}
        
};




class makeLine : public MaxSearch<Fish,int>
{
    public:
        int func(const Fish& e) const override {return e.num;}
        bool cond(const Fish&e) const override {return true;}

};




class Line
{
    public:
        string name;
        string championship;
        Fish fish;
        friend istream &operator >>(istream &is , Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>> line.name>>line.championship;
            makeLine ml;
            StringStreamEnumerator<Fish>enor(ss);
            ml.addEnumerator(&enor);
            ml.run();
            if(ml.found())
            {
                line.fish = ml.optElem();
            }else
            {
                line.fish = Fish("",0);
            }
            


            return is;
            

        }
};




class Championship
{
    public:
        string name;
        bool issalmon;
        Championship()
        {

        }
        Championship(string tname, bool tissalmon)
        {
            name = tname;
            issalmon = tissalmon;
        }
        
};


class getChampionship : public MaxSearch<Line,int>
{
    private:
        string _name;
    public:
        getChampionship(const string &name) : _name (name){}
       // getChampionship(){}
    protected:
        int func (const Line &e) const override {return e.fish.num;}
        bool cond(const Line &e) const override{return true;}
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
        if(gc.found())
        {
            if(gc.optElem().fish.name == "Salmon")
            {
                _championship.issalmon = true;
            }else
            {
                _championship.issalmon = false;
            }
        }else
        {
            _championship.issalmon = false;
        }
        



    }
}

class getAnswer : public LinSearch<Championship>
{
    public:
        bool cond(const Championship& i) const override
        {
            return i.issalmon == true;
        }

};
int main()
{
    try
    {
        Championshipenum enor ("t13.txt");
        getAnswer ga ;
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            cout <<"The championship called "<< ga.elem().name <<" where the largest caught fish was a salmon" <<endl;
        }else
        {
            cout << "Didnt find!"<<endl;
        }
        
    }
    catch(SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout << "Can not open file !!"<<endl;
    }
    return 0;
    
}
