//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    
    int n = 0, p = 0;
    for (int i = 0; i < 50; i++) {
        p = n+2;
        printf("%d\n", p);
        n = p;
    }
    return 0;

}
