//Guilherme da Rocha Verneck Braz 176497

#include <stdio.h>

int main() {
    int horaInicio, minutoInicio, segundoInicio, horaFim, minutoFim, segundoFim, duracao, horas, minutos;

    scanf("%d %d %d %d", &horaInicio, &minutoInicio, &horaFim, &minutoFim);

    if (horaFim <= horaInicio && minutoFim <= minutoInicio) {
        horaFim += 24;
    } else if (minutoFim <= minutoInicio) {
        minutoFim += 60;
        horaFim -= 1;
    }

    segundoInicio = (horaInicio * 3600) + (minutoInicio * 60);
    segundoFim = (horaFim * 3600) + (minutoFim * 60);

    duracao = segundoFim - segundoInicio;
    horas = duracao / 3600;
    minutos = (duracao - (horas * 3600)) / 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);

    return 0;
}