//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main () {

    float nota = 0, media = 0, nota_valida = 0;
    int valida = 0;
    
    while (valida < 2) {
        scanf("%f", &nota);
        if (nota > 10 || nota < 0) {
            printf ("nota invalida\n");
            while (getchar() != '\n');
            continue;
        } else {
            valida++;
            nota_valida += nota;
        }
    }
    
    media = nota_valida/2;
    printf("media = %.2f\n",media);

    return 0;
}