#ifndef HUNTERENOR_H
#define HUNTERENOR_H

#include <fstream>
#include <sstream>
#include <iostream>

struct Animal
{
    std::string name;
    int weight;
};

struct Hunting
{
    std::string hunterName;
    std::string date;
    bool hasShotABear; //it is true in case the given hunter has shot a bear
    //at the given hunting described by one line of the file
    friend std::istream &operator>>(std::istream &is, Hunting &h);
};

//Main idea: we enumerate Hunter type of elements.
//The next Hunter type of element can be produced by the next() method that processes
//the lines of the input file that belong to the same hunter.
//The next Hunter type of element can be asked by calling the method().
struct Hunter
{
    std::string name;
    bool bear;//is true if the given hunter has shot a bear at any of his/her huntings
};

enum Status {norm,abnorm};
class HunterEnor
{
    private:
        Status _sx;
        Hunter _act;
        std::ifstream _f;
        Hunting _dx;
        bool _end;
    public:
        enum Exception { OPEN_ERROR };
        HunterEnor(const std::string &fileName);
        ~HunterEnor() { _f.close(); }
        void first();
        void next();
        Hunter current() const { return _act; }
        bool end() const { return _end; }
        void read();
};

#endif // INFILE_H
