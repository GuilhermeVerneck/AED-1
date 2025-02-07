//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void floydWarshall(long **grafo, int numVertices) {
    for (int k = 1; k <= numVertices; ++k) {
        for (int i = 1; i <= numVertices; ++i) {
            for (int j = 1; j <= numVertices; ++j) {
                if (grafo[i][k] != INF && grafo[k][j] != INF) {
                    if (grafo[i][j] > grafo[i][k] + grafo[k][j]) {
                        grafo[i][j] = grafo[i][k] + grafo[k][j];
                    }
                }
            }
        }
    }
}

int main() {
    int numVertices, numArestas;

    while (scanf("%d %d", &numVertices, &numArestas) && (numVertices != 0 || numArestas != 0)) {
        long **grafo = (long **)malloc((numVertices + 1) * sizeof(long *));
        for (int i = 0; i <= numVertices; ++i) {
            grafo[i] = (long *)malloc((numVertices + 1) * sizeof(long));
            for (int j = 0; j <= numVertices; ++j) {
                grafo[i][j] = INF;
            }
        }

        for (int i = 0; i < numArestas; ++i) {
            int origem, destino, peso;
            scanf("%d %d %d", &origem, &destino, &peso);
            grafo[origem][destino] = peso;
        }

        for (int i = 1; i <= numVertices; ++i) {
            for (int j = i; j <= numVertices; ++j) {
                if (grafo[i][j] != INF && grafo[j][i] != INF) {
                    grafo[i][j] = 0;
                    grafo[j][i] = 0;
                }
            }
        }

        floydWarshall(grafo, numVertices);

        int numConsultas;
        scanf("%d", &numConsultas);
        for (int i = 0; i < numConsultas; ++i) {
            int origem, destino;
            scanf("%d %d", &origem, &destino);

            if (grafo[origem][destino] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%ld\n", grafo[origem][destino]);
            }
        }
        printf("\n");

        for (int i = 0; i <= numVertices; ++i) {
            free(grafo[i]);
        }
        free(grafo);
    }

    return 0;
}