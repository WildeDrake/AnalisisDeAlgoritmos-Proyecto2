#include "Grafo.h"

using namespace std;

vector<pair<int,int>> Bstrat(Grafo grafo){
    vector<pair<int,int>> vertex_cover;
    int vcurrent = 0;
    int unext = 0;
    int counter = 0;
    int best = 0;
    bool stopper = true;
    int V = grafo.V;
    while(stopper){
    vector<int>* temp = new vector<int>; 
    //ver cual nodo es adyacente con el actual
    for(int i = 0; i < V; ++i){
        if(grafo.MatrizAdyacencia[vcurrent][i]==true){
            temp->push_back(i);
        }
    }
    if(temp->empty()){
        stopper = false;
    }
    else{
        //Elegir el de mayor grado
        for(int i = 0; i < temp->size();++i){
            int x = temp->at(i);
            for(int j = 0; j < V; ++j){
                if(grafo.MatrizAdyacencia[x][j] == true){
                    ++counter;
                }
            }
            if(best <= counter){
                best = counter;
                unext = x; //Unext es elegido como el nodo de mayor grado adyacente al nodo que estamos analizando
            }
            counter = 0;
        }
        //Eliminamos las instancias del nodo unext en la matriz de adyacencia, "eliminándolo"
        for(int i = 0; i < V; ++i){
            grafo.MatrizAdyacencia[vcurrent][i] = false;
            grafo.MatrizAdyacencia[i][vcurrent] = false;
        }
        vertex_cover.push_back(make_pair(vcurrent,unext)); //Anyadidas al vertex_cover
        vcurrent = unext; // Se prepara para la sgte iteración
        delete temp; // Reiniciamos parámetros
        counter = 0;
        best = 0; 
    }

                    
    }
    return vertex_cover;
}

int main(){
    Grafo g("grafo2.txt");
    vector<pair<int,int>> B = Bstrat(g);
    for(int i = 0; i < B.size(); ++i){
        cout<<B.at(i).first<<","<<B.at(i).second<<endl;
    }
}