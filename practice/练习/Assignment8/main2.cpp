/*
The results of the National Angler's Championship is stored in a text file. Each line of the
file contains the identifier of the participant and the championship (strings without
whitespace), and the list of the caught fish, which are stored as pairs: (the kind of the fish,
the size of the fish). The kind of the fish is a string without whitespace, its size is a natural
number. The data in a line are separated by whitespace. The lines of the text file are sorted
according to the name of the participants. You can assume that the text file is correct.
An example for a line of the text file:

James BigLakeChampionship Tuna 50 Salmon 20 Sardine 5 Tuna 100

Which angler caught the most tuna?
*/
#include <iostream>
#include "../library/summation.hpp"
#include "../library/counting.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/maxsearch.hpp"
#include "../library/linsearch.hpp"

using namespace std;

struct Fish{
    string name;
    int size;
    friend istream& operator>>(istream &is,Fish &f){
        is >> f.name >> f.size;
        return is;
    }
};

class Cnt : public Counting<Fish>{
    bool cond(const Fish &f) const override{ return f.name == "Tuna";}
};

struct Line{
    string name;
    string contest;
    int TunaCount;
    friend istream& operator>>(istream &is, Line &l){
        string str;
        getline(is,str);
        stringstream ss(str);
        ss >> l.name;
        ss >> l.contest ;
        StringStreamEnumerator<Fish> enor(ss);
        Cnt br;
        br.addEnumerator(&enor);
        br.run();
        l.TunaCount = br.result();
        return is;
    }
};

class AllTunas : public Summation<Line,int>{
private:
    string _name;
public:
    AllTunas(const string &fname) : _name(fname) {}
protected:
    bool whileCond(const Line &l) const override {return _name == l.name;}
    void first()override{}
    int func(const Line &l)const override {return l.TunaCount;}
    int add (const int &a, const int &b) const override{return a+b;}
    int neutral()const override{return 0;}
};

struct Angler{
    string name;
    int Tunas;
};

class AnglerEnumerator : public Enumerator<Angler>{
private:
    SeqInFileEnumerator<Line>* _f;
    bool _end;
    Angler _angler;
public:
    AnglerEnumerator(const string &name) {_f = new SeqInFileEnumerator<Line>(name);}
    ~AnglerEnumerator(){delete _f;}
    bool end()const override{return _end;}
    Angler current()const override{return _angler;}
    void first()override {_f->first();next();}
    void next()override;
};

void AnglerEnumerator::next(){
    if(_f->end()){
        _end = true;
    }
    else{
        _end = false;
        _angler.name = _f->current().name;
        AllTunas pr(_angler.name);
        pr.addEnumerator(_f);
        pr.run();
        _angler.Tunas = pr.result();
    }
}

class MaxTunaAngler : public MaxSearch<Angler,int>{
    int func(const Angler &a) const override{return a.Tunas;}
};

/// James BigLakeChampionship Tuna 50 Salmon 20 Sardine 5 Tuna 100

int main(){
    try{
        MaxTunaAngler br;
        AnglerEnumerator enor("t13.txt");
        br.addEnumerator(&enor);
        br.run();
        if(br.found()){
            cout << br.optElem().name << " caught " << br.optElem().Tunas << " Tunas which make him max." << endl;
        }
        else{
            cout << "there was no angler who caught at least 1 Tuna\n";
        }
    }catch(SeqInFileEnumerator<Line> :: Exceptions exc){
        cout << "No file\n";
    }
    return 0;
}






