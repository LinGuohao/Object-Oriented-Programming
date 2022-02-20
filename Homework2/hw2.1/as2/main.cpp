#include <iostream>

using namespace std;

int main()
{
  Enor t(file);
  while(t.end() != true)
  {
      if(t.current().caught == true)
      {
          cout<<t.current().ID<<endl;
      }
  }

}
