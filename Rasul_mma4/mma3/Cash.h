#pragma once

class Cash{
    public:
        Cash(int number);
        void pay(int unit, int display);
        int getPrice(){return _price;}
    private:
        int _number;
        int _price;
};
