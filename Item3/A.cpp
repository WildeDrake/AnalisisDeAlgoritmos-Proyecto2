#include "Grafo.h"


vector<int> A(Grafo G) {
    vector<int> C;
    vector<pair<int, int>> E = G.listaAristas();
    while (E.size() != 0) {
        pair<int, int> arco = E[0];
        C.push_back(arco.first);
        C.push_back(arco.second);
        for (int i = 0 ; i < E.size() ; i++) {
            if (E[i].first == arco.first || E[i].first == arco.second || E[i].second == arco.first || E[i].second == arco.second) {
                E.erase(E.begin() + i);
                i--;
            }
        }
    }
    return C;
}

int main() {
    Grafo G("grafo3.txt");
    vector<int> C = A(G);
    for (int i = 0 ; i < C.size() ; i++) {
        cout << C[i] << ", ";
    }
    cout << endl;
    cout << "Tamano: " << C.size() << endl;
    return 0;
}