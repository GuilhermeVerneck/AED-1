//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AVIOES 1000
#define MAX_TEXTO 100

typedef struct {
    char texto[MAX_TEXTO];
} Aviao;

typedef struct {
    Aviao avioes[MAX_AVIOES];
    int tamanho;
} ListaAvioes;

void inicializarLista(ListaAvioes *lista) {
    lista->tamanho = 0;
}

void adicionarAviao(ListaAvioes *lista, char *texto) {
    if (lista->tamanho < MAX_AVIOES) {
        strcpy(lista->avioes[lista->tamanho].texto, texto);
        lista->tamanho++;
    }
}

void inverterLista(ListaAvioes *lista) {
    for (int i = 0; i < lista->tamanho / 2; i++) {
        Aviao temp = lista->avioes[i];
        lista->avioes[i] = lista->avioes[lista->tamanho - 1 - i];
        lista->avioes[lista->tamanho - 1 - i] = temp;
    }
}

void juntarTextos(ListaAvioes *lista, char *resultado) {
    resultado[0] = '\0';
    for (int i = 0; i < lista->tamanho; i++) {
        strcat(resultado, lista->avioes[i].texto);
        if (i < lista->tamanho - 1) {
            strcat(resultado, " ");
        }
    }
}

void pousos(ListaAvioes *avioes, char *resultado) {
    if (avioes[0].tamanho == 0 && avioes[1].tamanho == 0 && avioes[2].tamanho == 0 && avioes[3].tamanho == 0) {
        resultado[0] = '\0';
    } else {
        char temp[MAX_TEXTO * MAX_AVIOES];
        juntarTextos(&avioes[0], temp);
        strcat(resultado, temp);
        pousos(&avioes[1], temp);
        strcat(resultado, temp);
    }
}

int main() {
    ListaAvioes avioes[4];
    for (int i = 0; i < 4; i++) {
        inicializarLista(&avioes[i]);
    }

    char a[MAX_TEXTO];
    int sentido = 1;

    while (scanf("%s", a) && strcmp(a, "0") != 0) {
        if (a[0] == '-') {
            sentido = -atoi(a);
        } else {
            adicionarAviao(&avioes[sentido], a);
        }
    }

    ListaAvioes avioesOrdenados[4] = {avioes[0], avioes[2], avioes[1], avioes[3]};
    for (int i = 0; i < 4; i++) {
        inverterLista(&avioesOrdenados[i]);
    }

    char resultado[MAX_TEXTO * MAX_AVIOES];
    pousos(avioesOrdenados, resultado);
    printf("%s\n", resultado);

    return 0;
}