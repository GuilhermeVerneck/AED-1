//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void inicializarLista(Lista *l) {
    l->inicio = NULL;
    l->tam = 0;
}

void inserir_na_lista(Lista *l, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (novo) {
        novo->chave = valor;
        novo->proximo = NULL; 
        if (l->inicio == NULL) {
            l->inicio = novo;
        } else {
            No *aux = l->inicio;
            while (aux->proximo != NULL) {
                aux = aux->proximo;
            }
            aux->proximo = novo; 
        }
        l->tam++;
    } else {
        printf("erro\n");
    }
}

void imprimir_lista(Lista *l) {
    No *aux = l->inicio;
    if (aux == NULL) {
        printf("\\\n");
        return;
    }
    
    while (aux) {
        printf("%d", aux->chave);
        aux = aux->proximo;
        if (aux) {
            printf(" -> ");
        } else {
            printf(" -> \\"); 
        }
    }
    printf("\n");
}
int hash(int chave, int tam) {
    return chave % tam;
}

void imprimir(Lista t[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d -> ", i);
        imprimir_lista(&t[i]);
    }
}

void iniciarTabela(Lista t[], int tam) {
    for (int i = 0; i < tam; i++) {
        inicializarLista(&t[i]);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int M = 0, C = 0;
        scanf("%d %d", &M, &C);
        
        Lista tabela[M];
        iniciarTabela(tabela, M);
        
        for (int j = 0; j < C; j++) {
            int key;
            scanf("%d", &key);
            int id = hash(key, M);
            inserir_na_lista(&tabela[id], key);
        }
        
        imprimir(tabela, M);
        
        if (i < N - 1) {
            printf("\n"); 
        }
    }

    return 0;
}