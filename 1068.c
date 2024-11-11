#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no {
    char caracter;
    struct no *proximo;
};

typedef struct no celula;

celula* empilhar(celula *pilha, char valor) {
    celula *novo = malloc(sizeof(celula));
    if (novo) {
        novo->caracter = valor;
        novo->proximo = pilha;
    }
    return novo;
}

char desempilhar(celula **pilha) {
    if (*pilha) {
        celula *remover = *pilha;
        char valor = remover->caracter;
        *pilha = remover->proximo;
        free(remover);
        return valor;
    }
    return '\0';
}

int BemFormada(char x[]) {
    celula *pilha = NULL;
    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] == '(') {
            pilha = empilhar(pilha, x[i]);
        } 
        else if (x[i] == ')') {
            if (desempilhar(&pilha) != '(') {
                while (pilha) {
                    desempilhar(&pilha);
                }
                return 0;  
            }
        }
    }

    int bemFormada = (pilha == NULL);
    while (pilha) {
        desempilhar(&pilha);
    }
    return bemFormada;
}

int main() {
    char eq[1000];
    int i = 0;
    do {
        fgets(eq, sizeof(eq), stdin);

        size_t len = strlen(eq);
        if (eq[len-1] == '\n') {
                eq[len-1] = '\0';
        }

        if (BemFormada(eq)) {
                printf("correct\n");  
        } else {
                printf("incorrect\n");
        }
        i--;
    } while (i < 0);
    return 0;
}
