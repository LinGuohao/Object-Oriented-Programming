#include <iostream>
#include <vector>
#include "simulation.h"

using namespace std;
//Displays the gas layer type and it's thickness
void DisplayGasLayers(vector<GasLayer*> _gasLayers)
{
    int j=0;
    while(j<_gasLayers.size())
    {
        char Symbol = _gasLayers[j]->getGasSymbol();
        switch(Symbol)
        {
            case 'Z' : std::cout<<"Ozone->  "<<_gasLayers[j]->getThickness()<<std::endl; break;
            case 'X' : std::cout<<"Oxygen-> "<<_gasLayers[j]->getThickness()<<std::endl; break;
            case 'C' : std::cout<<"Carbon-> "<<_gasLayers[j]->getThickness()<<std::endl; break;
        }
        j++;
    }
}
#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{
    try
    {
        //Simulation enumerates Gas layers after every simulation round
        string str("in1.txt");
        Simulation t(str);
        //Display gasLayers before the beginnnig of the simulation
        cout<<"<----Before simulation------>"<<endl;
        DisplayGasLayers(t.current());
        cout<<endl;
        //Begin simulation process
        //Simulation process ends when a gas layer perishes from the atmosphere
        //That is it's thickness is lesss than 0.5
        /*In case there is only one atmospheric variable and gas layers which it has no effect on,
         thhen the simulation is infinite*/
        t.first();
        int i=0;
        while(!t.end())
        {
            cout<<"<----Simulation Round "<<i+1<<"---->"<<endl;
            DisplayGasLayers(t.current());
            t.next();
            i++;
            cout<<endl;
        }
        return 0;
    }
    catch(Simulation::FILE)
    {
        cout<<"Invalid file"<<endl;
    }
    catch(Simulation::INPUT)
    {
        cout<<"The file consists of invalid input or format"<<endl;
    }
    catch(...)
    {
        cout<<"An exception occured"<<endl;
    }

}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("Check that simulation ends when one single gas layer perishes from the atmosphere" "in1.txt")
{
    string file("in1.txt");
    Simulation object(file);
    vector<GasLayer*> _layers = object.current();
    //Check nefore beginnig of the simulation
    int i = 0;
    int perished = 0;
    while(i<_layers.size())
    {
        if(_layers[i]->isPerished()==true)
            perished +=1;
        i++;
    }
    CHECK(perished==0);
    //Check after the end of the simulaton process
    int j=0;
    object.first();
    while(!object.end())
        object.next();
    while(j<_layers.size())
    {
        if(_layers[j]->isPerished()==true)
            perished +=1;
        j++;
    }
    CHECK(perished==1);
}
TEST_CASE("Check that Thundersorm transform 50% of Oxygen to Ozone", "in5.txt")
{

    string file("in5.txt");
    Simulation object(file);

    //Check before simulation
    vector<GasLayer*> _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='X');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);

    //Check after first simulation
    object.first();
    _layers = object.current();
    CHECK(_layers[1]->getGasSymbol()=='X');
    CHECK(_layers[1]->getThickness()==25.0);
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==25.0);
    CHECK(_layers.size()==2);

    //Check after second simulation process
    object.next();
    CHECK(_layers[1]->getGasSymbol()=='X');
    CHECK(_layers[1]->getThickness()==12.5);
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==37.5);
}
TEST_CASE("Check that Thunderstorm has no effect on Carbon Dioxide and Ozone", "in6.txt and in7.txt")
{
    //On Carbon dioxide
    string file1("in6.txt");
    Simulation object(file1);
    vector<GasLayer*> _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);

    object.first();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);

    object.next();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);

    //On Ozone
    string file2("in7.txt");
    Simulation objectTwo(file2);
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);

    objectTwo.first();
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);

    objectTwo.next();
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==50.0);
    CHECK(_layers.size()==1);
}
TEST_CASE("Check that Sunshine transforms 5% of Oxygen to Ozone and 5 Carbon Dioxide to Oxygen", "in8.txt and in9.txt")
{
    //On Oxygen
    string file1("in8.txt");
    Simulation object(file1);
    vector<GasLayer*> _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='X');
    CHECK(_layers[0]->getThickness()==500.0);
    CHECK(_layers.size()==1);

    object.first();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==25.0);
    CHECK(_layers[1]->getGasSymbol()=='X');
    CHECK(_layers[1]->getThickness()==475.0);
    CHECK(_layers.size()==2);

    //On Ozone
    string file2("in9.txt");
    Simulation objectTwo(file2);
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==500.0);
    CHECK(_layers.size()==1);

    objectTwo.first();
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='X');
    CHECK(_layers[0]->getThickness()==25.0);
    CHECK(_layers[1]->getGasSymbol()=='C');
    CHECK(_layers[1]->getThickness()==475.0);
    CHECK(_layers.size()==2);
}
TEST_CASE("Check that Sunshine has no effect on Ozone", "in10.txt")
{
    string file1("in10.txt");
    Simulation object(file1);
    vector<GasLayer*> _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==500.0);
    CHECK(_layers.size()==1);

    object.first();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==500.0);
    CHECK(_layers.size()==1);

    object.next();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==500.0);
    CHECK(_layers.size()==1);
}
TEST_CASE("Check that Others transforms 5% of Ozone to Oxygen and 10% Oxygen to Carbon Dioxide", "in11.txt and in12.txt")
{
    //On Ozone
    string file1("in11.txt");
    Simulation object(file1);
    vector<GasLayer*> _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='Z');
    CHECK(_layers[0]->getThickness()==100.0);
    CHECK(_layers.size()==1);

    object.first();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='X');
    CHECK(_layers[0]->getThickness()==5.0);
    CHECK(_layers[1]->getGasSymbol()=='Z');
    CHECK(_layers[1]->getThickness()==95.0);
    CHECK(_layers.size()==2);

    //On Oxygen
    string file2("in12.txt");
    Simulation objectTwo(file2);
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='X');
    CHECK(_layers[0]->getThickness()==100.0);
    CHECK(_layers.size()==1);

    objectTwo.first();
    _layers = objectTwo.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==10.0);
    CHECK(_layers[1]->getGasSymbol()=='X');
    CHECK(_layers[1]->getThickness()==90.0);
    CHECK(_layers.size()==2);
}
TEST_CASE("Check that Ohters have no effect on Carbon Dioxide", "in13.txt")
{
    string file1("in13.txt");
    Simulation object(file1);
    vector<GasLayer*> _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==100.0);
    CHECK(_layers.size()==1);

    object.first();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==100.0);
    CHECK(_layers.size()==1);

    object.next();
    _layers = object.current();
    CHECK(_layers[0]->getGasSymbol()=='C');
    CHECK(_layers[0]->getThickness()==100.0);
    CHECK(_layers.size()==1);
}
#endif
