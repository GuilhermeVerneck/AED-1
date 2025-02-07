//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <string.h>

void removerCaracter(char *str, char charRemover) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != charRemover) dst++;
    }
    *dst = '\0';
}

void removerZerosIniciais(char *str) {
    char *ptr = str;
    while (*ptr == '0') ptr++;
    if (ptr != str) memmove(str, ptr, strlen(ptr) + 1);
}

int main() {
    char D, N[105];

    while (scanf(" %c %s", &D, N) == 2) {
        if (D == '0' && strcmp(N, "0") == 0) break;

        removerCaracter(N, D);
        removerZerosIniciais(N);

        if (strlen(N) == 0) {
            printf("0\n");
        } else {
            printf("%s\n", N);
        }
    }

    return 0;
}