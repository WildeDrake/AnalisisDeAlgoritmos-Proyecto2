#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;


struct Grafo {
    int V;
    int E;
    bool** MatrizAdyecencia;
    pair<int, int> *Grados;
    
    Grafo (string nombreArchivo) {
        ifstream file(nombreArchivo);
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> V >> E;
        MatrizAdyecencia = new bool*[V];
        for (int i = 0 ; i < V ; i++) {
            MatrizAdyecencia[i] = new bool[V];
            for (int j = 0 ; j < V ; j++) {
                MatrizAdyecencia[i][j] = false;
            }
        }
        E = 0;
        Grados = new pair<int, int>[V];
        for (int i = 0 ; i < V ; i++) {
            Grados[i] = make_pair(i, 0);
        }
        while (getline(file, line)) {
            stringstream ss(line);
            int v, w;
            ss >> v >> w;
            if (MatrizAdyecencia[v-1][w-1] == false ){
                MatrizAdyecencia[v-1][w-1] = true;
                MatrizAdyecencia[w-1][v-1] = true;
                Grados[v-1].second++;
                Grados[w-1].second++;
                E++;
            }
        }
    }

    void OrdenarGrados() {
        sort(Grados, Grados + V, [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
    }

    void imprimir() {
        cout << "Vertices: " << V << "\nAristas: " << E << endl;
        for (int i = 0 ; i < V ; i++) {
            for (int j = 0 ; j < V ; j++) {
                cout << MatrizAdyecencia[i][j] << " ";
            }
            cout << endl;
        }
    }
};



int main() {
    Grafo g("grafo2.txt");
    g.imprimir();
    return 0;
}