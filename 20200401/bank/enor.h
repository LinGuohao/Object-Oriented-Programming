#ifndef ENOR_H
#define ENOR_H
#include <fstream>

struct Trans {
    std::string number;
    std::string date;
    int sum;
    friend std:: istream& operator>>(std::istream &is, Trans&tmp);
};

struct Balance {
    std::string number;
    int balance;

};

enum Status { abnorm, norm };

class Enor
{
    public:
        enum Errors { FILEERROR };
        Enor(const std::string &str);
        void first() { read(); next(); }
        void next();
        Balance current() const { return _cur; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        Trans _dx;
        Status _sx;
        Balance _cur;
        bool _end;
        void read();
};
#endif

