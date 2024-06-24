#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct tupla{
    int bus; // indice del bus
    int equipo; // indice del equipo
    int miembros; // cantidad de miembros
};

vector<tupla> Backtracking(int m, int P, int n, vector<int> equipos){

}
int main(){
    int m = 4;
    int P = 50;
    int n = 6;
    vector<int> equipos = {40, 30, 40, 50, 10, 30};
    vector<tupla> Resultado = Backtracking(m, P, n, equipos);
    
    return 0;
}
