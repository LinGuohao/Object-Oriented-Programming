//Author:   Rasul Khanbayov GGUSA3
//Date:     2020.04.12.
//Title:    8

#ifndef CONTEST_H
#define CONTEST_H

#include <fstream>
#include <sstream>
#include <string>

struct Contest {
    std::string angler;
    std::string contest;
    int counter;
};

enum Status { abnorm, norm };

class ContestEnor{
    public:
        enum Errors { FILEERROR };
        ContestEnor(const std::string &str);
        void first() {next();}
        void next();
        Contest current() const { return _cur;}
        bool end() const { return _end;}
    private:
        std::ifstream _f;
        Status _sx;
        Contest _cur;
        bool _end;
};

#endif // CONTEST_H

