#include <iostream>
#include "prsor.h"
#include <vector>

using namespace std;

void PrSorTeszt();
void beolvas(PrSor &ps);
void kiir(PrSor &ps);

int main()
{
    PrSorTeszt();
    PrSor ps;
    beolvas(ps);
    kiir(ps);

    return 0;
}

void kiir(PrSor &ps)
{
    cout<<"\nEredmenyek: \n\n";
    int n=ps.getHossz();
    for (int i=0;i<n;i++)
    {
        Elem e=ps.maxKivesz();
        cout<<(i+1)<<". "<<e;
    }
}

void beolvas(PrSor &ps)
{
    cout<<"Versenyzok szama: ";
    int db;
    cin>>db;
    for (int i=0;i<db;i++)
    {
        Elem e;
        cout<<i+1<<". ";
        cin>>e;
        ps.prSorba(e);
    }
}

void PrSorTeszt()
{
    Elem e1(0,"a");
    Elem e2(0,"a");
    if (e1==e2)
    {
        cout<<"Egyenlo!\n";
    }
    try
    {
        PrSor s(-1);
    }
    catch (PrSor::PrSorHiba err)
    {
        if (err==PrSor::HIBAS_MERET)
        {
            cerr<<"A sor maximalis elemszama csak pozitiv lehet!\n";
        }
    }
    PrSor s;
    try
    {
        s.maxKivesz();
    }
    catch (PrSor::PrSorHiba err)
    {
        if (err==PrSor::URES_PRSOR)
        {
            cerr<<"Ures sorbol nem lehet kivenni!\n";
        }
    }
    try
    {
        for (int i=0;i<100;i++)
        {
            Elem e(i,"q");
            s.prSorba(e);
        }
        Elem e(100,"q");
        s.prSorba(e);
    }
    catch (PrSor::PrSorHiba err)
    {
        if (err==PrSor::MEGTELT)
        {
            cerr<<"Megtelt a sor!\n";
        }
    }
}
