//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

int numCidades, numEstradas, numRota, origem;
int grafo[1010][1010];
int custo[1010];

typedef struct {
    int elementos[1010];
    int frente, tras;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = 0;
    fila->tras = 0;
}

bool filaVazia(Fila *fila) {
    return fila->frente == fila->tras;
}

void enfileirar(Fila *fila, int valor) {
    fila->elementos[fila->tras++] = valor;
}

int desenfileirar(Fila *fila) {
    return fila->elementos[fila->frente++];
}

void inicializarGrafo() {
    for (int i = 0; i <= numCidades; i++) {
        custo[i] = INF;
        for (int j = 0; j <= numCidades; j++) {
            grafo[i][j] = INF;
        }
    }
}

int dijkstra(int origem, int destino) {
    Fila fila;
    inicializarFila(&fila);
    custo[origem] = 0;
    enfileirar(&fila, origem);
    while (!filaVazia(&fila)) {
        int i = desenfileirar(&fila);
        for (int j = 0; j < numCidades; j++) {
            if (grafo[i][j] != INF && custo[j] > custo[i] + grafo[i][j]) {
                custo[j] = custo[i] + grafo[i][j];
                enfileirar(&fila, j);
            }
        }
    }
    return custo[destino];
}

int main() {
    while (scanf("%d %d %d %d", &numCidades, &numEstradas, &numRota, &origem), (numCidades || numEstradas || numRota || origem)) {
        inicializarGrafo();
        
        for (int i = 1; i <= numEstradas; i++) {
            int cidade1, cidade2, peso;
            scanf("%d %d %d", &cidade1, &cidade2, &peso);
            
            if (cidade1 >= numRota && cidade2 >= numRota) {
                grafo[cidade1][cidade2] = peso;
                grafo[cidade2][cidade1] = peso;
            }
            if (cidade1 >= numRota && cidade2 < numRota) {
                grafo[cidade1][cidade2] = peso;
            }
            if (cidade1 < numRota && cidade2 >= numRota) {
                grafo[cidade2][cidade1] = peso;
            }
            if (cidade1 < numRota && cidade2 < numRota && abs(cidade1 - cidade2) == 1) {
                grafo[cidade1][cidade2] = peso;
                grafo[cidade2][cidade1] = peso;
            }
        }
        
        printf("%d\n", dijkstra(origem, numRota - 1));
    }
    return 0;
}