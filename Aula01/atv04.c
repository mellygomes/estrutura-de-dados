#include <stdio.h>
#include <stdlib.h>

int Fatorial(int N);

int main() {
    int N;
    printf("Inteiro positivo: ");
    scanf("%d", &N);
    printf("Fatorial: %d", Fatorial(N));
}

int Fatorial(int N) {
    int Resposta = 1;

    for (int i = 1; i <= N; i++) Resposta = Resposta * i;
    return(Resposta);
}