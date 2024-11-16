//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    double a = 0.0, b = 0.0, c = 0.0, area = 0.0, pi = 3.14159;

    scanf ("%lf %lf %lf", &a, &b, &c);  
    
    area = a*c/2;
    printf("TRIANGULO: %.3f\n", area);

    area = pi*c*c;
    printf("CIRCULO: %.3f\n", area);
    
    area = ((a+b)*c)/2;
    printf("TRAPEZIO: %.3f\n", area);
    
    area = b*b;
    printf("QUADRADO: %.3f\n", area);

    area = a*b;
    printf("RETANGULO: %.3f\n", area);

    return 0;
}
