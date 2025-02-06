//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int calcularMMC(long long int num1, long long int num2);

int main() {
    long long int x, y, z, anoAtual, resultado, proximaData;

    while (scanf("%lld %lld %lld %lld", &anoAtual, &x, &y, &z) != EOF) {
        resultado = calcularMMC(x, calcularMMC(y, z));
        proximaData = resultado - anoAtual;
        printf("%lld\n", proximaData);
    }

    return 0;
}

int calcularMMC(long long int num1, long long int num2) {
    int resto, a, b;
    a = num1;
    b = num2;

    do {
        resto = a % b;
        a = b;
        b = resto;
    } while (resto != 0);

    return (num1 * num2) / a;
}