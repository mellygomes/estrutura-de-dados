#include <stdio.h>
// FUNCAO

#include <stdio.h>
#include <stdlib.h>
#define ERRO -1

int X;
int G (int X);

int main() {
    int N;
    int Resposta = G(N);
    if (Resposta != ERRO) printf("G(%d) = %d\n\n", N, Resposta);
    else printf("A funcao nao esta definida para o valor indicado!");
}

int g(int X) {
    if (X == 0) return(-1);
    else if (X > 0) return (4* f(X-1) + 6);
}