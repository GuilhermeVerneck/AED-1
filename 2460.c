//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdbool.h>

int main() {
    int quantidadePessoas, quantidadeSaidas;

    scanf("%d", &quantidadePessoas);
    int fila[quantidadePessoas];

    for (int i = 0; i < quantidadePessoas; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &quantidadeSaidas);
    bool saiu[100001] = {false}; 

    for (int i = 0; i < quantidadeSaidas; i++) {
        int identificador;
        scanf("%d", &identificador);
        saiu[identificador] = true; 
    }
    
    bool primeiro = true;
    for (int i = 0; i < quantidadePessoas; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = false;
        }
    }
    printf("\n");

    return 0;
}