//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

void direcao(int *linha, int *coluna, char direcao) {
    if (direcao == '>') {
        (*coluna)++;
    } else if (direcao == '<') {
        (*coluna)--;
    } else if (direcao == 'v') {
        (*linha)++;
    } else if (direcao == '^') {
        (*linha)--;
    } 
}

int procurar(char matriz[100][100], int linhas, int colunas) {
    int linha_atual = 0, coluna_atual = 0;
    char seta;

    if (matriz[linha_atual][coluna_atual] == '>') {
        seta = '>';
    } else if (matriz[linha_atual][coluna_atual] == 'v') {
        seta = 'v';
    } else {
        return 1; 
    }

    int passos = 0;

    while (1) {
        
        if (linha_atual < 0 || linha_atual >= linhas || coluna_atual < 0 || coluna_atual >= colunas) {
            return 1; 
        }

        if (matriz[linha_atual][coluna_atual] == '*') {
            return 2; 
        }

        if (matriz[linha_atual][coluna_atual] == '.') {
            direcao(&linha_atual, &coluna_atual, seta);
            passos++;
            if (passos > 10000) { 
                return 1;
            }
            continue; 
        }

        if (matriz[linha_atual][coluna_atual] == '>') {
            seta = '>';
        } else if (matriz[linha_atual][coluna_atual] == '<') {
            seta = '<';
        } else if (matriz[linha_atual][coluna_atual] == 'v') {
            seta = 'v';
        } else if (matriz[linha_atual][coluna_atual] == '^') {
            seta = '^';
        }

        direcao(&linha_atual, &coluna_atual, seta);
    }
}

int main() {
    int x, y;
    char mapa[100][100];

    scanf("%d", &y);
    scanf("%d", &x);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf(" %c", &mapa[i][j]);
        }
    }

    int resultado = procurar(mapa, x, y);

    if (resultado == 1) {
        printf("!\n");
    } else if (resultado == 2) {
        printf("*\n");
    }

    return 0;
}