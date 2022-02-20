#include"enor.h"
#include<iostream>
#include<fstream>
using namespace std;


istream&operator>>(istream &in,Student& tmp)
{
    in >> tmp.name >> tmp.subject >> tmp.result;
    return in;
}
ostream&operator<<(ostream &out,Grade &tmp)
{
    out << tmp.name <<" "<<tmp.cunt;
    return out;
}

Gradeenor::Gradeenor(const string &filename)
{
    _x.open(filename.c_str());
    if(_x.fail())
    {
        throw Error::FILE_OPEN_FAILED;
    }
}


void Gradeenor::read()
{
    if(_x>>_dx)
    {
        _sx = norm;
    }else
    {
        _sx = abnorm;
    }
}

void Gradeenor::next()
{
        _end = (_sx == abnorm);
        curr.name = _dx.name;
        curr.cunt = 0;
        while(_sx != abnorm && curr.name == _dx.name)
        {
           if(_dx.result == 5)
           {
               curr.cunt ++;
           }
           read();
        }
}



