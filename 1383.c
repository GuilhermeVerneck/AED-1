#include <stdio.h>
//biblioteca para gerar numeros aleatorios
#include <stdlib.h>  // Necessário para rand() e srand()
#include <time.h>    // Necessário para time()


int main(){
    // Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    int n, i, j, k;
    //gerar numeros aleatorios
    int numero_aleatorio = rand() % 9 + 1;

    //numeros de matrizes
    scanf("%d", &n);
    
    //gerar matriz
    do{
        for(i=0; i<3; i++){
            for (j=0; j<3; j++){
                printf("%d ", numero_aleatorio);
            }
        }
        printf("\n");
        k++;
    }while (k<=n);

}