#ifndef CACTUSENOR_H
#define CACTUSENOR_H

#include "cactus.h"
#include <fstream>

//CactusEnor produces Cactuses, enumerated by an input file
//each line of the input file given by its name fname contains the data of a Cactus
class CactusEnor {
public:
    enum Status { norm, abnorm };
    enum Exceptions {FILE_ERROR};
    CactusEnor(const std::string& fname);

    void first() { next(); }
    void next();
    Cactus current() const {return _dx;}
    bool end() const { return _sx==abnorm; }
private:
    Cactus _dx;
    std::ifstream _f;
    Status _sx;
};

#endif
