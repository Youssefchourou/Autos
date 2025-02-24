#include "fahrzeug.h"

Fahrzeug::Fahrzeug(string marke, string Typ, int Leistung):marke(marke),Typ(Typ),Leistung(Leistung)
{

}

string Fahrzeug::getMarke() const
{
    return marke;
}

string Fahrzeug::getTyp() const
{
    return Typ;
}

int Fahrzeug::getLeistung() const
{
    return Leistung;
}
