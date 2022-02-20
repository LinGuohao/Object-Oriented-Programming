#include <iostream>
#include<fstream>
#include <string>
#include<sstream>
#include <cstring>
#include "FileReader_3.hpp"
using namespace std;



int main()
{
    FileReader fr("test3_1.txt");
    int cnt = 0;
    while(!fr.isEnd)
    {
       string id;
       int num;
       fr.getOneLineInfo(id,num);
       if(num>400)
       {
            cnt ++;
       }
    }
    cout<<"The number of bookstores is "<<cnt<<endl;

}