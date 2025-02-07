//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int numTestes, numAlunos, nota, resposta;
    int *original, *ordenado;

    scanf("%d", &numTestes);

    for (int k = 0; k < numTestes; ++k) {
        scanf("%d", &numAlunos);

        original = (int*)malloc(numAlunos * sizeof(int));
        ordenado = (int*)malloc(numAlunos * sizeof(int));

        for (int i = 0; i < numAlunos; ++i) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }

        qsort(ordenado, numAlunos, sizeof(int), comparar);

        resposta = 0;
        for (int i = 0; i < numAlunos; ++i) {
            if (original[i] == ordenado[i])
                ++resposta;
        }

        printf("%d\n", resposta);

        free(original);
        free(ordenado);
    }

    return 0;
}