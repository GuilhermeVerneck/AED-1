//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    int testes, qnt, notas;
    char p = '%';
    scanf("%d", &testes);
    
    for (int i = 0; i < testes; i++) {
        scanf("%d", &qnt);
        
        int total = 0;
        int acima_media = 0;
        int notas_array[qnt]; 
        
        for (int j = 0; j < qnt; j++) {
           scanf("%d", &notas_array[j]);
            total += notas_array[j];
        }
        
        float media = (float)total / qnt;
        
        for (int j = 0; j < qnt; j++) {
            if (notas_array[j] > media) {
                acima_media++;
            }
        }
        
        float percentual = ((float)acima_media / qnt) * 100;
        
        printf("%.3f%s\n", percentual, p);
    }

    return 0;
}