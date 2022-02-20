#include "foodEnor.h"

std::istream& operator>>(std::istream &is, Order &ord)
{
    is >> ord.foodName >> ord.hour >> ord.minute >>
          ord.orderCount >> ord.unitPrice;
    return is;
}

FoodEnor::FoodEnor(const std::string &fname)
{
    _f.open(fname.c_str());
    if(_f.fail())
    {
        throw FILE_ERROR;
    }
}

void FoodEnor::first()
{
    read();
    next();
}

void FoodEnor::next()
{
    _end = (_sx == abnorm);

    if(_sx == norm)
    {
        _current.foodName = _dx.foodName;
        //summation
        _current.income   = 0;
        while(_sx == norm && _current.foodName == _dx.foodName)
        {
            _current.income += _dx.orderCount * _dx.unitPrice;
            read();
        }
    }
}

void FoodEnor::read()
{
    if(_f >> _dx) _sx = norm;
    else _sx = abnorm;
}
