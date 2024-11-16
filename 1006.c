//Guilherme da Rocha Verneck Braz 176497


#include <stdio.h>

int main() {

    double a = 0.0, b = 0.0, c = 0.0, media = 0.0;
    scanf ("%lf", &a);
    scanf ("%lf", &b);
    scanf ("%lf", &c);

    media = (2*a + 3*b + 5*c)/10;
    printf("MEDIA = %.1f\n", media);

    return 0;
}
