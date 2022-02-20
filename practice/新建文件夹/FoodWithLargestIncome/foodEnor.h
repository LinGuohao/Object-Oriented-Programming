#ifndef FOODENOR_H
#define FOODENOR_H

#include <iostream>
#include <fstream>

struct Order
{
    std::string foodName;
    int hour;
    int minute;
    int orderCount;
    int unitPrice;
    friend std::istream& operator>>(std::istream &is, Order &ord);
};

struct FoodIncome
{
    std::string foodName;
    int income;
};

class FoodEnor
{
public:
    enum Status {norm, abnorm};
    enum Exceptions { FILE_ERROR };
    FoodEnor(const std::string &fname);
    void first();
    void next();
    FoodIncome current() const { return _current; }
    bool end() const {return _end;}
private:
    std::ifstream _f;
    Status _sx;
    Order _dx; //current element of the file
    FoodIncome _current; //current element of the enumeration
    bool _end;
    //the read() method implements the abstract sx,dx,x: read operation
    void read();
};

#endif
