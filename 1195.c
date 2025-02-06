//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
   int valor;
   struct No *direita, *esquerda;
} No;

No *criarNovoNo(int n) {
   No *novoNo = (No *) malloc(sizeof(No));
   novoNo->valor = n;
   novoNo->esquerda = novoNo->direita = NULL;
   return novoNo;
}

void inserir(int n, No *raiz) {
   if (n < raiz->valor) {
      if (raiz->esquerda != NULL) 
         inserir(n, raiz->esquerda);
      else 
         raiz->esquerda = criarNovoNo(n);
   } else {
      if (raiz->direita != NULL) 
         inserir(n, raiz->direita);
      else 
         raiz->direita = criarNovoNo(n);
   }
}

void preOrdem(No *raiz) {
   if (raiz) {
      printf(" %d", raiz->valor);
      preOrdem(raiz->esquerda);
      preOrdem(raiz->direita);
   }
}

void emOrdem(No *raiz) {
   if (raiz) {
      emOrdem(raiz->esquerda);
      printf(" %d", raiz->valor);
      emOrdem(raiz->direita);
   }
}

void posOrdem(No *raiz) {
   if (raiz) {
      posOrdem(raiz->esquerda);
      posOrdem(raiz->direita);
      printf(" %d", raiz->valor);
   }
}

int main(void) {
   int casos, numNos, i, j, valor;
   scanf("%d", &casos);
   for (i = 1; i <= casos; ++i) {
      scanf("%d", &numNos);
      scanf("%d", &valor);
      No *raiz = criarNovoNo(valor);
      for (j = 0; j < numNos - 1; ++j) {
         scanf("%d", &valor);
         inserir(valor, raiz);
      }
      printf("Case %d:", i);
      printf("\nPre.:"); preOrdem(raiz);
      printf("\nIn..:"); emOrdem(raiz);
      printf("\nPost:"); posOrdem(raiz);
      printf("\n\n");
   }

   return 0;
}