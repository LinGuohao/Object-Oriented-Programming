#ifndef PAIRENOR_H
#define PAIRENOR_H

#include <utility>
#include <fstream>

//PairEnor produces all the Pairs where the first member of a Pair is an element of the input file,
//the second member of the Pair is the consecutive element of the first one
class PairEnor {
public:
    enum Status {norm, abnorm};
    enum Exceptions {FILE_ERROR};
    PairEnor(const std::string &fname);
    void first();
    void next();
    //The current element is a pair of integers, (in general std::pair may couples values of different types).
    //The individual values can be accessed through public members first and second.
    std::pair<int, int> current() const { return _current; }
    bool end() const { return _sx == abnorm; }
private:
    std::pair<int, int> _current;
    Status _sx;
    std::ifstream _f;
};

#endif
