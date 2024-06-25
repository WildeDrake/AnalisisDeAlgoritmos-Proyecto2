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
        int temp;
        vector<tupla> mejorSolucion;
        int puntajeSolucion;

        void BacktrackingDFS(vector<tupla> A, int k, int* Buses, int* equipos, int penalizacion, int suma){
            if(suma == 0){ // Caso base
                cout<<"Llega al caso base"<<endl;
                if(penalizacion < puntajeSolucion){
                    puntajeSolucion = penalizacion;
                    mejorSolucion.clear();
                    for(int i = 0; i < A.size(); i++){
                        mejorSolucion.push_back(A[i]);
                    }
                }
            } else { // Caso recursivo 
                for(int i = 0 ; i < m; i++){
                    cout<<"Altura: " <<k<<"---------------------------------------------------------"<<endl;
                    // imprimir equipos
                    cout<<"equipos"<<endl;
                    for (int j = 0; j < n; j++) {
                        cout << equipos[j] << ", ";
                    }
                    cout<<"\nbuses"<<endl;
                    for (int j = 0; j < m; j++) {
                        cout << Buses[j] << ", ";
                    }
                    
                    cout<<"suma: "<<suma<<endl;
                    if (Buses[i] > 0){
                        if(Buses[i] >= equipos[k]){ //Caso en que un bus puede dejar entrar un equipo
                            cout<<"Primera Recursion"<<endl;
                            int aux1 = equipos[k];
                            int aux2 = Buses[i];
                            A.push_back({i, k, equipos[k]});
                            Buses[i] -= equipos[k];
                            equipos[k] = 0;
                            BacktrackingDFS(A, k+1, Buses, equipos, penalizacion, suma - aux1);
                            A.pop_back();
                            equipos[k] = aux1;
                            Buses[i] = aux2;

                        } else {    //Caso en que se va a dejar a una fracción del equipo en el bus
                            cout<<"Segunda Recursion"<<endl;
                            int aux1 = equipos[k];
                            int aux2 = Buses[i];
                            equipos[k] -= Buses[i];
                            A.push_back({i, k, Buses[i]});
                            Buses[i] = 0;
                            if(equipos[k] > 0) BacktrackingDFS(A, k, Buses, equipos, penalizacion + aux1, suma - aux2);
                            else BacktrackingDFS(A, k+1, Buses, equipos, penalizacion, suma - temp);
                            A.pop_back();
                            equipos[k] = aux1;
                            Buses[i] = aux2;
                        }
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
    int equipos[6] = {40, 30, 40, 50, 10, 30};
    Backtracking b(m, P, n, equipos);
    vector<tupla> mejorSolucion = b.getMejorSolucion();
    for (int i = 0; i < mejorSolucion.size(); ++i) {
        cout << "Bus: " << mejorSolucion[i].bus+1 << ", Equipo: " << mejorSolucion[i].equipo+1 << ", Miembros: " << mejorSolucion[i].miembros << endl;
    }
    cout << "Penalizacion: " << b.getPuntajeSolucion() << endl;
    return 0;
}
