#ifndef PRSOR_H
#define PRSOR_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct Elem
{
    //publikus adattagok
    int pr;
    std::string adat;

    //Paraméter nélküli (üres)-, és paraméteres konstruktor
    Elem() {}
    Elem(int p,std::string s):pr(p), adat(s) {}

    //Teszteléshez készült, egyenlőséget vizsgáló == operátor
    bool operator==(const Elem& b)
    {
        return (pr==b.pr && adat==b.adat);
    }
    //Beolvasó, kiíró operátorok
    friend std::ostream &operator<<(std::ostream &os,const Elem &e)
    {
        os<<"nev: "<<e.adat<<" pontszam: "<<e.pr<<std::endl;
        return os;
    }
    friend std::istream &operator>>(std::istream &is,Elem &e)
    {
        is>>e.adat;
        is>>e.pr;
        return is;
    }
};

class PrSor
{
    private:
        vector<Elem> vec;
        int maxmeret=100;
        int maxindex() const; //maximális elem indexének kiválasztása

    public:
        enum PrSorHiba{URES_PRSOR,MEGTELT,HIBAS_MERET};
        PrSor() : maxmeret(100) {}
        PrSor(int m);
        void prSorba(Elem a); //elem berakása a sorba
        Elem maxKivesz(); //legnagyobb prioritássú elem kivétele a sorból
        Elem maxpr() const; //(egyik) legnagyobb prioritású elem visszaadása
        bool ures_e() {return vec.size()==0;} //pr.sor ürességét vizsgálja
        //Csak a teszteléshez használatos metódusok
        //friend std::ostream& operator<<(std::ostream& s, const PrSor& q); //sor kiirása
        int getHossz() const {return vec.size();}
        std::vector<Elem> getElemek() const {return vec;}
        int getMaxindex() const {return maxindex();} //maxindex privát, nem hívható meg kívülről
};

#endif // PRSOR_H
