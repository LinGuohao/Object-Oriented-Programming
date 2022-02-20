#include <iostream>
#include "../library/stringstreamenumerator.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/counting.hpp"
#include "../library/summation.hpp"
//#include "library/maxsearch.hpp"

using namespace std;

struct fish{
    string fishname;
    int size;
    friend istream &operator>> (istream &is,fish &e) { is >> e.fishname >> e.size; return is; }
};

class findCatFish : public Counting<fish>{
protected:
    bool cond(const fish& e) const override { return e.fishname=="catfish";}
};

struct angler{
    string name;
    string comp;
     int countvalue;
     int max_num;
    friend istream &operator>>(istream &is, angler &c)
    {
        string line;
        getline(is, line, '\n');
        stringstream ss(line);
        ss >> c.name >> c.comp;
        StringStreamEnumerator<fish> ssenor(ss);   // 识别每横行的鲇鱼
        findCatFish pr;
        pr.addEnumerator(&ssenor);
        pr.run();
        c.countvalue = pr.result(); // 计算出每行有多少鲇鱼=
        return is;
    }
};


class countcatfish : public Summation<angler, int>  // 识别纵行行鱼的总数量
{
protected:
    int neutral() const final override { return 0; }
    int add(const int &a, const int &b) const final override { return a + b; }
    int func(const angler &e) const final override { return e.countvalue; }
};



class countline : public Counting<angler>{   // 识别纵行catfish的总数量
protected:
    bool cond(const angler& e) const override { return true;}
};


int main() {
    SeqInFileEnumerator<angler> enor("C:/Users/Monst/Desktop/OOP/HW4/input.txt"); // 纵向识别
    countcatfish pr;  // 调用计算所有鱼类总数的方程
    pr.addEnumerator(&enor);  //直接用，死的
    pr.run(); // 直接用
    SeqInFileEnumerator<angler> enorr("C:/Users/Monst/Desktop/OOP/HW4/input.txt"); //纵向识别
    countline prr;    // 调用计算鲇鱼总数量的方程
    prr.addEnumerator(&enorr); // 直接用， 死的
    prr.run(); // 直接用
    double avg = pr.result() / prr.result();  // 计算平均数的方法
    cout << avg << endl;
    return 0;
}