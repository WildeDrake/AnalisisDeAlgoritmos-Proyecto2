#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct BinomialArray {
    vector<double*> Arrays;
    vector<int> sizes;
    int NumArrays;
    int size;

    BinomialArray() {
        Arrays = vector<double*>();
        sizes = vector<int>();
        NumArrays = 0;
        size = 0;
    }

    ~BinomialArray() {
        for (auto arr : Arrays) {
            delete[] arr;
        }
    }

    void insertar(double promedio) {
        size++;
        double* temp = new double();
        temp[0] = promedio;
        Arrays.push_back(temp);
        sizes.push_back(1);
        NumArrays++;
        for (int i = NumArrays - 1 ; i > 0 ; --i) {
            if (sizes[i] == sizes[i - 1]) {
                double* temp = new double[sizes[i] * 2];
                merge(Arrays[i], Arrays[i] + sizes[i], Arrays[i - 1], Arrays[i - 1] + sizes[i - 1], temp);
                delete[] Arrays[i];
                delete[] Arrays[i - 1];
                Arrays[i - 1] = temp;
                sizes[i - 1] *= 2;
                Arrays.pop_back();
                sizes.pop_back();
                NumArrays--;
            } else {
                break;
            }
        }
    }

    // Esto es una Búsqueda Binaria recursiva común y corriente.
    double binarySearch(double* array, int size, double x) {
    int left = 0; 
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == x) {
            return mid;
        }
        if (array[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
    }

    // Retorno: (i, j) con i es el indice del array y j es el indice del elemento en el array.
    // x: valor a buscar.
    pair<int, int> Buscar(double x) {
        int i = 0;
        while (i < NumArrays) { //NumArrays almacena los arrays que hay en el BinomialArray.
            int iarray = binarySearch(Arrays[i], sizes[i], x); // Realizamos una busqueda binaria en el array i.
            if (iarray != -1) { 
                return {i, iarray};
            }
            i++;
        }
        return {-1, -1};
    }
};



/*int main() {
    BinomialArray pe;
    pe.insertar(2.7);
    pe.insertar(3.5);
    pe.insertar(4.0);
    pe.insertar(3.0);
    pe.insertar(2.0);

    for (int i = 0; i < pe.NumArrays; ++i) {
        for (int j = 0; j < pe.sizes[i]; ++j) {
            cout << pe.Arrays[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < pe.NumArrays; ++i) {
        cout << pe.sizes[i] << " ";
    }
    cout << endl;

    return 0;
}*/