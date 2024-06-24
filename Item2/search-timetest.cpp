#include "BinomialArray.h"
#include <chrono>
#include <ctime>
#include <random>
#include <cstdlib>
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
    int repeticiones = 100;
    double tiempo = 0;
    for(int i = 1024; i < pow(2,25); i = (i*2)){
        BinomialArray* a = generateList(i-1);
        double temp = 777.77;
        for(int j=0; j < repeticiones; ++j ){
            auto start = chrono::high_resolution_clock::now();
            a->Buscar(temp);
            auto end = chrono::high_resolution_clock::now();
            tiempo += chrono::duration_cast<chrono::nanoseconds>(end-start).count();
        }
        tiempo /= repeticiones;
        cout<< i-1 << ";" << (int)tiempo <<endl;
        delete a;
    }
}