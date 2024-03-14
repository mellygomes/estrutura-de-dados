//  CALCULAR FATORIAL

#include <stdio.h>
#include <stdlib.h>

#define ERRO -1

int X;
int fat (int X);

int main() {
    int N;
    printf("Digite um numero nao negativo: ");
    fflush(stdin);
    scanf("%d", &N);

    int Resposta = fat(N);
    if (Resposta != ERRO) printf("G(%d) = %d\n\n", N, Resposta);
    else printf("Nao existe fatorial de -n!");
}

int fat(int X) {
    if (X == 0) return(1);
    else if (X > 0) return (X * fat(X - 1));
    else return (ERRO);
}

// "Overflow é o nome do evento onde um resultado é maior que o numero de bits suportato pelo tipo de var"
// "Pesquisa binaria" é uma forma de estruturar sem verificar o vetir inteiro