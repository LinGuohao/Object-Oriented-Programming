//Author:   Guohao Lin
//Date:     2020.04.12
//Title:    3

#include <iostream>
#include "Enor.h"
#include<string>

using namespace std;

int Summation(const string &filename)
{
     // count used for testing!
      int count = 0;
    try{
      Enor t (filename);
      t.first();
      bool l = false;
      while(!t.end())
      {
          if(t.current().caught == true)
          {
              count++;
              cout<<t.current().ID<<endl;
              l = true;
          }
          t.next();
      }
      if(l == false)
      {
          cout <<"No such championship"<<endl;
      }
  }catch (Enor::error FILE_OPEN_FAIL)
  {
      cout<<"No such file"<<endl;
  }
  return count;
}
#define NORMAL_MODE
#ifdef NORMAL_MODE


int main()
{
  Summation("t10.txt");
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("empty file", "t0.txt") {
    CHECK(Summation("t1.txt")==0);
}
TEST_CASE("2nd test")
{
    CHECK(Summation("t2.txt") ==1);
}
TEST_CASE("3rd test")
{
    CHECK(Summation("t3.txt")==2);
}
TEST_CASE("4th test")
{
    CHECK(Summation("t4.txt")==1);
}
TEST_CASE("5th test")
{
    CHECK(Summation("t5.txt")==1);
}
TEST_CASE("6th test")
{
    CHECK(Summation("t6.txt")==2);
}
TEST_CASE("7th test")
{
    CHECK(Summation("t7.txt")==1);
}
TEST_CASE("8th test")
{
    CHECK(Summation("t8.txt")==1);
}
TEST_CASE("9th test")
{
    CHECK(Summation("t9.txt")==0);
}
TEST_CASE("10th test")
{
    CHECK(Summation("t10.txt")==2);
}
TEST_CASE("11th test")
{
    CHECK(Summation("t11.txt")==3);
}
TEST_CASE("12th test")
{
    CHECK(Summation("t12.txt")==10);
}
TEST_CASE("13th test")
{
    CHECK(Summation("t13.txt")==9);
}
TEST_CASE("14th test")
{
    CHECK(Summation("t14.txt")==1);
}
TEST_CASE("15th test")
{
    CHECK(Summation("t15.txt")==1);
}
TEST_CASE("16th test")
{
    CHECK(Summation("t16.txt")==1);
}
TEST_CASE("17th test")
{
    CHECK(Summation("t17.txt")==1);
}















#endif // NORMAL_MODE
