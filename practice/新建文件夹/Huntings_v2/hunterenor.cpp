#include "hunterenor.h"

//"converting" a line of the input into a Hunting struct
//Examples:
//Daniel 2017.02.12 rabbit 15 fox 24 is "converted to" Daniel 2017.02.12 false
//Pete 2017.04.05 bear 300 rabbit 20 is "converted to" Pete 2017.04.05 true
//hasShotABear member will be true only if there is a bear shot by the given hunter
//on the given day
std::istream &operator>>(std::istream &is,Hunting &h)
{
    std::string line;
    getline(is,line,'\n');
    std::istringstream ss(line);
    ss >> h.hunterName >> h.date;
    Animal a;
    //Instead of pushing Animal type of objects into a vector we can process later,
    //here we decide (by using summation, OR'ing) whether there is at least one bear
    //among the enumerated animals.
    //Recall: animals are given in the form of (name, weight) pairs.
    h.hasShotABear = false;
    while (ss >> a.name >> a.weight)
    {
        h.hasShotABear = h.hasShotABear || (a.name == "bear");
    }
    return is;
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
        //At this point we know that the input file is not empty, here we aim to
        //process all the successive line that belong to the same hunter.
        //What is the name of the hunter we deal with?
        //_dx.hunterName, the current element of the file, from where we start the processing.
        //We also have to record that value as _act.name
        _end = false;
        _act.name = _dx.hunterName;
        _act.bear = false;
        while (_sx==norm && _dx.hunterName == _act.name)
        {
            _act.bear = (_act.bear || _dx.hasShotABear );
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
