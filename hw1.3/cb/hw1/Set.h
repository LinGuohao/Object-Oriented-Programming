#ifndef SET
#define SET
#include <iostream>
#include<vector>
#include<fstream>

using namespace std;

class Seq{
private:
    vector<int>a;
public:
    bool in(int tmp);
    bool rem(int tmp);
    bool isEit(int tmp);
	bool prout();
	bool isEmp();
	int rade();
	int  Evnum();

};


#endif
