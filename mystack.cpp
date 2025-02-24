#include "mystack.h"
#include"fahrzeug.h"
#include<algorithm>
#include<fstream>
template<typename T>
myStack<T>::myStack()
{

}

template<typename T>
bool myStack<T>::empty()
{
    return data.empty();

}

template<typename T>
int myStack<T>::size()
{
    return data.size();

}

template<typename T>
void myStack<T>::push_back(T value)
{
    data.push_back(value);

}

template<typename T>
T myStack<T>::pop_back()
{
    if (empty()) {
        throw std::runtime_error("Stack is empty");
    }
    T topElement = data.back();


    data.pop_back();
    return topElement;

}

template<typename T>
T myStack<T>::get(int i)
{

    if(i>data.size()){
        cout<<"ungültige eingabe"<<endl;
    }
    return data[i];
}

template<typename T>
T myStack<T>::swapp(int i, int j)
{

    if(i>data.size() || j>data.size() ||j==i){
        cout<<"der Austausch könnte nicht ausgeführt werden prüfen sie bitte Ihre eingegebene Daten"<<endl;

    }
    swap(data[i],data[j]);
}

template<typename T>
void myStack<T>::sortz()
{
    sort(data.begin(),data.end(),[](Fahrzeug*a,Fahrzeug*b){
      return a->getLeistung()<b->getLeistung();
    });
    ofstream datei("FahrzeugeSort.txt");
    if(!datei){
        cerr<<"Fehler bei der Öffnung von der Datei"<<endl;
    }
    for(Fahrzeug*fahrzeug:data){
        datei<<fahrzeug->getLeistung()<<","<<fahrzeug->getMarke()<<","<<fahrzeug->getTyp()<<" "<<endl;
    }
    datei.close();
    cout<<"Datei wird gespeichert"<<endl;


}



template<typename T>
vector<T> &myStack<T>::getData()
{
    return data;
}
template class myStack<Fahrzeug*>;

