#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char lista[2000];
    struct cel *proximo;
} No;

void inserirINICIO (No **lista, char alunos[]) {
    No *novo = malloc(sizeof(No));

    strcpy(novo->lista, alunos);
    novo->proximo = *lista;
    *lista = novo;

}

void bubbleSort(No *inicio) {
    if (!inicio) return;

    int trocou;
    No *ptr;
    No *ultimo = NULL;

    do {
        trocou = 0;
        ptr = inicio;

        while (ptr->proximo != ultimo) {
            if (strcmp(ptr->lista, ptr->proximo->lista) > 0) {
                char temp[2000];
                strcpy(temp, ptr->lista);
                strcpy(ptr->lista, ptr->proximo->lista);
                strcpy(ptr->proximo->lista, temp);
                trocou = 1;
            }
            ptr = ptr->proximo;
        }
        ultimo = ptr;
    } while (trocou);
}

char *sorteio(No *no, int ganhador) {
    for (int i = 0; i < ganhador - 1; i++) {
        if (no == NULL) return NULL;
        no = no->proximo;
    }
    return no ? no->lista : NULL; 
}


void imprimir(No *no) {
    while (no) {
        printf("%s", no->lista); 
        no = no->proximo;
    }
    printf("\n");
}

int main() {

    int k = 0, n = 0;
    char nomes[1000];
    No *turma = NULL;

    scanf ("%d %d", &n, &k); 
    getchar();

    for (int i =0; i < n; i++) {
        fgets(nomes, sizeof(nomes), stdin);
        nomes[strcspn(nomes, "\n")] = '\0';
        inserirINICIO(&turma, nomes);
    }

    bubbleSort(turma);
    
    char *vencedor = sorteio(turma, k);
    printf("%s\n", vencedor);

    while (turma) {
        No *prox = turma->proximo;
        free(turma);
        turma = prox;
    }

    return 0;
}