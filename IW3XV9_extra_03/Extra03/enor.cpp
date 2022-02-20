#include<iostream>
#include<fstream>
#include "valley.h"
#include "enor.h"
using namespace std;

Vaenor::Vaenor(const string &infile)
{
    _x.open(infile);
    if(_x.fail()) throw FILEERROR;

}

void Vaenor::first()
{
    _x>>_tmp._e;
   // cout<<_tmp._a<<endl;
    _x>>_tmp._a;
   // cout<<_tmp._e<<endl;
    _x>>_tmp._k;
    //cout<<_tmp._k<<endl;


}

void Vaenor::next()
{
    int tmp;
    _x >> tmp;
    _tmp._e = _tmp._a;
    _tmp._a = _tmp._k;
    _tmp._k = tmp;
    //cout<<_tmp._k<<endl;
    if(_x.fail()){
    _st=abnorm;
 }
 else{
    _st=norm;
 }
}
void Vaenor::read()
{
    int dx;
    _x >> dx;
    if(_x.fail())
    {
        _st = abnorm;
    }
    else
    {
        _st = norm;
    }
}

