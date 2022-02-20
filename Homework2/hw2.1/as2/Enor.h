#ifndef ENOR_H
#define ENOR_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct Fish
{

    string fishname;
    int size;
};

struct tmpchampionship
{
    string fisher;
    string name;
    bool hastuna;
};

struct Championship
{
    string ID;
    bool caught;
};

class Enorline
{
public:
    enum error{FILE_OPEN_FAIL};
    void next();
    void current(){return _curr };
private:
    ifstream _x;
    tmpchampionship _curr;


};



class Enor
{
public:


        enum Status{norm,abnorm};
        Enor(const string &str);
        bool end()const{return _end;};
        bool Judge(string _dx);
        Championship current()const{return _curr;};
        ~Enor(){_x.close();};
        void first(){read();next();};
        void next();



private:

        ifstream _x;
        string _dx;
        Status _sx;
        Championship _curr;
        bool _end;
        string _name;
        void read();

};




#endif // ENOR_H
