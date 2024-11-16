//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    
    int vel = 0;
    double horas = 0.0, distancia = 0.0;

    scanf("%lf", &horas);
    scanf("%d", &vel);

    distancia = (horas*vel)/12;
    printf("%.3f\n", distancia);

    return 0;
}
