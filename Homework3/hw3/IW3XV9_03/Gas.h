#pragma once

class Gase
{

protected:
    double thickness;
    char _name;
public:
    void decrease(double amount){thickness=thickness - amount;};
    void increase(double amount){thickness=thickness+ amount;};
    double getthickness(){return thickness;};
    virtual char givename()=0;
    void setthickness(double amount){ thickness = amount;};
    bool isdisappear()const{return thickness <0.5;};
};



