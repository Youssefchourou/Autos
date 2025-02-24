#ifndef LKW_H
#define LKW_H
#include<iostream>
#include"fahrzeug.h"
using namespace std;

class Lkw:public Fahrzeug
{
public:
    Lkw(string marke, string Typ, int Leistung, double Zuladung);
    double getZuladung() const;

    void setZuladung(double newZuladung);

private:
    double Zuladung;
};

#endif // LKW_H
