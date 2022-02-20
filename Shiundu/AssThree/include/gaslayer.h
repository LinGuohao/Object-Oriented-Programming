//#ifndef GASLAYER_H
//#define GASLAYER_H
#pragma once
#include <iostream>
class Oxygen;
class GasLayer
{
    public:
        virtual ~GasLayer(){}
        //A gas may change its thicknes when transformed by an atmospheric variable
        //Or when a transforrmed gas layer of similar type ascends from below nad merges with it
        void transformed(double percentage_Change){this->_thickness += (this->_thickness * percentage_Change/100);}
        void transformed(GasLayer *newlyTransformed){this->_thickness += newlyTransformed->getThickness();}
        bool isPerished(){return _thickness < 0.5;}
        double getThickness(){return _thickness;}
        char getGasSymbol(){return _gasSymbol;}

    protected:
        GasLayer(char Symbol, double thickness) : _gasSymbol(Symbol), _thickness(thickness) {}
        double _thickness;
        char _gasSymbol;
    private:
};
class Ozone : public GasLayer
{
    public:
        Ozone(char Symbol, double thickness) : GasLayer(Symbol, thickness){}
};
class Oxygen : public GasLayer
{
    public:
        Oxygen(char Symbol, double thickness) : GasLayer(Symbol, thickness){}
};
class CarbonDioxide : public GasLayer
{
    public:
        CarbonDioxide(char Symbol, double thickness) : GasLayer(Symbol, thickness){}
};

//#endif // GASLAYER_H
