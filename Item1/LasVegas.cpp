#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int* LasVegas(int N, int* P, int* U){
    // Setear el arreglo de 0 hasta N-1. O(n).
    int* A = new int[N];
    for(int i = 0 ; i < N ; i++){
        A[i] = i;
    }
    bool correcto = false;
    while(!correcto){
        // Algoritmo aleatorizado para permutar inplace. O(n).
        for(int i = 0 ; i < N ; i++){
            // Un numero random del i a N-1.
            int j = rand() % (N - i) + i;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        // Verificar si la permutacion es correcta. O(n).
        correcto = true;
        for(int i = 0 ; i < N ; i++){
            if(P[A[i]] < U[i]){
                correcto = false;
                break;
            }
        }
    }
    return A;
}

int main(){
    srand(time(NULL));
    int N = 7;
    int P[] = {8, 20, 10, 3, 50, 2, 5};
    int U[] = {10, 2, 50, 8, 20, 5, 3};
    int* A = LasVegas(N, P, U);
    for(int i = 0 ; i < N ; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    delete[] A;
    delete[] P;
    delete[] U;
    return 0;
}