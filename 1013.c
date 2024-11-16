//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int a = 0, b = 0, c = 0, maiorAB = 0, maiorCC = 0;

    scanf ("%d %d %d", &a, &b, &c);

    maiorAB = (a+b+abs(a-b))/2;
    maiorCC = (maiorAB+c+abs(maiorAB-c))/2;

    printf("%d eh o maior\n", maiorCC);

    return 0;
}
