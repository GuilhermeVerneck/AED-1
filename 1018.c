//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    int x = 0;
    scanf("%d", &x);

    int notas;

    if (x >= 100) {
        notas = x / 100;
        x %= 100;
        printf("%d nota(s) de R$ 100,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 100,00\n");
    }

    if (x >= 50) {
        notas = x / 50;
        x %= 50;
        printf("%d nota(s) de R$ 50,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 50,00\n");
    }

    if (x >= 20) {
        notas = x / 20;
        x %= 20;
        printf("%d nota(s) de R$ 20,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 20,00\n");
    }

    if (x >= 10) {
        notas = x / 10;
        x %= 10;
        printf("%d nota(s) de R$ 10,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 10,00\n");
    }

    if (x >= 5) {
        notas = x / 5;
        x %= 5;
        printf("%d nota(s) de R$ 5,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 5,00\n");
    }

    if (x >= 2) {
        notas = x / 2;
        x %= 2;
        printf("%d nota(s) de R$ 2,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 2,00\n");
    }

    if (x >= 1) {
        notas = x / 1;
        x %= 1;
        printf("%d nota(s) de R$ 1,00\n", notas);
    } else {
        printf("0 nota(s) de R$ 1,00\n");
    }

    return 0;
}
