#include <iostream>
#include <vector>


using namespace std;

struct tupla{
    int bus; // Indice del bus.
    int equipo; // Indice del equipo.
    int miembros; // Cantidad de miembros.
};

class Backtracking{
    private:
        int m;
        int P;
        int n;
        vector<int> equipos;
        vector<tupla> mejorSolucion;
        int puntajeSolucion;

        void BacktrackingDFS(vector<tupla> A, int k){
            if(k == n){
                int penalizacion = 0;
                for(int i = 0; i < m; i++){
                    int asientos = 0;
                    for(int j = 0; j < A.size(); j++){
                        if(A[j].bus == i){
                            asientos += A[j].miembros;
                        }
                    }
                    if(asientos > P){
                        penalizacion += asientos - P;
                    }
                }
                if(penalizacion < puntajeSolucion){
                    puntajeSolucion = penalizacion;
                    mejorSolucion = A;
                }
            }else{
                for(int i = 0; i < m; i++){
                    A.push_back({i, k, equipos[k]});
                    BacktrackingDFS(A, k + 1);
                    A.pop_back();
                }
            }
        }

    public:
        Backtracking(int m, int P, int n, vector<int> equipos){
            this->m = m;
            this->P = P;
            this->n = n;
            this->puntajeSolucion = INT_MAX;
            this->equipos = equipos;
            vector<tupla> A;
            int k = 0;
            BacktrackingDFS(A, k);
        }
        
        vector<tupla> getMejorSolucion(){
            return mejorSolucion;
        }

        int getPuntajeSolucion(){
            return puntajeSolucion;
        }

        ~Backtracking(){}
};




int main(){
    int m = 4; // Cantidad de buses.
    int P = 50; // Asientos por bus.
    int n = 6; // Cantidad de equipos.
    vector<int> equipos = {40, 20, 40, 50, 10, 30};
    Backtracking b(m, P, n, equipos);
    vector<tupla> mejorSolucion = b.getMejorSolucion();
    for (int i = 0; i < mejorSolucion.size(); ++i) {
        cout << "Bus: " << mejorSolucion[i].bus+1 << ", Equipo: " << mejorSolucion[i].equipo+1 << ", Miembros: " << mejorSolucion[i].miembros << endl;
    }
    cout << "Penalizacion: " << b.getPuntajeSolucion() << endl;
    return 0;
}
