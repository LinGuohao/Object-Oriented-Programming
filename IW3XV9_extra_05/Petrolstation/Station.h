#ifndef STATION_H
#define STATION_H

#include<iostream>
#include<vector>
#include"Pump.h"
#include"Cash.h"

using namespace std;


class Station
{

    public:
        Station(int expectedunit)
        {
            unit = expectedunit;

            for(int i=0;i<6;i++)
            {
                Pump* tmp = new Pump;
                pumplist.push_back(tmp);
            }
            for(int i=1;i<3;i++)
            {
                Cash* tmp = new Cash(i);
                cashlist.push_back(tmp);
            }
        }
        int getunit()
        {
            return unit;
        }

        vector<Pump*>pumplist;
        vector<Cash*>cashlist;
    private:
         int unit;



};



#endif // STATION_H
