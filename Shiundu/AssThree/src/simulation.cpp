#include "simulation.h"

//Instantites the gas layers and the atmospheric variables
//Both are a vector of pointers t the respective classes
Simulation::Simulation(std::string &fname)
{
    std::fstream file(fname.c_str());
    if(file.fail())
        throw FILEERROR;

    int totalGasLayers;
    file >> totalGasLayers;

    int i=0;
    char typeOfGas;
    int thicknessOfGas;
    GasLayer *temp;
    while(i<totalGasLayers)
    {

        file >> typeOfGas;
        file >> thicknessOfGas;
        switch(typeOfGas)
        {
            case 'Z' : temp = new Ozone('Z', thicknessOfGas); break;
            case 'X' : temp = new Oxygen('X', thicknessOfGas); break;
            case 'C' : temp = new CarbonDioxide('C', thicknessOfGas); break;
            default : throw WRONG_INPUT;
        }
        _gasLayers.push_back(temp);
        i++;
    }
    std::string theAtmosphericVariables;
    file >> theAtmosphericVariables;
    int j = 0;
    AtmosphericVariable *var;
    int len = theAtmosphericVariables.length();
   while(j < len)
    {
        switch(theAtmosphericVariables[j])
        {
            case 'O' : var = new Others(); break;
            case 'T' : var = new Thunderstorm(); break;
            case 'S' : var = new Sunshine(); break;
            default : throw WRONG_INPUT;
        }
        j++;
        _variables.push_back(var);
    }
    //ctor
}

//The simulation of the gasLayers by the atmospheric variables.
//The gas layer at position 0 in the vector is considered the highest in altitude
//Hence, any transformed gas ascends up from positon n towards 0 and is combined with it's similar type if exists
/*Otherwise, it forms top layer, i.e occupies positon 0 if no matching upper layer exist
if and ony if it has a thickness of atleast 0.5. Else it vanishes.*/
//All atmosperic variables act from the highest altitude going down; that is from zero position of the vector
void Simulation::simulate()
{
    for(auto atmVar : _variables)
    {
        int i=0;
        while(i<_gasLayers.size() && !(_end = _gasLayers[i]->isPerished()))
        {
            GasLayer *newlyTransformed = atmVar->transform(_gasLayers[i]);
            if(newlyTransformed != nullptr)
            {
                int found = searchUpperGasLayers(newlyTransformed, i);
                if(found >=0)
                    _gasLayers[found]->transformed(newlyTransformed);
                else if(found==-1 && newlyTransformed->getThickness() >=0.5)
                {
                    _gasLayers.insert(_gasLayers.begin(), newlyTransformed);
                    //Since there is an insertion at the beginning of the vetctor
                    i=i+1;
                }
            }
            i++;
        }
    }
}
//Searches if the newly transformeed gas layer has a matching gas layer in the upper zone
//Returns the position else return -1 if not found
int Simulation::searchUpperGasLayers(GasLayer* newlyTransformed, int startPosition)
{
    char Symbol = newlyTransformed->getGasSymbol();
    int j = startPosition;
    while(j>=0 && _gasLayers[j]->getGasSymbol() != Symbol)
        j--;
    return j;
}

//Frees memory
Simulation::~Simulation()
{
    int i=0;
    while( i < _gasLayers.size() )
    {
        delete(_gasLayers[i]);
        i++;
    }
    int j=0;
    while( j< _variables.size())
    {
        delete(_variables[j]);
        j++;
    }
    //dtor
}
