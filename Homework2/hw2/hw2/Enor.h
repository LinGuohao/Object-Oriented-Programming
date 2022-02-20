//Author:   Guohao Lin
//Date:     2020.04.12
//Title:    3
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


struct Championship
{
    string ID;
    bool caught;
};

class Enor
{
public:

        enum error{FILE_OPEN_FAIL};
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
