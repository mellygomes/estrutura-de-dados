#include <stdio.h>
#include <stdlib.h>
#define ERRO -1

int Area(int Lado);

int main() {
    int L = 6;
    int A = Area(L);
    printf("\nArea do quadrado de lado %d e igual a %d.\n", L, A);
}

int Area(int Lado) {
    if ((Lado == 2) || (Lado ==3) || (Lado == 4) || (Lado ==5)) {
        int Resposta = Lado * Lado;
        return(Resposta);
    } 
    else {
        printf("Erro naos sei oq la\n");
        return(ERRO);
    }
}