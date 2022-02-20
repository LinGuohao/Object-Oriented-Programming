#include<iostream>
#include"enor.h"
#include<fstream>

using namespace std;
istream& operator>>(istream &is, Trans&tmp)
{

    is >> tmp.number >> tmp.date >> tmp.sum;
    return is;
}

Enor :: Enor (const string &str)
{

  _x.open(str.c_str());
  if(_x.fail())
  {
      throw Errors ::FILEERROR;
  }
}

void Enor::read()
{
    if(_x >> _dx)
    {
        _sx = norm;

     //   cout << _cur.balance<<endl;
   //  cout << 1 <<endl;
    }
    else
    {
        _sx = abnorm;

    }

}

void Enor:: next()
{
    _end = (_sx == abnorm);

    if(_sx == norm )
    {
         _cur.balance = 0;
        _cur.number =  _dx.number;
        while (_sx == norm && _cur.number  == _dx.number )
        {
            _cur.balance = _cur.balance + _dx.sum;
            read();
        }

    //    _cur.balance = sum;
     // cout << _cur.balance<<endl;
    }
}
