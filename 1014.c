//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {

    int x = 0;
    double km = 0.0, total = 0.0;

    scanf ("%d", &x);
    scanf ("%lf", &km);

    total = x/km;
    printf("%.3f km/l\n", total);

    return 0;
}
