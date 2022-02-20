#pragma once
#include "gaslayer.h"
//An interface
class AtmosphericVariable
{
    public:
        virtual GasLayer* transform(GasLayer* object) = 0;
        virtual ~AtmosphericVariable(){}
    protected:
        AtmosphericVariable() {}
    private:
};
//Child classes implements function transform()
//the function transforms a given gas layer
//Chnages its thickness by calling  the transformed () function of the gas layer class
//Returns a newly transformed gas layer if exists else return null
class Others : public AtmosphericVariable
{
    public:
        GasLayer* transform(GasLayer* object)
        {
            char Symbol = object->getGasSymbol();
            GasLayer *newlyTransformed;
            switch(Symbol)
            {
                case 'Z' : newlyTransformed = new Oxygen('X', 0.05 * object->getThickness()); object->transformed(-5); return newlyTransformed;
                case 'X' : newlyTransformed = new CarbonDioxide('C', 0.1 * object->getThickness()); object->transformed(-10); return newlyTransformed;
                case 'C' : return nullptr;
            }
        }
};
class Thunderstorm : public AtmosphericVariable
{
    public:
        GasLayer* transform(GasLayer* object)
        {
            char Symbol = object->getGasSymbol();
            GasLayer *newlyTransformed;
            switch(Symbol)
            {
                case 'Z' : return nullptr;
                case 'X' : newlyTransformed = new Ozone('Z', 0.5 * object->getThickness()); object->transformed(-50); return newlyTransformed;
                case 'C' : return nullptr;
            }
        }
};
class Sunshine : public AtmosphericVariable
{
    public:
        GasLayer* transform(GasLayer* object)
        {
            char Symbol = object->getGasSymbol();
            GasLayer *newlyTransformed;
            switch(Symbol)
            {
                case 'Z' : return nullptr;
                case 'X' : newlyTransformed = new Ozone('Z', 0.05 * object->getThickness()); object->transformed(-5); return newlyTransformed;
                case 'C' : newlyTransformed = new Oxygen('X', 0.05 * object->getThickness()); object->transformed(-5); return newlyTransformed;
            }
        }
};

//#endif // ATMOSPHERICVARIABLE_H
