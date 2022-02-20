#include <iostream>
#include<string>
#include "../library/summation.hpp"
#include "../library/seqinfileenumerator.hpp"
#include"../library/counting.hpp"

using namespace std;

struct Person{
public:
 string name;
 double age;

friend istream& operator>>(std::istream& is, Person& p){
 is >> p.name >> p.age;
 return is;
 }
};


class Number :public Counting<Person>
{
     bool cond(const Person& e) const override
     { 
          return e.age>20;
     }
};

int main()
{
    SeqInFileEnumerator<Person> enor("input.txt");
    Number mycount;
    mycount.addEnumerator(&enor);
    mycount.run();
    
    cout<<"The number of people older than 20 is "<<mycount.result()<<endl;

    
}