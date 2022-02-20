#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "../library/enumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/maxsearch.hpp"
using namespace std;
class Data_part
{
    public:
    int mins;
    int sec;
    int dis;
    int score;

    friend istream & operator >> (istream &is, Data_part &part)
        {
            is>> part.mins>> part.sec>>part.dis>>part.score;
            return is;
        }// reading operator
};

class Player// for each line
{
    public:

    int total;
        Player(int ttotal)
        {
            total = ttotal;

        }// constructor
        Player(){}// default constructor
};

class getPlayer : public Summation<Data_part,Player>
{
    public:
        Player func (const Data_part& e) const override{return Player((e.score==0)?0:1);}
        Player neutral() const override {return Player(0);}// neutral element(inital element)
        bool cond(const Data_part& e) {return (e.score>0);}
        Player add(const Player &p1, const Player &p2) const override
        {
            return Player(p1.total+p2.total);
        }

};// for getting the total number of success shot

class Line// how to read from the line
{
public:
    string name1;
    string name2;
    string city;
    int total_success;
    friend istream & operator >> (istream &is , Line &line )// we need to define a reading operator for reading the stream
        {
            string str;
            getline(is,str);// put the stream into the string
            stringstream ss(str);// take out the data int the string
            ss >> line.name1 >> line.name2>>line.city;// we need to first read the name and the subject
            getPlayer gs1;
            StringStreamEnumerator<Data_part> enor(ss);
            gs1.addEnumerator(&enor);
            gs1.run();
            line.total_success=gs1.result().total;

            return is;
            }
};// now we get the number of success shot in each line

// now we do the grouping
class Player_g
{
public:
    string name1;

    int suc_shot;
    Player_g(string n1, int suc)
    {
        name1=n1;

        suc_shot=suc;
    }
    Player_g(){}
};

class getPlayer_g:public Summation<Line,Player_g>
{
private:
    string _name;
    public :getPlayer_g(const string&name):_name(name){};
    protected:
        Player_g func(const Line&e) const override {return Player_g(e.name1,e.total_success);}
        Player_g neutral() const override {return Player_g("",0);}
        Player_g add(const Player_g &a , const Player_g &b) const override {return Player_g(b.name1,a.suc_shot+b.suc_shot);}
        bool whileCond(const Line&e) const override {return e.name1 ==_name;}
        void first() override {}
};

class finalPlayer
{
    public:
        string name;
        int final_suc;// this is the final suc shot that we get
        finalPlayer(string tname, int tfinalgrade)
        {
            name = tname;
            final_suc = tfinalgrade;
        }
        finalPlayer(){}
};

class FinalPlayerEnum : public Enumerator<finalPlayer>// this is the enumerator that we need to define, to calculate the final gpa of each line because there is not such default thing in the template liberay
{
    private:
        SeqInFileEnumerator<Line> *_f;
        finalPlayer _finalPlayer;
        bool _end;
    public:
        FinalPlayerEnum(const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}

        void first() override {_f->first(),next();}
        void next() override;
        finalPlayer current() const override {return _finalPlayer;}
        bool end() const override{return _end;}

};

void FinalPlayerEnum::next()
{
    if(_f->end())
    {
        _end = true;
    }else
    {
        _end=false;
        _finalPlayer.name = _f->current().name1;
        getPlayer_g gs (_finalPlayer.name);
        gs.addEnumerator(_f);
        gs.run();
        _finalPlayer.name=gs.result().name1;
         _finalPlayer.final_suc=gs.result().suc_shot;


    }

}// calculating the final suc shot


class getAnswer : public MaxSearch<finalPlayer,int>
{
    public:
        int func(const finalPlayer&e) const override{return e.final_suc;}
        bool cond (const finalPlayer&e) const override {return true;}
};

int main()
{
     try
    {
        FinalPlayerEnum enor ("test5.txt");
        getAnswer ga;
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            cout << "The highest shot is " << ga.optElem().name <<" "<<ga.optElem().final_suc<<endl;
        }else
        {
            cout<<"Didnt find!"<<endl;
        }

    }
    catch(SeqInFileEnumerator<Line>::Exceptions exception)
    {
        cout<< "Can not open file!!"<<endl;
    }

}
