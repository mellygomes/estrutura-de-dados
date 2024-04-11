#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //biblioteca para usar o horario de sistema

#define TAMANHO 500

int main() {

    // calcular tempo de CPU gasto
    typedef int Numero; //renomeia algo que ja existe
    Numero V[TAMANHO];
    clock_t inicio, fim;
    double tempoCPU;
    srand(time(NULL));

    inicio = clock(); // dispara o cronometro
    for (int i = 0; i < TAMANHO; i++) V[i] = rand() % 100;
    fim = clock(); // para o cronometro

    for (int i = 0; i < TAMANHO; i++) printf("%d\t", V[i]);

    tempoCPU = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo de CPU: %lf segundos", tempoCPU);
}