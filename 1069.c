//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <string.h>

int main() {

    char minerio[1001];
    int num = 0;

    scanf("%d", &num);
    getchar();

    for (int i = 0; i < num; i++) {
        int pilha = 0, diamantes = 0;
        fgets(minerio, sizeof(minerio), stdin);
        minerio[strcspn(minerio, "\n")] = '\0';
        for (int j = 0; minerio[j] != '\0'; j++ ) {
            if (minerio[j] == '<') {
                pilha++;
            } else if (minerio[j] == '>') {
                if (pilha > 0) {
                    pilha--;
                    diamantes++;
                }
            }
        }
        printf("%d\n", diamantes);
    }
    
    return 0;
}