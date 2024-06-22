#include "2.cpp"
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
using namespace std::chrono;

BinomialArray* generateList(int size){
    srand(time(NULL));
    BinomialArray* list = new BinomialArray();
    int x = 0;
    double temp = 0;
    for(int i = 0; i<size ; ++i){
        x = rand() % 60;
        x = x+10;
        temp =   x / 10.0;
        list->insertar(temp);
    }
    return list;
}

int main(){
    cout<<"Size"<<";"<<"Time "<<endl;
    int repeticiones = 10;
    double tiempo = 0;
    for(int i = 1000; i < 20000; i+=1000){
        BinomialArray* a = generateList(i);
        auto start = chrono::high_resolution_clock::now();
        for(int j=0; j < repeticiones; ++j ){
            int x =  rand() % 60;
            x = x+10;
            double temp =  x / 10.0;
            a->Buscar(temp);
        }
    auto end = chrono::high_resolution_clock::now();
    tiempo = chrono::duration_cast<chrono::nanoseconds>(end-start).count() / repeticiones;
    cout<< i << ";" << tiempo <<endl;
    delete a;
    }
}