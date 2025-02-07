//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

typedef struct pilha {
    int topo;
    int chegada[MAX];
    int saida[MAX];
} Estacionamento;

Estacionamento* criarEstacionamento();
void liberarEstacionamento(Estacionamento* est);
int estacionamentoVazio(Estacionamento* est);
int estacionamentoCheio(Estacionamento* est, int vagas);
int adicionarCarro(Estacionamento* est, int chegada, int saida, int vagas);
int removerCarro(Estacionamento* est);

int main(){
    int vagas, numCarros, chegada, saida;
    int i;
    while(1){
        scanf("%d %d", &numCarros, &vagas);
        if(vagas == 0 && numCarros == 0) break;
        Estacionamento* est = criarEstacionamento();
        int possivel = 1;
        for(i = 0; i < numCarros; i++){
            scanf("%d %d", &chegada, &saida);
            if(possivel){
                if(estacionamentoVazio(est)){
                    adicionarCarro(est, chegada, saida, vagas);
                    possivel = 1;
                } else {
                    while(chegada >= est->saida[est->topo-1]){
                        removerCarro(est);
                        if(estacionamentoVazio(est)) break;
                    }
                    if(estacionamentoCheio(est, vagas)){
                        possivel = 0;
                    } else {
                        adicionarCarro(est, chegada, saida, vagas);
                        if(est->topo > 1){
                            if(est->chegada[est->topo-1] > est->chegada[est->topo -2] && est->saida[est->topo -1] < est->saida[est->topo -2]){
                                possivel = 1;
                            }else{
                                possivel = 0;
                            }
                        } else {
                            possivel = 1;
                        }
                    }
                }
            }
        }
        if(possivel) printf("Sim\n");
        else printf("Nao\n");
        liberarEstacionamento(est);
    }
}

Estacionamento* criarEstacionamento(){
    Estacionamento* est = (Estacionamento*) malloc(sizeof(Estacionamento));
    est->topo = 0;
    return est;
}

void liberarEstacionamento(Estacionamento* est){
    free(est);
}

int estacionamentoVazio(Estacionamento* est){
    if (est->topo == 0) return 1;
    else return 0;
}

int estacionamentoCheio(Estacionamento* est, int vagas){
    if (est->topo == vagas) return 1;
    else return 0;
}

int adicionarCarro(Estacionamento* est, int chegada, int saida, int vagas){
    if (!estacionamentoCheio(est, vagas)){
        est->chegada[est->topo] = chegada;
        est->saida[est->topo] = saida;
        est->topo++;
        return 1;
    } else {
        return 0;
    }
}

int removerCarro(Estacionamento* est){
    if(!estacionamentoVazio(est)){
        est->topo--;
        return 1;
    } else {
        return 0;
    }
}