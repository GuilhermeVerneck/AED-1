//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int matrizAdjacencia[50][50];
    int numTestes, verticeInicial, numVertices, numArestas, vertice1, vertice2;

    scanf("%d\n", &numTestes);

    for (int k = 0; k < numTestes; ++k) {
        scanf("%d\n", &verticeInicial);

        scanf("%d %d\n", &numVertices, &numArestas);

        memset(matrizAdjacencia, 0, sizeof(matrizAdjacencia));

        for (int i = 0; i < numArestas; ++i) {
            scanf("%d %d\n", &vertice1, &vertice2);
            matrizAdjacencia[vertice1][vertice2] = 1;
            matrizAdjacencia[vertice2][vertice1] = 1;
        }

        int resposta = 0;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = i; j < numVertices; ++j) {
                if (matrizAdjacencia[i][j] == 1) {
                    ++resposta;
                }
            }
        }

        printf("%d\n", 2 * resposta);
    }

    return 0;
}