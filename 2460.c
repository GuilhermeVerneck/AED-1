//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *proximo;
};

typedef struct no celula;

void inserirFIM(celula **lista, int num) {
    celula *aux, *novo = malloc(sizeof(celula));

    novo->valor = num;
    novo->proximo = NULL;

    if (*lista == NULL) {
        *lista = novo;
    } else {
        aux = *lista;
        while (aux->proximo) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}

void remover(celula **lista, int num){
    celula *p = *lista, *q = NULL;
    
    if (p != NULL && p->valor == num){
        *lista = p->proximo;
        free(p);
        return;
    }
    while (p != NULL && p->proximo != NULL && p->proximo->valor != num){
        p = p->proximo;
    }
    if (p != NULL && p->proximo != NULL){
        q = p->proximo;
        p->proximo = q->proximo;
        free(q);
    }
}

void imprimir(celula *no) {
    celula *p;
    for (p = no->proximo; p != NULL; p = p->proximo){
        if(p->proximo == NULL){
            printf("%d\n", p->valor);
        } else {
            printf("%d ", p->valor);
        }
    }
}

int main() {
    celula *removido, *fila = NULL;
    int entrada;
    int qntd_pessoas = 0, qntd_sair = 0;
    
    scanf("%d", &qntd_pessoas);
    for (int i = 0; i <qntd_pessoas; i++){
        scanf("%d", &entrada);
        inserirFIM(&fila, entrada);
    }

    scanf("%d", &qntd_sair);
    for(int i = 0; i < qntd_sair; i++) {
        scanf("%d", &entrada);
        remover(&fila, entrada);
    }
    
    imprimir(fila);

    while (fila) {
        celula *temp = fila;
        fila = fila->proximo;
        free(temp);
    }
    
    return 0;
}
