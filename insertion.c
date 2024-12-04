//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int const TAM = 20000; 

void insertionSort(int v[TAM]) {
    int i, j, chave;
    for (i = 1; i < TAM; i++) {
        chave = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

int main() {
    clock_t t; 
    int vetor[TAM];
    
    srand((unsigned)time(NULL));

    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    t = clock(); 
    insertionSort(vetor);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}
