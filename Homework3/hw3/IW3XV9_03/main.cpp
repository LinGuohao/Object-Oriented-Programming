#include <iostream>
#include <vector>
#include <fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Atm.h"
#include"Gas.cpp"


using namespace std;

string CreatList(const string &str , Atmp*atmospheric)
{
     ifstream f(str);
     if(f.fail()) { cout << "Wrong file name!\n"; exit(1);}
     int num;
     f>>num;
     for(int i=0; i< num;i++)
     {
         char name ;
         double tmpthickness;
         f>>name>>tmpthickness;
        switch(name){
            case 'Z' :
                {
                    Ozone* tmpGase = new Ozone(tmpthickness);atmospheric->Layerlist.push_back(tmpGase); break;
                }
            case 'X' :
                {
                   Oxygen* tmpGase = new Oxygen(tmpthickness);atmospheric->Layerlist.push_back(tmpGase); break;
                }
            case 'C' :
                {
                   Carbon* tmpGase = new Carbon(tmpthickness);atmospheric->Layerlist.push_back(tmpGase);   break;
                }
        }

      }

      string variables;
      f>>variables;
      return variables;



}
char* Convert(string src)
{
    char *dst = new char[255];
    int i;
    for(i=0;i <=src.length();i++)
        dst[i]=src[i];
    dst[i] = '\0';
     return dst;
}
int runfile(const string &str)
{
    Atmp * atmospheric = new Atmp;
    string variables;
    int cont = 0;
    variables=CreatList(str,atmospheric);
    char *var = Convert(variables);
    bool l = true;
    while(l)
    {
      for(int i=0;var[i]!='\0';i++)
      {
          if(var[i] == 'T')
          {
              atmospheric->thunderstorm();
          }else if(var[i]=='S')
          {
              atmospheric->sunshine();
          }else if(var[i] == 'O')
          {
              atmospheric->other();
          }

      }
      cont++;
      cout<<"== The "<<cont<<" "<<"round of simulation =="<<endl;
      cout<<endl;
      atmospheric->print();
      l = atmospheric->notdone('C')&&atmospheric->notdone('X')&&atmospheric->notdone('Z');
    }
   return cont;
}
#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{

    runfile("input.txt");

}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("Original test file", "input.txt") {
    CHECK(runfile("input.txt")==64);
}

TEST_CASE("Repeating elements X","in2.txt")
{
    CHECK(runfile("in2.txt")==10);
}

TEST_CASE("Repeating elements Z","in3.txt")
{
    CHECK(runfile("in3.txt")==1);
}
TEST_CASE("Repeating elements C","in4.txt")
{
    CHECK(runfile("in4.txt")==10);
}
TEST_CASE("Test other on Z","in5.txt")
{
    CHECK(runfile("in5.txt")==1);
}
TEST_CASE("Test other on X","in6.txt")
{
    CHECK(runfile("in6.txt")==1);
}
TEST_CASE("Test sunshine on X","in7.txt")
{
    CHECK(runfile("in7.txt")==1);
}
TEST_CASE("Test sunshine on C","in8.txt")
{
    CHECK(runfile("in8.txt")==1);
}
TEST_CASE("Test thunderstorm on X","in9.txt")
{
    CHECK(runfile("in9.txt")==1);
}
TEST_CASE("Test X","in10.txt")
{
    CHECK(runfile("in10.txt")==2);
}
TEST_CASE("Test C","in11.txt")
{
    CHECK(runfile("in11.txt")==1);
}
TEST_CASE("Test Z","in12.txt")
{
    CHECK(runfile("in12.txt")==1);
}
TEST_CASE("Test other on C","in13.txt")
{
    CHECK(runfile("in13.txt")==1);
}
TEST_CASE("Test sunshine on Z","in4.txt")
{
    CHECK(runfile("in14.txt")==1);
}
TEST_CASE("Test thunderstorm on Z","in15.txt")
{
    CHECK(runfile("in15.txt")==1);
}
TEST_CASE("Test thunderstorm on C","in16.txt")
{
    CHECK(runfile("in16.txt")==1);
}




#endif // NORMAL_MODE
