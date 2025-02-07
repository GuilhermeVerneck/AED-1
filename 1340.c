//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

typedef struct {
    No* frente;
    No* tras;
} Fila;

typedef struct {
    int* elementos;
    int tamanho;
    int capacidade;
} FilaPrioridade;

// Funções para Pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

bool pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

void empilhar(Pilha* pilha, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
}

int desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) return -1;
    No* temp = pilha->topo;
    int valor = temp->valor;
    pilha->topo = temp->proximo;
    free(temp);
    return valor;
}

void destruirPilha(Pilha* pilha) {
    while (!pilhaVazia(pilha)) desempilhar(pilha);
    free(pilha);
}

// Funções para Fila
Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->frente = fila->tras = NULL;
    return fila;
}

bool filaVazia(Fila* fila) {
    return fila->frente == NULL;
}

void enfileirar(Fila* fila, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    if (filaVazia(fila)) {
        fila->frente = novoNo;
    } else {
        fila->tras->proximo = novoNo;
    }
    fila->tras = novoNo;
}

int desenfileirar(Fila* fila) {
    if (filaVazia(fila)) return -1;
    No* temp = fila->frente;
    int valor = temp->valor;
    fila->frente = temp->proximo;
    if (fila->frente == NULL) fila->tras = NULL;
    free(temp);
    return valor;
}

void destruirFila(Fila* fila) {
    while (!filaVazia(fila)) desenfileirar(fila);
    free(fila);
}

// Funções para Fila de Prioridade (usando Max-Heap)
FilaPrioridade* criarFilaPrioridade(int capacidade) {
    FilaPrioridade* filaPrioridade = (FilaPrioridade*)malloc(sizeof(FilaPrioridade));
    filaPrioridade->elementos = (int*)malloc(capacidade * sizeof(int));
    filaPrioridade->tamanho = 0;
    filaPrioridade->capacidade = capacidade;
    return filaPrioridade;
}

bool filaPrioridadeVazia(FilaPrioridade* filaPrioridade) {
    return filaPrioridade->tamanho == 0;
}

// Função para manter a heap ordenada ao inserir elementos
void inserirFilaPrioridade(FilaPrioridade* filaPrioridade, int valor) {
    int i = filaPrioridade->tamanho++;
    filaPrioridade->elementos[i] = valor;

    // Ajusta a posição do novo elemento para manter a propriedade de heap
    while (i > 0 && filaPrioridade->elementos[i] > filaPrioridade->elementos[(i - 1) / 2]) {
        int temp = filaPrioridade->elementos[i];
        filaPrioridade->elementos[i] = filaPrioridade->elementos[(i - 1) / 2];
        filaPrioridade->elementos[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Função para remover o maior elemento da fila de prioridade
int removerFilaPrioridade(FilaPrioridade* filaPrioridade) {
    if (filaPrioridadeVazia(filaPrioridade)) return -1;
    
    int raiz = filaPrioridade->elementos[0];
    filaPrioridade->elementos[0] = filaPrioridade->elementos[--filaPrioridade->tamanho];

    // Ajusta a heap para manter a propriedade de max-heap
    int i = 0;
    while (2 * i + 1 < filaPrioridade->tamanho) {
        int filhoEsq = 2 * i + 1;
        int filhoDir = 2 * i + 2;
        int maior = filhoEsq;

        if (filhoDir < filaPrioridade->tamanho && filaPrioridade->elementos[filhoDir] > filaPrioridade->elementos[filhoEsq]) {
            maior = filhoDir;
        }

        if (filaPrioridade->elementos[i] >= filaPrioridade->elementos[maior]) break;

        int temp = filaPrioridade->elementos[i];
        filaPrioridade->elementos[i] = filaPrioridade->elementos[maior];
        filaPrioridade->elementos[maior] = temp;

        i = maior;
    }

    return raiz;
}

void destruirFilaPrioridade(FilaPrioridade* filaPrioridade) {
    free(filaPrioridade->elementos);
    free(filaPrioridade);
}

// Função principal
int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Pilha* pilha = criarPilha();
        Fila* fila = criarFila();
        FilaPrioridade* filaPrioridade = criarFilaPrioridade(n);
        bool ehPilha = true, ehFila = true, ehFilaPrioridade = true;

        for (int i = 0; i < n; i++) {
            int opcao, elemento;
            scanf("%d %d", &opcao, &elemento);

            if (opcao == 1) { // Inserção
                if (ehPilha) empilhar(pilha, elemento);
                if (ehFila) enfileirar(fila, elemento);
                if (ehFilaPrioridade) inserirFilaPrioridade(filaPrioridade, elemento);
            } else { // Remoção
                if (ehPilha && (pilhaVazia(pilha) || desempilhar(pilha) != elemento)) ehPilha = false;
                if (ehFila && (filaVazia(fila) || desenfileirar(fila) != elemento)) ehFila = false;
                if (ehFilaPrioridade && (filaPrioridadeVazia(filaPrioridade) || removerFilaPrioridade(filaPrioridade) != elemento)) ehFilaPrioridade = false;
            }
        }

        // Determinar qual estrutura foi usada
        if (ehPilha && !ehFila && !ehFilaPrioridade) {
            printf("stack\n");
        } else if (!ehPilha && ehFila && !ehFilaPrioridade) {
            printf("queue\n");
        } else if (!ehPilha && !ehFila && ehFilaPrioridade) {
            printf("priority queue\n");
        } else if (!ehPilha && !ehFila && !ehFilaPrioridade) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }

        // Liberar memória
        destruirPilha(pilha);
        destruirFila(fila);
        destruirFilaPrioridade(filaPrioridade);
    }

    return 0;
}
