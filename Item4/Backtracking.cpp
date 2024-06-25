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
        vector<tupla> mejorSolucion;
        int puntajeSolucion;

        void BacktrackingDFS(vector<tupla> A, int k, int* Buses, int* equipos, int penalizacion, int suma){
            // Cota de poda.
            if(penalizacion >= puntajeSolucion) return;

            // Caso base.
            if(suma == 0){
                if(penalizacion < puntajeSolucion){
                    puntajeSolucion = penalizacion;
                    mejorSolucion.clear();
                    for(int i = 0; i < A.size(); i++){
                        mejorSolucion.push_back(A[i]);
                    }
                }

            // Caso recursivo general.
            } else {
                for(int i = 0 ; i < m; i++){
                    if (Buses[i] > 0){
                        //Caso en que un bus puede dejar entrar un equipo completo.
                        if(Buses[i] >= equipos[k]){ 
                            int aux1 = equipos[k];
                            int aux2 = Buses[i];
                            A.push_back({i, k, equipos[k]});
                            Buses[i] -= aux1;
                            equipos[k] = 0;
                            BacktrackingDFS(A, k+1, Buses, equipos, penalizacion, suma - aux1);
                            A.pop_back();
                            equipos[k] = aux1;
                            Buses[i] = aux2;
                        //Caso en que se va a dejar a una fracción del equipo en el bus
                        } else {
                            int aux1 = equipos[k];
                            int aux2 = Buses[i];
                            equipos[k] -= aux2;
                            A.push_back({i, k, Buses[i]});
                            Buses[i] = 0;
                            if(equipos[k] > 0) BacktrackingDFS(A, k, Buses, equipos, penalizacion + min(equipos[k], aux2), suma - aux2);
                            else BacktrackingDFS(A, k+1, Buses, equipos, penalizacion, suma - aux2);
                            A.pop_back();
                            equipos[k] = aux1;
                            Buses[i] = aux2;
                        }
                    }
                }
            }
            delete[] Buses;
            delete[] equipos;
        }

    public:
        Backtracking(int m, int P, int n, int* equipos){
            this->m = m;
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
    int equipos[6] = {40, 20, 40, 50, 10, 30};
    Backtracking b(m, P, n, equipos);
    vector<tupla> mejorSolucion = b.getMejorSolucion();
    for (int i = 0; i < mejorSolucion.size(); ++i) {
        cout << "Bus: " << mejorSolucion[i].bus+1 << ", Equipo: " << mejorSolucion[i].equipo+1 << ", Miembros: " << mejorSolucion[i].miembros << endl;
    }
    cout << "Penalizacion: " << b.getPuntajeSolucion() << endl;
    return 0;
}