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
       string originID;
       bool finalbool = true;
       
    public:
        bool isEnd;
        bool hasnext = true;
        FileReader(string filename)
        {
           fin.open(filename);
           if(fin)
           {
               isEnd = false;
               if(!fin.eof())
               {
                   string tmpid;
                   string Provider;
                   int numOfData;
                   getOneLineInfo(tmpid,Provider,numOfData);
                   originID = tmpid;
                   if(numOfData>2)
                   {
                       finalbool = false;
                   }
               }
           }else
           {
               cout <<"no such file" << endl;
               abort();
            }
           
        }
        void getOneLineInfo(string &id, string &Provider , int& numOfData)
        {   
            string str;
            if(!fin.eof())
            {
                getline(fin, str);
                stringstream input(str);
                input>>id;
                input>>Provider;
                string tmp;
                int cnt=0;
                while(input>>tmp)
                {
                    cnt = cnt+1;
                }
                numOfData = cnt/2;
                if(fin.eof())
                {
                    isEnd = true;
                }
            }else
            {
                isEnd = true;
            }
            //cout<<"test"<<endl;
        }
        ~FileReader(){fin.close();}
        void getOne(string &id,bool &isTrue)
        {
        
            while(!isEnd)
            {
                string tmpid;
                string Provider;
                int numOfData;
                getOneLineInfo(tmpid,Provider,numOfData);
                if(tmpid == originID)
                {
                   if(numOfData>2)
                   {
                       finalbool = false;
                   }
                }else
                {
                    id = originID;
                    isTrue = finalbool;
                   if(numOfData>2)
                   {
                       finalbool = false;
                   }
                    originID = tmpid;
                    break;
                }
            }
            if(isEnd)
            {
                id=originID;
                isTrue = finalbool;
                finalbool = true;
                hasnext = false;
                return;
            }
            
        }

};



int main()
{
    FileReader fr("test4.txt");
    while(fr.hasnext)
    {
        string id;
        bool istrue;
        fr.getOne(id,istrue);
        if(istrue)
        {
            cout<<id<<endl;
        }
    }

}