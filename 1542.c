//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    int paginasLidasPorDia, dias, paginasPorDia, paginasTotais;

    while (scanf("%d", &paginasLidasPorDia) && paginasLidasPorDia != 0) {
        scanf("%d %d", &dias, &paginasPorDia);

        paginasTotais = (paginasLidasPorDia * dias * paginasPorDia) / (paginasPorDia - paginasLidasPorDia);

        printf("%d pagina", paginasTotais);
        if (paginasTotais > 1) {
            printf("s");
        }
        printf("\n");
    }

    return 0;
}