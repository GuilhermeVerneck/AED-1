//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000000

int distancia[MAX], marcacao[MAX];

typedef struct {
    int elementos[MAX];
    int frente, tras;
} Fila;

void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

bool filaVazia(Fila *f) {
    return f->frente == f->tras;
}

void enfileirar(Fila *f, int valor) {
    f->elementos[f->tras++] = valor;
}

int desenfileirar(Fila *f) {
    return f->elementos[f->frente++];
}

int main() {
    int origem, destino, k;
    Fila fila;

    while (scanf("%d %d %d", &origem, &destino, &k), origem || destino || k) {
        memset(distancia, -1, sizeof(distancia));
        memset(marcacao, 0, sizeof(marcacao));

        for (int i = 0; i < k; i++) {
            int naoPassar;
            scanf("%d", &naoPassar);
            marcacao[naoPassar] = 1;
        }

        inicializarFila(&fila);
        distancia[origem] = 0;
        enfileirar(&fila, origem);

        while (!filaVazia(&fila)) {
            if (distancia[destino] != -1) {
                break;
            }
            int v = desenfileirar(&fila);
            if (!marcacao[v + 1] && v + 1 <= 100000 && distancia[v + 1] == -1) {
                distancia[v + 1] = distancia[v] + 1;
                enfileirar(&fila, v + 1);
            }
            if (!marcacao[v - 1] && v - 1 > 0 && distancia[v - 1] == -1) {
                distancia[v - 1] = distancia[v] + 1;
                enfileirar(&fila, v - 1);
            }
            if (v * 2 <= 100000 && !marcacao[v * 2] && distancia[v * 2] == -1) {
                distancia[v * 2] = distancia[v] + 1;
                enfileirar(&fila, v * 2);
            }
            if (v * 3 <= 100000 && !marcacao[v * 3] && distancia[v * 3] == -1) {
                distancia[v * 3] = distancia[v] + 1;
                enfileirar(&fila, v * 3);
            }
            if (v % 2 == 0 && !marcacao[v / 2] && distancia[v / 2] == -1) {
                distancia[v / 2] = distancia[v] + 1;
                enfileirar(&fila, v / 2);
            }
        }

        printf("%d\n", distancia[destino]);
    }

    return 0;
}