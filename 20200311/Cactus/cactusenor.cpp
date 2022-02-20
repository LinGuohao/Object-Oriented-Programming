#include<iostream>
#include"cactusenor.h"
#include<fstream>


    void CactusEnor :: next()
    {

        _f>>_dx;
        if(_f.fail())
        {
            _sx = abnorm;
        }else
        {
            _sx = norm;
        }
    }
    CactusEnor::CactusEnor(const std::string& fname)
    {
        _f.open(fname.c_str());
        if(_f.fail())
        {
            throw FILE_ERROR;
        }
    }

