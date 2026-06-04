#include <iostream>
#include <stdlib.h>
using namespace std;

class MatrizGrafo {
private:
    static const int N = 6;
    int matriz[N][N];
    char vertices[N] = {'A', 'B', 'C', 'D', 'E', 'F'};

public:
    // Construtor: inicializa a matriz
    MatrizGrafo() {
        int valores[N][N] = {
            {0,    12,   4,    1000, 1000, 1000}, // A
            {1000, 0,    6,    6,    1000, 1000}, // B
            {1000, 10,   0,    1000, 2,    1000}, // C
            {1000, 1000, 8,    0,    1000, 6},    // D
            {1000, 2,    1000, 1000, 0,    6},    // E
            {1000, 1000, 1000, 1000, 1000, 0}     // F
        };

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matriz[i][j] = valores[i][j];
            }
        }
    }

    // Método para imprimir a matriz
    void imprimir() {
        system("clear");
        
        cout << "\t";

        for (int i = 0; i < N; i++) {
            cout << vertices[i] << "\t";
        }

        cout << endl;

        for (int i = 0; i < N; i++) {
            cout << vertices[i] << "\t";

            for (int j = 0; j < N; j++) {
                cout << matriz[i][j] << "\t";
            }

            cout << endl;
        }
    }
};

int main() {
    MatrizGrafo grafo;

    grafo.imprimir();

    return 0;
}