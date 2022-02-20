//Author:    Gregorics Tibor
//Date:      2017.08.08.
//Title:     Diagonal matrix

#pragma once
#include <iostream>
#include <vector>

//Class of diagonal matrices
//Methods: add, multiply, write, read, refer to an element
//Representation: only the elements of the diagonal
class Diag {
public:
    enum Exceptions{OVERINDEXED, NULLPART, DIFFERENT, INVALID};

    Diag(){ _v.clear(); }
    Diag(int k);
    ~Diag() { }
    Diag(const std::vector<int> &v);
    Diag(const Diag& a);
    Diag& operator=(const Diag& a);
    int getSize() const {return _v.size();}

    int operator()(int i, int j) const;
    int& operator()(int i, int j);

    friend Diag operator+ (const Diag& a, const Diag& b);
    friend Diag operator* (const Diag& a, const Diag& b);
    friend std::istream& operator>> (std::istream& s, Diag& a);
    friend std::ostream& operator<< (std::ostream& s, const Diag& a);
private:
    std::vector<int> _v;

    void reSize(int k);
};
