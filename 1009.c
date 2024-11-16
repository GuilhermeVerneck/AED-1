//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    char nome;
    double sal = 0.0, vendas = 0.0, total = 0.0;

    scanf ("%s", &nome);
    scanf ("%lf", &sal);
    scanf ("%lf", &vendas);

    total = sal + (vendas*0.15);
    printf ("TOTAL = R$ %.2f\n", total);
}
