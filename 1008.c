#include <stdio.h>

int main() {
    int num = 0, horas = 0;
    double valor = 0.0, sal = 0.0;
    scanf ("%d", &num);
    scanf ("%d", &horas);
    scanf ("%lf", &valor);

    sal = valor * horas;

    printf ("NUMBER = %d\n", num);
    printf ("SALARY = U$ %.2f\n", sal);

    return 0;
}