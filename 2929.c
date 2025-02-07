//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

void destruirPilha(Pilha* pilha) {
    while (pilha->topo != NULL) {
        No* temp = pilha->topo;
        pilha->topo = pilha->topo->proximo;
        free(temp);
    }
    free(pilha);
}

void empilhar(Pilha* pilha, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int desempilhar(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return -1; // Pilha vazia
    }
    No* temp = pilha->topo;
    int valor = temp->valor;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    return valor;
}

int topo(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return -1; // Pilha vazia
    }
    return pilha->topo->valor;
}

int main() {
    int numOperacoes, valor;
    char operacao[10];
    Pilha* pilhaMinimos = criarPilha();

    scanf("%d", &numOperacoes);
    for (int i = 0; i < numOperacoes; ++i) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &valor);

            if (pilhaMinimos->topo == NULL) {
                empilhar(pilhaMinimos, valor);
            } else {
                empilhar(pilhaMinimos, valor < topo(pilhaMinimos) ? valor : topo(pilhaMinimos));
            }
        } else if (strcmp(operacao, "POP") == 0) {
            if (pilhaMinimos->topo == NULL) {
                printf("EMPTY\n");
            } else {
                desempilhar(pilhaMinimos);
            }
        } else {
            if (pilhaMinimos->topo == NULL) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", topo(pilhaMinimos));
            }
        }
    }

    destruirPilha(pilhaMinimos);

    return 0;
}