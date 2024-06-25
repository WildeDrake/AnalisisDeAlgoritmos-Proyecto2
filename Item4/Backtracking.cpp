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
        int m; // Cantidad de buses.
        int P; // Asientos por bus.
        int n; // Cantidad de equipos.
        vector<tupla> mejorSolucion;
        int puntajeSolucion;

        void BacktrackingDFS(vector<tupla> A, int k, int* Buses, int* equipos, int penalizacion, int suma){
            if(suma == 0){ // Caso base
                if(penalizacion < puntajeSolucion){
                    puntajeSolucion = penalizacion;
                    mejorSolucion = A;
                }
            } else { // Caso recursivo 
                for(int i = 0 ; i < m; i++){
                    if(Buses[i] >= equipos[k]){
                        A.push_back({i, k, equipos[k]});
                        Buses[i] -= equipos[k];
                        BacktrackingDFS(A, k+1, Buses, equipos, penalizacion, suma - equipos[k]);
                    } else {
                        equipos[k] -= Buses[i];
                        A.push_back({i, k, Buses[i]});
                        Buses[i] = 0;
                        BacktrackingDFS(A, k, Buses, equipos, penalizacion + equipos[k], suma - Buses[i]);
                    }
                }
            }
        }

    public:
        Backtracking(int m, int P, int n, int* equipos){
            this->m = m;
            this->P = P;
            this->n = n;
            this->puntajeSolucion = INT_MAX;
            vector<tupla> A;
            int* buses = new int[m];
            for(int i = 0; i < m; i++){
                buses[i] = P;
            }
            int suma = 0;
            for(int i = 0; i < n; i++){
                suma += equipos[i];
            }
            BacktrackingDFS(A, 0, buses, equipos, 0, suma);
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
    int equipos[6] = {10, 20, 30, 40, 50, 60};
    Backtracking b(m, P, n, equipos);
    vector<tupla> mejorSolucion = b.getMejorSolucion();
    for (int i = 0; i < mejorSolucion.size(); ++i) {
        cout << "Bus: " << mejorSolucion[i].bus+1 << ", Equipo: " << mejorSolucion[i].equipo+1 << ", Miembros: " << mejorSolucion[i].miembros << endl;
    }
    cout << "Penalizacion: " << b.getPuntajeSolucion() << endl;
    return 0;
}
