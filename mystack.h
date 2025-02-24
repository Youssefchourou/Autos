#ifndef MYSTACK_H
#define MYSTACK_H
#include<iostream>
#include<vector>
#include"fahrzeug.h"
using namespace std;
template <typename T>

class myStack
{
public:
    myStack();
    bool empty();
    int size();
    void push_back(T);
    T pop_back();
    T get(int i);
    T swapp(int i,int j);

    void sortz();

    vector<T> &getData();

private:
    vector<T>data;
};

#endif // MYSTACK_H
