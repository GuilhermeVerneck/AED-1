//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <string.h>

int main() {
    int numTestes, numLinhas, hash, i, elemento;
    char palavra[51];

    scanf("%d", &numTestes);

    while (numTestes--) {
        scanf("%d", &numLinhas);
        hash = 0;
        
        elemento = 0;
        while (numLinhas--) {
            scanf("%s", palavra);

            for (i = 0; i < strlen(palavra); i++)
                hash += (int)palavra[i] - 65 + elemento + i;
            
            elemento++;
        }

        printf("%d\n", hash);
    }

    return 0;
}