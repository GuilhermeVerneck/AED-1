//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    double matriz[12][12];
    char operacao;
    double soma = 0;
    int contador = 1;
    int totalElementos = 0;

    scanf(" %c", &operacao);

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 11; i++) {
        for (int j = contador; j < 12; j++) {
            soma += matriz[i][j];
            totalElementos++;
        }
        contador++;
    }

    if (operacao == 'S') {
        printf("%.1lf\n", soma);
    } else {
        printf("%.1lf\n", soma / totalElementos);
    }

    return 0;
}