#ifndef ENOR_H
#define ENOR_H

#include <fstream>

struct Statistic {
    int number;
    int count;
};

enum Status { abnorm, norm };

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        //we assume that when we call the next() method
        //then we are at the first occurrence of a given number
        //or we know that the inputfile is empty
        void next();
        //next() will produce for us the first enumerated element,
        //we just need to ensure its "precondition" by reading
        //an integer number from the file
        void first() { read(); next(); }

        Statistic current() const { return _cur; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        int _dx; //the current integer number of the input file
                    //we are processing
        Status _sx;
        Statistic _cur; //the current element of the enumeration
        bool _end;
        void read();
};
#endif
