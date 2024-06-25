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
            //Esto sera recursivo.
        }

    public:
        Backtracking(int m, int P, int n, vector<int> equipos){ // no cambiar nada aca, solo es el constructor.
            this->m = m;
            this->P = P;
            this->n = n;
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
    int m = 4;
    int P = 50;
    int n = 6;
    vector<int> equipos = {40, 30, 40, 50, 10, 30};
    Backtracking b(m, P, n, equipos);
    vector<tupla> mejorSolucion = b.getMejorSolucion();
    for (int i = 0; i < mejorSolucion.size(); ++i) {
        cout << "Bus: " << mejorSolucion[i].bus << ", Equipo: " << mejorSolucion[i].equipo << ", Miembros: " << mejorSolucion[i].miembros << endl;
    }
    cout << "Penalizacion: " << b.getPuntajeSolucion() << endl;
    return 0;
}
