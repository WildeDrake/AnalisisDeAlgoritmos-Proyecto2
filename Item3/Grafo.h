#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;


struct Grafo {
    int V;
    int E;
    bool** MatrizAdyacencia;

    Grafo (string nombreArchivo) {
        ifstream file(nombreArchivo);
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> V >> E;
        MatrizAdyacencia = new bool*[V];
        for (int i = 0 ; i < V ; i++) {
            MatrizAdyacencia[i] = new bool[V];
            for (int j = 0 ; j < V ; j++) {
                MatrizAdyacencia[i][j] = false;
            }
        }
        E = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            int v, w;
            ss >> v >> w;
            if (MatrizAdyacencia[v-1][w-1] == false ){
                MatrizAdyacencia[v-1][w-1] = true;
                MatrizAdyacencia[w-1][v-1] = true;
                E++;
            }
        }
    }

    vector<pair<int, int>> listaAristas() {
        vector<pair<int, int>> aristas;
        for (int i = 0 ; i < V ; i++) {
            for (int j = i ; j < V ; j++) {
                if (MatrizAdyacencia[i][j]) {
                    aristas.push_back(make_pair(i, j));
                }
            }
        }
        return aristas;
    }

    void imprimir() {
        cout << "Vertices: " << V << "\nAristas: " << E << endl;
        for (int i = 0 ; i < V ; i++) {
            for (int j = 0 ; j < V ; j++) {
                cout << MatrizAdyacencia[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~Grafo() {
        for (int i = 0 ; i < V ; i++) {
            delete[] MatrizAdyacencia[i];
        }
        delete[] MatrizAdyacencia;
    }
};