#include "pkw.h"

Pkw::Pkw(string marke, string Typ, int Leistung, int geschwindigkeit):Fahrzeug(marke,Typ,Leistung),geschwindigkeit(geschwindigkeit)
{

}

int Pkw::getGeschwindigkeit() const
{
    return geschwindigkeit;
}

void Pkw::setGeschwindigkeit(int newGeschwindigkeit)
{
    geschwindigkeit = newGeschwindigkeit;
}
