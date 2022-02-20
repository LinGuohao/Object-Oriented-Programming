#ifndef ENOR_H
#define ENOR_H
#include <fstream>
#include "valley.h"
using namespace std;

class Vaenor
{
   public:
       Vaenor(const string &infile);
       enum Errors{FILEERROR,TEST};
       enum Status{norm,abnorm};
       void first();
       void next();
       Valley current() {return _tmp;};
       bool end() {return _st == abnorm;}
       void read();
   private:
    Valley _tmp;
    Status _st ;
    ifstream _x;

};










#endif // ENOR_H





