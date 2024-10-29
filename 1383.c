// Guilherme da Rocha Verneck Braz; 176497

#include <stdio.h>

int main() {

  int n, instancia = 1;
  int matriz[9][9];
  int vetor[9];
      // numeros de matrizes
      scanf("%d", &n);

  // gerar a matriz
  do {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        scanf("%d", &matriz[i][j]);
      }
    }
    //verfica se as linhas sao iguais 
    int iguais = 0;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++){
        for (int k = j + 1; k < 9; k++){
           if (matriz[i][j] == matriz [i][k]){
             iguais ++;
           }
        }
      }
    }
    // verifica se as colunas sao iguais    
   for (int j = 0; j < 9; j++){
     for (int i = 0; i < 9; i++) {
       for (int k = i + 1; k < 9; k++){
         if (matriz[i][j] == matriz [k][j]){
           iguais++;
           break;
         }
      }
    }
  }
    // verfica se as 9 matrizes 3x3 tem linhas e colunas iguais
    for (int x = 0; x < 3; x++){
      for(int y = 0; y < 3; y++){
        int c = 0;
         for (int i = 3*x; i < 3*(x+1); i++){
           for (int j = 3*y; j < 3*(y+1); j++){
             vetor[c] = matriz[i][j];
             c++;     
           }       
        }
        for (int i = 0; i < 8; i++){
          for (int j = i + 1; j < 9; j++){
            if (vetor[i] == vetor[j]){
              iguais++;
              break;
            }
          }
        }
      }
    }
    printf("Instancia %d\n", instancia);
    if (iguais == 0){
      printf("SIM\n\n");
    }
    else {
      printf("NAO\n\n");
    }
    instancia++;
} while (instancia <= n);

return 0;
}