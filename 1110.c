//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* frente;
    No* tras;
} Deque;

Deque* criarDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->frente = NULL;
    deque->tras = NULL;
    return deque;
}

bool dequeVazio(Deque* deque) {
    return deque->frente == NULL;
}

void inserirTras(Deque* deque, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (dequeVazio(deque)) {
        deque->frente = novoNo;
    } else {
        deque->tras->proximo = novoNo;
    }
    deque->tras = novoNo;
}

int removerFrente(Deque* deque) {
    if (dequeVazio(deque)) {
        return -1; // Deque vazio
    }
    No* temp = deque->frente;
    int valor = temp->valor;
    deque->frente = deque->frente->proximo;
    if (deque->frente == NULL) {
        deque->tras = NULL;
    }
    free(temp);
    return valor;
}

void destruirDeque(Deque* deque) {
    while (!dequeVazio(deque)) {
        removerFrente(deque);
    }
    free(deque);
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        Deque* deque = criarDeque();
        for (int i = 1; i <= n; i++) {
            inserirTras(deque, i);
        }

        printf("Discarded cards:");
        bool primeiro = true;
        while (deque->frente != deque->tras) {
            if (!primeiro) {
                printf(",");
            }
            printf(" %d", removerFrente(deque));
            inserirTras(deque, removerFrente(deque));
            primeiro = false;
        }
        printf("\nRemaining card: %d\n", removerFrente(deque));

        destruirDeque(deque);
    }

    return 0;
}