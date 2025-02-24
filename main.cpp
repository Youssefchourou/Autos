#include <iostream>
#include<verwaltung.h>
#include<fahrzeug.h>
using namespace std;

int main()
{
    Fahrzeug auto1("BMW","X6",200);
    cout<<auto1<<endl;
    Verwaltung*auf=new Verwaltung();
    auf->benutzerdialog();
    delete auf;
    return 0;
}
