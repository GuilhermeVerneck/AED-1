//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <math.h>

int main() {
    while (1) {
        int L, C, R1, R2;
        scanf("%d %d %d %d", &L, &C, &R1, &R2);
        
        if (L == 0 && C == 0 && R1 == 0 && R2 == 0) {
            break;  
        }

        int maior_raio = (R1 > R2) ? R1 : R2;
        int soma_raios = R1 + R2;

        if ((2 * maior_raio <= L && 2 * maior_raio <= C) && 
            (soma_raios * soma_raios <= (L - R1 - R2) * (L - R1 - R2) + (C - R1 - R2) * (C - R1 - R2))) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    return 0;
}
