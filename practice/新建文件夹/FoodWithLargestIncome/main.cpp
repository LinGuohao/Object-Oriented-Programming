//Problem: determine the food that generated the highest income for a restaurant.
//Each line of the input file consists of the following data:
//name of the food, hour and minute of the time of ordering, unit price of the food, amount of food ordered
//The lines of the text file are sorted according to the name of the food.
#include <iostream>
#include "FoodEnor.h"

using namespace std;

int main()
{
    FoodEnor enor("in.txt");

    enor.first();
    //maximum search can be applied only if the enumerator is not empty
    if(enor.end())
    {
        cout << "The file is empty!" << endl;
    }
    else
    {
        int maxIncome = enor.current().income;
        string maxFoodName = enor.current().foodName;
        enor.next();
        while(!enor.end())
        {
            if(enor.current().income > maxIncome)
            {
                maxIncome = enor.current().income;
                maxFoodName = enor.current().foodName;
            }
            enor.next();
        }
        cout << maxFoodName << " grossed the largest profit: " << maxIncome << endl;
    }
}
