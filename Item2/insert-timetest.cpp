#include "2.cpp"
#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
using namespace std::chrono;

int main(){
    cout<<"Size"<<";"<<"Time "<<endl;
    int repeticiones = 10;
    double tiempo = 0;
    for(int i = 1000; i < 20000; i+=1000){
        auto start = chrono::high_resolution_clock::now();
        for(int j=0; j < repeticiones; ++j ){
            BinomialArray* a = new BinomialArray();        
            for(int k = 0; k < i; ++k){
                int x =  rand() % 60;        
                x = x+10;
                double temp =  x / 10.0;
                a->insertar(temp);
            }
            delete a;
        }
        auto end = chrono::high_resolution_clock::now();
        tiempo = chrono::duration_cast<chrono::milliseconds>(end-start).count() / repeticiones;
        cout<< i << ";" << tiempo <<endl;
    }
}