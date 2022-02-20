#include "enor.h"

using namespace std;

Enor::Enor(const string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

//the next() method has two tasks:
//1. indicating whether the enumeration is over by setting
//   the value of the member _end
//2. producing the next enumerated element by setting
//   the member _cur
//Notice that next() will not return anything to us. It just sets
//the values of _end and _cur. After that, we can get these
//values by calling the end() and current() methods.
void Enor::next()
{
    _end = (abnorm==_sx);
    if (!_end) {
        //_cur.number: the given number in the file
        //_cur.count: the number of occurrences of the given number,
        //            we determine its value by using the counting
        //            algorithmic pattern
        _cur.number = _dx;
        _cur.count = 0;
        for( ; norm==_sx && _dx==_cur.number ; read() ){
            ++_cur.count;
        }
    }
}

// implementation of the abstract sx,dx,x: read operation
void Enor::read()
{
/*  short form:
    _sx = (_x >> _dx) ? norm : abnorm;
*/
    _x >> _dx;
    //we have to try to read from the file first in order to
    //be able to check (call the fail() method) whether
    //the file is empty
    if ( _x.fail() ) _sx = abnorm;
    else _sx= norm;
}
