//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int calcularOperacoes(int inicio, int fim, int numOperacoes);

int main() {
    int inicio, fim;

    scanf("%d %d", &inicio, &fim);
    printf("%d\n", calcularOperacoes(inicio, fim, 1));

    return 0;
}

int calcularOperacoes(int inicio, int fim, int numOperacoes) {
    int operacoes[6], minimo;

    if (inicio * 2 == fim || inicio * 3 == fim || inicio / 2 == fim || inicio / 3 == fim || inicio + 7 == fim || inicio - 7 == fim || numOperacoes > 10) 
        return numOperacoes;
    else {
        operacoes[0] = calcularOperacoes(inicio * 2, fim, numOperacoes + 1);
        operacoes[1] = calcularOperacoes(inicio * 3, fim, numOperacoes + 1);
        operacoes[2] = calcularOperacoes(inicio / 2, fim, numOperacoes + 1);
        operacoes[3] = calcularOperacoes(inicio / 3, fim, numOperacoes + 1);
        operacoes[4] = calcularOperacoes(inicio + 7, fim, numOperacoes + 1);
        operacoes[5] = calcularOperacoes(inicio - 7, fim, numOperacoes + 1);
        minimo = operacoes[0];
        for (int i = 1; i < 6; i++) {
            if (operacoes[i] <= minimo) 
                minimo = operacoes[i];
        }
        return minimo;
    }
}