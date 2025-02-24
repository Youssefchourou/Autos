#ifndef VERWALTUNG_H
#define VERWALTUNG_H
#include<iostream>
#include<vector>
#include"fahrzeug.h"
#include"mystack.h"
using namespace std;

class Verwaltung
{
public:
    Verwaltung();
    ~Verwaltung();
    void benutzerdialog();
    void dateieinlesen(const string &dateiname);
    void Fahrzeugeanzeigen();
    void Fahrzeugetunen();
    void print();
    void mystackeingeben();
    void mystackausgeben();
    void mystackielement(int a);
    void elementetauschen(int a,int k);
    void Fahrzeugesotrieren();
private:
    vector<Fahrzeug*>autos;
    myStack<Fahrzeug*>stack;


};

#endif // VERWALTUNG_H
