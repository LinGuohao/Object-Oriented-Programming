#include "hunterenor.h"

//"converting" a line of the input into a Hunting struct
std::istream &operator>>(std::istream &is,Hunting &h)
{
    std::string line;
    getline(is,line,'\n');
    std::istringstream ss(line);
    ss >> h.hunterName >> h.date;
    Animal a;
    h.animals.clear();
    while (ss >> a.name >> a.weight)
    {
        h.animals.push_back(a);
    }
    return is;
}

//method containsBear enables us to decide whether a bear has been shot at a given hunting
bool Hunting::containsBear() const
{
    bool l = false;
    for (int i = 0 ; i < animals.size() && !l ; i++)
    {
        l = animals[i].name == "bear";
    }
    return l;
}


HunterEnor::HunterEnor(const std::string &fileName)
{
    _f.open(fileName.c_str());
    if (_f.fail())
        throw OPEN_ERROR;
}

void HunterEnor::first()
{
    read();
    next();
}

void HunterEnor::next()
{
    if (_sx!=norm)
    {
        _end = true;
    }
    else
    {
        _end = false;
        _act.name = _dx.hunterName;
        _act.bear = false;
        while (_sx==norm && _dx.hunterName == _act.name)
        {
            _act.bear = (_act.bear || _dx.containsBear() );
            read();
        }
    }
}

//this method implements the abstract sx,dx,x: read operation
void HunterEnor::read()
{
    if(_f >> _dx) _sx = norm;
    else _sx = abnorm;
}
