#include <iostream>
#include<fstream>
#include <string>
#include<sstream>
#include <cstring>

using namespace std;
class FileReader
{
    private:
       ifstream fin;
       
    public:
        bool isEnd = false;
        FileReader(string filename)
        {
           fin.open(filename);
           if(!fin)
           {
               cout <<"no such file" << endl;
               abort();
            }
           
        }
        void getOneLineInfo(string &id , int &numOfBook)
        {   
            string str;
            if(!fin.eof())
            {
                getline(fin, str);
                stringstream input(str);
                string data;
                int num;
                numOfBook = 0;
                input>>id;
                while(input>>data>>num)
                {
                    numOfBook = numOfBook + num;
                }
                if(fin.eof())
                {
                    isEnd = true;
                }
            }
            //cout<<"test"<<endl;
        }
        ~FileReader(){fin.close();}
       

};