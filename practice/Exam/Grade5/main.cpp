#include <iostream>
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"
#include "../library/counting.hpp"
#include "../library/enumerator.hpp"
#include "../library/maxsearch.hpp"

using namespace std;




class Detail
{
    public:
    string city;
    int type;
    int ticket;
     friend istream &operator >>(istream &is,Detail &detail )
     {
         is >> detail.city >> detail.type >> detail.ticket;
         return is;
     }
};


class getindoor : public Counting<Detail>
{
    public:
        bool cond(const Detail &e) const override {return e.type == 1;}

};



class Line
{
    public:
        string name;
        string genre;
        int indoor;
        friend istream & operator>> (istream &is, Line &line)
        {
            string str;
            getline(is,str);
            stringstream ss(str);
            ss>> line.name >> line.genre;
            StringStreamEnumerator<Detail> enor (ss);
            getindoor gi;
            gi.addEnumerator(&enor);
            gi.run();
            line.indoor = gi.result();
            return is;


        }
};



class Genre
{
    public:
        string genrename;
        int indoor;
        Genre(string tgenrename , int tindoor)
        {
            genrename = tgenrename;
            indoor = tindoor;
        }
        Genre(){}
};


class getGenre : public Summation<Line,Genre>
{
    private:
        string _name;
    public:
        getGenre(const string &name) : _name(name){}
    protected:
        Genre func(const Line&e) const override {return Genre(e.genre,e.indoor);}
        Genre neutral() const override {return Genre("",0);}
        Genre add(const Genre&a, const Genre&b) const override {return Genre(b.genrename,a.indoor+b.indoor);}
        bool whileCond(const Line&e) const override {return e.genre == _name;}
        void first() override {}

};


class GenreEnum : public Enumerator<Genre>
{
    private:
        SeqInFileEnumerator<Line> *_f;
        Genre _genre;
        bool _end;
    public:
        GenreEnum(const string &fname) {_f = new SeqInFileEnumerator<Line>(fname);}
        ~GenreEnum(){delete _f;}
        void first() override {_f -> first(),next();}
        void next() override;
        Genre current() const override {return _genre;}
        bool end() const override {return _end;}
};

void GenreEnum :: next()
{
    if(_f ->end())
    {
        _end = true;
    }else
    {
        _end = false;
        _genre.genrename = _f->current().genre;
        getGenre gG(_genre.genrename);
        gG.addEnumerator(_f);
        gG.run();
        _genre = gG.result();

    }

};

class getAnswer : public MaxSearch<Genre,int>
{
    public:
        int func(const Genre&e) const override {return e.indoor;}
        bool cond(const Genre&e) const override {return true;}
};

int main()
{
    try
    {
        GenreEnum enor("test2.txt");
        getAnswer ga;
        ga.addEnumerator(&enor);
        ga.run();
        if(ga.found())
        {
            
            {
                 cout<< "The genre with the largest total number of indoor concerts is "<< ga.optElem().genrename<<endl;
                 cout <<"The number is " << ga.optElem().indoor<<endl;
            }
            
           
        }else
        {
            cout<< "Didnt find!"<<endl;
        }

    }
    catch(SeqInFileEnumerator<Line> ::Exceptions exception)
    {
        cout << "Can not open file!"<<endl;
    }

}
