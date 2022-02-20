#ifndef HUNTERENOR_H
#define HUNTERENOR_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

struct Animal
{
    std::string name;
    int weight;
};

struct Hunting
{
    std::string hunterName;
    std::string date;
    std::vector<Animal> animals;
    bool containsBear() const;
    friend std::istream &operator>>(std::istream &is, Hunting &h);
};

struct Hunter
{
    std::string name;
    bool bear;
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
