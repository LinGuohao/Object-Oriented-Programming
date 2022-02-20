#ifndef ENOR_H
#define ENOR_H
#include <iostream>
#include <fstream>
using namespace std;

struct Student{
   string name;
   string subject;
   int result;
   friend istream&operator>>(istream &in,Student &tmp);
};

struct Grade{
  string name;
  int cunt;
  friend ostream&operator<<(ostream &out,Grade &tmp);
  Grade& operator =(const Grade &tmp)
  {
      name = tmp.name;
      cunt = tmp.cunt;
      return *this;

  }
};

class Gradeenor{
   public:
       Gradeenor (const string &filename);
       enum Error {FILE_OPEN_FAILED};
       enum Status {norm,abnorm};
       void read();
       void first(){read();next();};
       void next();
       Grade current()const{return curr;};
       bool end(){return _end;};



   private:
       ifstream _x;
       Student _dx;
       Status _sx;
       Grade curr;
       bool _end;

};












#endif // ENOR_H

