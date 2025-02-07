//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int consumos[201];
    double consumoMedio;
    int numTestes, numCasas, numPessoas, consumo, totalPessoas, totalConsumo;
    int cidade = 0;

    while (scanf("%d", &numCasas) && numCasas != 0) {
        if (cidade > 0) {
            printf("\n");
        }

        totalPessoas = 0;
        totalConsumo = 0;
        for (int i = 0; i < 201; ++i) {
            consumos[i] = 0;
        }

        for (int i = 0; i < numCasas; ++i) {
            scanf("%d %d", &numPessoas, &consumo);

            totalPessoas += numPessoas;
            totalConsumo += consumo;
            consumos[consumo / numPessoas] += numPessoas;
        }

        printf("Cidade# %d:\n", ++cidade);
        int primeiro = 1;
        for (int i = 0; i < 201; ++i) {
            if (consumos[i] > 0) {
                if (!primeiro) {
                    printf(" ");
                }
                printf("%d-%d", consumos[i], i);
                primeiro = 0;
            }
        }
        printf("\n");

        consumoMedio = floor((100.0 * totalConsumo) / totalPessoas) / 100.0;
        printf("Consumo medio: %.2f m3.\n", consumoMedio);
    }

    return 0;
}