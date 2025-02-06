//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>

#define verdadeiro 1
#define falso 0

typedef struct No {
    char caractere;
    struct No *proximo;
} No;

typedef struct Pilha {
    No *topo;
} Pilha;

void inicializarPilha(Pilha *);
void empilhar(Pilha *, char);
void desempilhar(Pilha *);
char obterTopo(Pilha *);
void converterInfixaParaPosfixa(char *);
int obterPrioridade(char, char);

int main() {
    char expressao[400];
    unsigned short quantidadeCasos;

    scanf("%hu", &quantidadeCasos);

    while (quantidadeCasos--) {
        scanf("%s", expressao);
        converterInfixaParaPosfixa(expressao);
    }

    return 0;
}

void inicializarPilha(Pilha *pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, char caractere) {
    No *novoNo = (No *)malloc(sizeof(No));
    if (!novoNo) {
        exit(1);
    }
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    novoNo->caractere = caractere;
}

void desempilhar(Pilha *pilha) {
    No *noRemovido = pilha->topo;
    if (noRemovido) {
        pilha->topo = noRemovido->proximo;
        free(noRemovido);
    }
}

char obterTopo(Pilha *pilha) {
    return (pilha->topo->caractere);
}

int obterPrioridade(char operador1, char operador2) {
    int prioridade1, prioridade2;

    if (operador1 == '^')
        prioridade1 = 3;
    else if (operador1 == '*' || operador1 == '/')
        prioridade1 = 2;
    else if (operador1 == '+' || operador1 == '-')
        prioridade1 = 1;
    else if (operador1 == '(')
        prioridade1 = 4;

    if (operador2 == '^')
        prioridade2 = 3;
    else if (operador2 == '*' || operador2 == '/')
        prioridade2 = 2;
    else if (operador2 == '+' || operador2 == '-')
        prioridade2 = 1;
    else if (operador2 == '(')
        prioridade2 = 0;

    return (prioridade1 > prioridade2);
}

void converterInfixaParaPosfixa(char *expressao) {
    int i = 0;
    char caractere, topoCaractere;
    Pilha pilha;
    inicializarPilha(&pilha);
    empilhar(&pilha, '(');

    do {
        caractere = expressao[i];
        ++i;

        if ((caractere >= 'A' && caractere <= 'Z') || (caractere >= '0' && caractere <= '9') || (caractere >= 'a' && caractere <= 'z'))
            printf("%c", caractere);
        else if (caractere == '(')
            empilhar(&pilha, '(');
        else if (caractere == ')' || caractere == '\0') {
            do {
                topoCaractere = obterTopo(&pilha);
                desempilhar(&pilha);
                if (topoCaractere != '(')
                    printf("%c", topoCaractere);
            } while (topoCaractere != '(');
        } else if (caractere == '+' || caractere == '-' || caractere == '*' || caractere == '^' || caractere == '/') {
            while (verdadeiro) {
                topoCaractere = obterTopo(&pilha);
                desempilhar(&pilha);
                if (obterPrioridade(caractere, topoCaractere)) {
                    empilhar(&pilha, topoCaractere);
                    empilhar(&pilha, caractere);
                    break;
                } else {
                    printf("%c", topoCaractere);
                }
            }
        }
    } while (caractere != '\0');

    printf("\n");
}