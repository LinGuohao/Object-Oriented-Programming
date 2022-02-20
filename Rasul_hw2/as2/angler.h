//Author:   Rasul Khanbayov GGUSA3
//Date:     2020.04.12.
//Title:    8

#ifndef ANGLER_H
#define ANGLER_H

#include "contest.h"

struct Angler{
    std::string id;
    int num;
};

class AnglerEnor{
    public:
        AnglerEnor(const std::string &str): _tt(str) { };
        void first() {_tt.first(); next();}
        void next();
        Angler current() const { return _cur;}
        bool end() const { return _end;}
    private:
        ContestEnor _tt;
        Angler _cur;
        bool _end;
};

#endif // ANGLER_H

