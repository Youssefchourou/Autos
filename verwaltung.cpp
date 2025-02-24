#include "verwaltung.h"
#include <iostream>
#include "fahrzeug.h"
#include "lkw.h"
#include "pkw.h"
#include"mystack.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Hilfsfunktion zum Trimmen (Entfernen von führenden und endenden Leerzeichen und Steuerzeichen)
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\n\r");
    return s.substr(start, end - start + 1);
}

Verwaltung::Verwaltung() { }

Verwaltung::~Verwaltung() {
    for (auto it : autos) {
        delete it;
    }
}

void Verwaltung::benutzerdialog() {
    while (true) {

        cout << "1: Datei einlesen" << endl;
        cout << "2: Fahrzeuge tunen" << endl;
        cout << "3: Fahrzeuge anzeigen" << endl;
        cout<<"4: Fahrzeuge in myStack einlesen"<<endl;
        cout<<"5: Fahrzeuge aus myStack ausgeben"<<endl;
        cout<<"6: Fahrzeug i aus dem Stack anzeigen"<<endl;
        cout<<"7: Fahrzeuge i un dj tauschen"<<endl;
        cout<<"8: Fahrzeuge stack sortieren"<<endl;
        cout << "0: Programm verlassen" << endl;
        char choice;
        cout << "Geben Sie ihre Wahl ein: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            cout << "Geben Sie bitte den Namen der Datei ein: ";
            string name;
            cin >> name;
            try {
                dateieinlesen(name);
            } catch (const invalid_argument &e) {
                cerr << "Fehler: " << e.what() << endl;
            } catch (const runtime_error &e) {
                cerr << "Laufzeitfehler: " << e.what() << endl;
            } catch (const exception &e) {
                cerr << "Allgemeiner Fehler: " << e.what() << endl;
            } catch (...) {
                cerr << "Unbekannter Fehler aufgetreten!" << endl;
            }
            break;
        }
        case '2': {
            Fahrzeugetunen();
            break;
        }
        case '3': {
            Fahrzeugeanzeigen();
            break;
        }
        case'4':{
             mystackeingeben();
            break;
        }
        case'5':{
            mystackausgeben();
            break;
        }
        case'6':{
            cout<<"Geben sie den Index ein"<<endl;
            int n;
            cin>>n;
            mystackielement(n);
            break;

        }
        case'7':{
            cout<<"Geben sie bitte die Indexs ein"<<endl;
            int n,a;
            cin>>n;
            cin>>a;
            elementetauschen(n,a);
            break;
        }
        case'8':{
            Fahrzeugesotrieren();
            break;
        }
        case '0': {
            cout << "Sie wollen das Programm verlassen..." << endl;
            return;
        }
        default:
            cout << "Ungültige Eingabe, bitte erneut versuchen." << endl;
        }
    }
}

void Verwaltung::dateieinlesen(const string &dateiname) {
    ifstream datei(dateiname);

    if (!datei) {
        throw invalid_argument("Fehler beim Öffnen der Datei!");
    }

    string line, currentSection;

    while (getline(datei, line)) {
        line = trim(line);

        if (line.empty()) {
            continue;
        }

        if (line == "LKW" || line == "PKW") {
            currentSection = line;
            continue;
        }

        if (currentSection == "LKW") {
            istringstream iss(line);
            string marke, typ;
            int leistung;
            double zuladung;

            if (!(iss >> marke >> typ >> leistung >> zuladung)) {
                cerr << "WARNUNG: Fehler beim Einlesen der LKW-Zeile: " << line << endl;
                continue;
            }

            Fahrzeug *lkw = new Lkw(marke, typ, leistung, zuladung);
            autos.push_back(lkw);
            cout << "LKW erfolgreich eingelesen." << endl;

        } else if (currentSection == "PKW") {
            istringstream iss(line);
            string marke, typ;
            int leistung, maxSpeed;

            if (!(iss >> marke >> typ >> leistung >> maxSpeed)) {
                cerr << "WARNUNG: Fehler beim Einlesen der PKW-Zeile: " << line << endl;
                continue;
            }

            Fahrzeug *pkw = new Pkw(marke, typ, leistung, maxSpeed);
            autos.push_back(pkw);
            cout << "PKW erfolgreich eingelesen." << endl;
        } else {
            cerr << "WARNUNG: Unbekannter Fahrzeugtyp." << endl;
        }
    }
    datei.close();
    cout << "Datei erfolgreich geladen!" << endl;
}

void Verwaltung::Fahrzeugeanzeigen() {
    for (Fahrzeug *fahr : autos) {
        if (auto lkw = dynamic_cast<Lkw *>(fahr)) {
            cout << "LKW" << endl;
            cout << "Marke: " << lkw->getMarke() << endl;
            cout << "Typ: " << lkw->getTyp() << endl;
            cout << "Leistung: " << lkw->getLeistung() << endl;
            cout << "Zuladung: " << lkw->getZuladung() << endl;
        } else if (auto pkw = dynamic_cast<Pkw *>(fahr)) {
            cout << "PKW" << endl;
            cout << "Marke: " << pkw->getMarke() << endl;
            cout << "Typ: " << pkw->getTyp() << endl;
            cout << "Leistung: " << pkw->getLeistung() << endl;
            cout << "Geschwindigkeit: " << pkw->getGeschwindigkeit() << endl;
        }
    }
}

void Verwaltung::Fahrzeugetunen()
{
    int maxgesch;
    double maxzu;
    for(Fahrzeug* fahr:autos){
        if(auto lkw=dynamic_cast<Lkw*>(fahr)){
            maxzu=lkw->getZuladung()+(lkw->getZuladung()*10)/100;
            lkw->setZuladung(maxzu);
        }else if(auto pkw=dynamic_cast<Pkw*>(fahr)){
            maxgesch=pkw->getGeschwindigkeit()+(pkw->getGeschwindigkeit()*5)/100;
            pkw->setGeschwindigkeit(maxgesch);
        }
    }

}

void Verwaltung::print()
{
    for(auto it:autos){
        cout<<"Fahrzeugeattributen: "<<endl;
        cout<<"Marke:"<<it->getMarke()<<endl;
        cout<<"Leistung"<<it->getLeistung()<<endl;
        cout<<"Typ: "<<it->getTyp()<<endl;
    }


}

void Verwaltung::mystackeingeben()
{
    if(autos.empty()){
        cout<<"Ungültig der vetktor ist leer"<<endl;
    }
    for(Fahrzeug*fahr:autos){
        if(auto pkw=dynamic_cast<Pkw*>(fahr)){
            stack.push_back(pkw);
        }else if(auto lkw=dynamic_cast<Lkw*>(fahr)){
            stack.push_back(lkw);
        }
    }
    cout<<"wurde auf dem Stack reingepusht"<<endl;

}

void Verwaltung::mystackausgeben()
{
    if(stack.empty()){
        cout<<"der Stack ist leer"<<endl;

    }
    Fahrzeug*topelement=stack.pop_back();
    cout<<"Marke: "<<topelement->getMarke()<<"   Leistung:  "<<topelement->getLeistung()<<"  Typ:  "<<topelement->getTyp()<<endl;



}

void Verwaltung::mystackielement(int a)
{
    Fahrzeug*element=stack.get(a);
    cout<<"ELement in Position: "<<a<<  "Marke: "<<element->getMarke()<< "   Leistung: "<<element->getLeistung()<<"  Typ:  "<<element->getTyp()<<endl;

}

void Verwaltung::elementetauschen(int a, int k)
{
    Fahrzeug* element1=stack.get(a);
    Fahrzeug*element2=stack.get(k);
    cout<<"die Marken von der elementen die vertauscht werden: "<<element1->getMarke()<<" und :"<<element2->getMarke()<<endl;
    stack.swapp(a,k);

}

void Verwaltung::Fahrzeugesotrieren()
{
    stack.sortz();



}

