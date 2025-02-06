//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char itens [1001];
    struct no *proximo;
}Celula; 

void inserir (Celula *lst, char comida) {
    Celula *novo = malloc(sizeof(Celula));

    strcpy (novo->itens, comida);
    novo->proximo = lst->proximo;
    lst->proximo = novo;

}

int main() {

    int n;

    scanf("%d", &n);
    gethar();

    for (int i = 0; i < n; i++) {
        char lista[1001];
        char compras[1001];
        fgets(compras, sizeof(compras), stdin);
        for (int j = 0; lista[j] != '\0'; j++){
            inserir(&lista, compras);
        }
        printf("%s ", lista);
    }



    return 0;
}