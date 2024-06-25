#include "LasVegas.h"


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
    return 0;
}