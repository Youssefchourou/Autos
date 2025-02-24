#include "lkw.h"

Lkw::Lkw(string marke,string Typ,int Leistung,double Zuladung):Fahrzeug(marke,Typ,Leistung),Zuladung(Zuladung)
{

}

double Lkw::getZuladung() const
{
    return Zuladung;
}

void Lkw::setZuladung(double newZuladung)
{
    Zuladung = newZuladung;
}
