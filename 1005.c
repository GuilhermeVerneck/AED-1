#include <stdio.h>

int main() {

    double a = 0.0, b = 0.0, media = 0.0;
    scanf ("%lf", &a);
    scanf ("%lf", &b);
    media = (3.5*a + 7.5*b)/11;
    printf("MEDIA = %.5f\n", media);

    return 0;
}