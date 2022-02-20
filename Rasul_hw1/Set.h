#ifndef SET_H
#define SET_H

#include <vector>

class Set{

private:
    std::vector<int> vec;

public:
    Set();
    void InsertElement(int a);
    void RemoveElement(int a);
    bool IsEmpty();
    bool IsContain(int a);
    int RandomElement();
    int LargestElement();
    void Print();
};

#endif
