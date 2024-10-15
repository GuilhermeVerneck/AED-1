#include <stdio.h>
 
int main() {
    int d, anos, meses, dias;
    scanf("%d", &d);
    anos = d/365;
    d %= 365;
    meses = d/30;
    d %= 30;
    dias = d;
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    return 0;
}