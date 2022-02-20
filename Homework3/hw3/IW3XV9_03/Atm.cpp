#include <iostream>
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "Atm.h"
#include "Gas.cpp"


void Check(vector<Gase*>&Layerlist)
{

        vector<Gase*>::iterator it;
     for(it=Layerlist.begin();it!=Layerlist.end();)
     {
         Gase *tmp = *it;
         if(tmp->isdisappear())
             it=Layerlist.erase(it);
         else
             ++it;
     }
}





bool Atmp::notdone(char name)
{
    bool l= false;
    int i=0;
    while (i<Layerlist.size()&&!l)
    {
       if( Layerlist[i] ->givename()== name)
       {
           l=true;
       }
       i++;
    }
    return l;

}


void Atmp::print()
{

    for(int i=0;i<Layerlist.size();i++)
    {

        cout<<"  "<<Layerlist[i] ->givename()<<" --- "<<Layerlist[i] ->getthickness()<<endl;
    }

    cout<<endl<<endl;
}



void Atmp::thunderstorm()
{
  for(int i=0;i<Layerlist.size();i++)
  {
     if(Layerlist[i]-> givename() == 'X')
     {
         double tmp = (Layerlist[i]-> getthickness())*0.5;
         Layerlist[i] -> decrease(tmp);
         int j;
         j=i-1;
         bool l = false;
         while(j>=0 && l == false)
         {
             if(Layerlist[j] ->givename() == 'Z')
             {
                 Layerlist[j] -> increase(tmp);
                 l = true;
             }
             j--;
         }
         if(l==false)
         {
            Ozone *newgas = new Ozone(tmp);
            Layerlist.insert(Layerlist.begin(),newgas);
            i++;
         }

       }
    }

    Check(Layerlist);

}

void Atmp::sunshine()
{
     for(int i=0;i<Layerlist.size();i++)
  {
     if(Layerlist[i]-> givename() == 'X')
     {
         double tmp = (Layerlist[i]-> getthickness())*0.05;
         Layerlist[i] -> decrease(tmp);
         int j;
         j=i-1;
         bool l = false;
         while(j>=0 && l == false)
         {
             if(Layerlist[j] ->givename() == 'Z')
             {
                 Layerlist[j] -> increase(tmp);
                 l = true;
             }
             j--;
         }
         if(l==false)
         {
            Ozone *newgas = new Ozone(tmp);
            Layerlist.insert(Layerlist.begin(),newgas);
            i++;
         }

       }else if(Layerlist[i]->givename() == 'C')
       {
         double tmp = (Layerlist[i]-> getthickness())*0.05;
         Layerlist[i] -> decrease(tmp);
         int j;
         j=i-1;
         bool l = false;
         while(j>=0 && l == false)
         {
             if(Layerlist[j] ->givename() == 'X')
             {
                 Layerlist[j] -> increase(tmp);
                 l = true;
             }
             j--;
         }
         if(l==false)
         {
            Oxygen *newgas = new Oxygen(tmp);
            Layerlist.insert(Layerlist.begin(),newgas);
            i++;
         }
       }
    }
    Check(Layerlist);
}

void Atmp::other()
{

    for(int i=0;i<Layerlist.size();i++)
  {
     if(Layerlist[i]-> givename() == 'Z')
     {
         double tmp = (Layerlist[i]-> getthickness())*0.05;
         Layerlist[i] -> decrease(tmp);
         int j;
         j=i-1;
         bool l = false;
         while(j>=0 && l == false)
         {
             if(Layerlist[j] ->givename() == 'X')
             {
                 Layerlist[j] -> increase(tmp);
                 l = true;
             }
             j--;
         }
         if(l==false)
         {
            Oxygen *newgas = new Oxygen(tmp);
            Layerlist.insert(Layerlist.begin(),newgas);
            i++;
         }

       }else if(Layerlist[i]->givename() == 'X')
       {
         double tmp = (Layerlist[i]-> getthickness())*0.1;
         Layerlist[i] -> decrease(tmp);
         int j;
         j=i-1;
         bool l = false;
         while(j>=0 && l == false)
         {
             if(Layerlist[j] ->givename() == 'C')
             {
                 Layerlist[j] -> increase(tmp);
                 l = true;
             }
             j--;
         }
         if(l==false)
         {
            Carbon *newgas = new Carbon(tmp);
            Layerlist.insert(Layerlist.begin(),newgas);
            i++;
         }
       }
    }
    Check(Layerlist);

}

