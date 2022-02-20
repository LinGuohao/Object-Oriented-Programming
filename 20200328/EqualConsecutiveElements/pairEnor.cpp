#include "pairEnor.h"

PairEnor::PairEnor(const std::string &fname)
{
    _f.open(fname.c_str());
    if(_f.fail()){
        throw FILE_ERROR;
    }
}

void PairEnor::next()
{
    _current.first = _current.second;

    if(_f >> _current.second) _sx = norm;
    else _sx = abnorm;
}

void PairEnor::first()
{
    _f >> _current.first;
    if(_f >> _current.second) _sx = norm;
    else _sx = abnorm;
}
