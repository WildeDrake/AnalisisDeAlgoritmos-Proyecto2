#include "LasVegas.h"
#include <chrono>
#include <ctime>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std::chrono;


int* generateArray(int size){
    srand(time(NULL));
    int* array = new int[size];
    int x = 0;
    for(int i = 0; i<size ; ++i){
        x = rand();
        array[i] = x;
    }
    return array;
}

int main(){
    cout<<"Size"<<";"<<"Time "<<endl;
    int repeticiones = 10;
    double tiempo = 0;
    for(int i = 2 ; i < 13 ; i = i+1){
        int* a = generateArray(i-1);
        for(int j=0; j < repeticiones; ++j ){
            auto start = chrono::high_resolution_clock::now();
            int* b = LasVegas(i, a, a);
            auto end = chrono::high_resolution_clock::now();
            tiempo += chrono::duration_cast<chrono::milliseconds>(end-start).count();
            delete[] b;
        }
        tiempo /= repeticiones;
        cout<< i << ";" << (int)tiempo <<endl;
        delete a;
    }
    return 0;
}
