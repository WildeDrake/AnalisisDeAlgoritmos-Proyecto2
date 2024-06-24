#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


struct Grafo {
    int V;
    int E;
    bool** Matriz;

    Grafo (string nombreArchivo) {
        ifstream file(nombreArchivo);
        string line;
        getline(file, line);
        stringstream ss(line);
        ss >> V >> E;
        Matriz = new bool*[V];
        for (int i = 0 ; i < V ; i++) {
            Matriz[i] = new bool[V];
            for (int j = 0 ; j < V ; j++) {
                Matriz[i][j] = false;
            }
        }
        E = 0;
        while (getline(file, line)) {
            stringstream ss(line);
            int v, w;
            ss >> v >> w;
            if (Matriz[v-1][w-1] == false ) E++;
            Matriz[v-1][w-1] = true;
            Matriz[w-1][v-1] = true;
        }
    }

    void imprimir() {
        cout << "Vertices: " << V << "\nAristas: " << E << endl;
        for (int i = 0 ; i < V ; i++) {
            for (int j = 0 ; j < V ; j++) {
                cout << Matriz[i][j] << " ";
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