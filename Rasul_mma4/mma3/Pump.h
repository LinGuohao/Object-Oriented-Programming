#pragma once

class Pump{
    public:
        Pump(int number);
        void fill(int liter);
        int getNumber(){return _number;}
        int getDisplay(){return _display;}
    private:
        int _number;
        int _display;
};
