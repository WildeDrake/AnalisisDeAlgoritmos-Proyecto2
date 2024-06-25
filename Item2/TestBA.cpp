#include "BinomialArray.h"

int main() {
    BinomialArray pe;
    pe.insertar(2.7);
    pe.insertar(3.5);
    pe.insertar(4.0);
    pe.insertar(3.0);
    pe.insertar(2.0);
    cout<<"Insertados: "<<endl;
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
    cout<<"Buscar "<<endl;
    pair woah = pe.Buscar(3.0);
    cout<<"Posicion del array: "<<woah.first<<" Posicion dentro del array: "<<woah.second<<endl;
    delete &pe;
    return 0;
}