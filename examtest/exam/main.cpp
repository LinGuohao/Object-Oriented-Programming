/*
A motorbike service has registered the repairs of the different motorcycles in a textfile. One
line of the file contains the customer�s name, the type of the motorbike, and the repairs: nameprice pairs.
The file is ordered by customer names. You can assume that the file�s structure is
correct. One sample line of the file:

Customer1 YamahaAxis50 oilchange 20 motorblock 100 cablesealing 10

For grade 5: How many customers have at least two motorbikes that had a service more expensive than
95 euros?
*/
#include <iostream>
#include "library/summation.hpp"
#include "library/counting.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/maxsearch.hpp"
#include "library/linsearch.hpp"

using namespace std;

struct Repair{
    string name;
    int price;
    friend istream& operator>>(istream &is, Repair &r){
        is >> r.name >> r.price;
        return is;
    }
};

class Searching : public LinSearch<Repair>{
    bool cond(const Repair &r)const override{return r.price>95;}
};

struct Line{
    string customer;
    string motorbike;
    bool Price;
    friend istream& operator>>(istream &is, Line &l){
        string str;
        getline(is,str);
        stringstream ss (str);
        ss >> l.customer;
        ss >> l.motorbike;
        StringStreamEnumerator<Repair> enor(ss);
        Searching br;
        br.addEnumerator(&enor);
        br.run();
        l.Price = br.found();
        return is;
    }
};

struct Result{
    string name;
    int cntOfMotorBikes;
    bool pricegreaterthan;
    Result(): name(""), cntOfMotorBikes(0), pricegreaterthan(true) { }
    Result(string nm,int cnt, bool a) : name(nm), cntOfMotorBikes(cnt), pricegreaterthan(a) { }
};

class LineSummation : public Summation<Line,Result>{
private:
    string _name;
public:
    LineSummation(const string &fname) : _name(fname) { }
protected:
    bool whileCond(const Line &l)const override {return _name == l.customer;}
    void first()override{ }
    Result func(const Line &l)const override{return Result(l.customer,1,l.Price);}
    Result add(const Result &a,const Result &b)const override{return Result(b.name,a.cntOfMotorBikes+b.cntOfMotorBikes,a.pricegreaterthan&&b.pricegreaterthan);}
    Result neutral()const override {return Result();}
};

struct Customer{
    string name;
    int cntOfMotorBikes;
    bool pricegreaterthan;
};

class CustomerEnumerator : public Enumerator<Customer>{
private:
    SeqInFileEnumerator<Line>* _f;
    Customer _customer;
    bool _end;
    bool _empty;
public:
    CustomerEnumerator(const string &name): _empty(true) {_f = new SeqInFileEnumerator<Line>(name);}
    ~CustomerEnumerator(){delete _f;}
    bool end()const override{return _end;}
    void first()override{_f->first();next();if (!end()) _empty = false;}
    void next()override;
    bool isEmpty() const {return _empty;}
    Customer current()const override{return _customer;}
};

void CustomerEnumerator::next(){
    if(_f->end()){
        _end = true;
    }
    else{
        _end=false;
        _customer.name = _f->current().customer;
        LineSummation br(_customer.name);
        br.addEnumerator(_f);
        br.run();
        _customer.cntOfMotorBikes = br.result().cntOfMotorBikes;
        _customer.pricegreaterthan = br.result().pricegreaterthan;
    }
}

class Cnt : public Counting<Customer>{
    bool cond(const Customer &c)const override{return c.cntOfMotorBikes>1 && c.pricegreaterthan;}
};

int main(int argc,char** argv){
    try{
        string filename;
        if (argc > 1) filename = argv[1];
        else filename = "teszt5.txt";

        Cnt pr;
        CustomerEnumerator enor(filename);
        pr.addEnumerator(&enor);
        pr.run();
        if (enor.isEmpty()){
            cout << "The file is Empty." << endl;
        }
        else{
            if(pr.result()==0){
                cout << " Such customer didnt found: " << pr.result() << endl;
            }
            else{
                cout << " " << pr.result() << " Customers had at least two motorbikes that had a service more expensive than 95 euros "<< endl;
            }
        }
    }catch(SeqInFileEnumerator<Line>::Exceptions err){
        cout <<"Give a valid filename." << endl;
    }

    return 0;
}
