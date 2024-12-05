// Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int const TAM = 400000;

int partition(int v[], int low, int high) {
    int pivot = v[high];  
    int i = (low - 1);   

    for (int j = low; j < high; j++) {
        if (v[j] <= pivot) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;

    return (i + 1);
}

void quickSort(int v[], int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main() {
    clock_t t; 
    int vetor[TAM];
    
    srand((unsigned)time(NULL));

    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    t = clock(); 
    quickSort(vetor, 0, TAM - 1);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}
