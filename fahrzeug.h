#ifndef FAHRZEUG_H
#define FAHRZEUG_H
#include<iostream>
using namespace std;

class Fahrzeug
{
public:
    Fahrzeug(string marke,string Typ,int Leistung);
    virtual~Fahrzeug()=default;
    string getMarke() const;

    string getTyp() const;

    int getLeistung() const;
    friend ostream& operator<<(ostream& os,const Fahrzeug&f){
        os<<"Marke:   "<<f.marke<<"  Typ: "<<f.Typ<<"  Leistung: "<<f.Leistung<<endl;
        return os;
    }

private:
    string marke;
    string Typ;
    int Leistung;
};

#endif // FAHRZEUG_H
