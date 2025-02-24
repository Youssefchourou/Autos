#ifndef PKW_H
#define PKW_H
#include<iostream>
#include"fahrzeug.h"
using namespace std;

class Pkw:public Fahrzeug
{
public:
    Pkw(string marke,string Typ,int Leistung,int geschwindigkeit);
    int getGeschwindigkeit() const;

    void setGeschwindigkeit(int newGeschwindigkeit);

private:
    int geschwindigkeit;
};

#endif // PKW_H
