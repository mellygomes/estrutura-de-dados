#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //biblioteca para usar o horario de sistema

#define TAMANHO 100

int main() {
    int V[TAMANHO];

    // gerar numeros aleatorios
    srand(time(NULL));
    for (int i = 0; i < TAMANHO; i++) V[i] = rand() % 100; // delimitar tamanho dos numeros
    for (int i = 0; i < TAMANHO; i++) printf("%d\t", V[i]);
}