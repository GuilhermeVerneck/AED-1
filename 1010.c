#include <stdio.h>

int main() {
    int codigo1 = 0, num1 = 0, codigo2 = 0, num2 = 0;
    double preco1 = 0.0, preco2 = 0.0, total = 0.0;

    scanf ("%d %d %lf", &codigo1, &num1, &preco1);
    scanf ("%d %d %lf", &codigo2, &num2, &preco2);

    total = (num1*preco1) + (num2*preco2);
    printf("VALOR A PAGAR: R$ %.2f\n", total);
    return 0;
}