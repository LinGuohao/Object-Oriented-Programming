//Author:   Guohao Lin
//Date:     2020.04.12
//Title:    3
#include<iostream>
#include<fstream>
#include"Enor.h"
#include<sstream>
#include<string>
using namespace std;


Enor::Enor(const string &filename)
{
    _x.open(filename.c_str());
    if(_x.fail())
    {
        throw FILE_OPEN_FAIL ;
    }

}

void Enor::read()
{
    if(!(_x.eof()))
    {
       _sx = norm;
       getline(_x,_dx,'\n');
       istringstream dx(_dx);
       string fisherman;
       dx>>fisherman;
       dx>> _name;
    }else
    {
        _sx = abnorm;
    }
}

void Enor::next()
{
    _end = (_sx == abnorm);
    if(!_end)
    {
        _curr.caught = false;
        _curr.ID = _name;
        while(_sx==norm && _curr.ID == _name )
        {
            _curr.caught = (_curr.caught || Judge(_dx));
            read();
        }
    }
}



bool Enor::Judge(string _dx)
{
    bool l = false;
    Fish onefish;
    string fisher;
    istringstream tmp (_dx);
    tmp>>fisher;
    tmp>>_name;
    while(tmp>>onefish.fishname>>onefish.size )
    {
      l = (l||onefish.fishname == "Tuna");
    }
     return l;
}
