#include "Grafo.h"

using namespace std;

vector<int> Bstrat(Grafo grafo){
    vector<int> vertex_cover;
    int v;
    int counter = 0;
    int best = 0;
    int V = grafo.V;
    bool stopper = true;

    while(stopper){
        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j){
                if(grafo.MatrizAdyacencia[i][j]){
                        ++counter;
                    }
                }
            if(best < counter){
                v = i;
                best = counter;
            }
            counter = 0;
        }

        if(best == 0){
            stopper = false;
        }
        else{
            vertex_cover.push_back(v);

            for(int i = 0; i < V; ++i){
                grafo.MatrizAdyacencia[v][i] = false;
                grafo.MatrizAdyacencia[i][v] = false;
            }
            best = 0;
        }

    }
    return vertex_cover;
}

vector<int> BstratStart6(Grafo grafo){
    vector<int> vertex_cover;
    int v;
    int counter = 0;
    int best = 0;
    int V = grafo.V;
    bool stopper = true;

//Empezar por el 6:

    vertex_cover.push_back(6);

    for(int i = 0; i < V; ++i){
        grafo.MatrizAdyacencia[6][i] = false;
        grafo.MatrizAdyacencia[i][6] = false;
    }
        
//Alg normal

    while(stopper){
        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j){
                if(grafo.MatrizAdyacencia[i][j]){
                        ++counter;
                    }
                }
            if(best < counter){
                v = i;
                best = counter;
            }
            counter = 0;
        }

        if(best == 0){
            stopper = false;
        }
        else{
            vertex_cover.push_back(v);

            for(int i = 0; i < V; ++i){
                grafo.MatrizAdyacencia[v][i] = false;
                grafo.MatrizAdyacencia[i][v] = false;
            }
            best = 0;
        }

    }
    return vertex_cover;
}
int main(){
    Grafo g("grafo3.txt");
    /*vector<int> B = Bstrat(g);
    for(int i = 0; i < B.size(); ++i){
        cout<<B.at(i) << ", ";
    }*/
    vector<int> B = BstratStart6(g);
    for(int i = 0; i < B.size(); ++i){
        cout<<B.at(i) << ", ";
    }  
    cout<<endl;
    cout<<"Tamano: "<<B.size();
}