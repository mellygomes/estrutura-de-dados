// FUNCAo RECURSIVA

#include <stdio.h>
#define ERRO -1

int f (int X);

int main() {
    int N = 4;
    int Resposta = f(N);
    printf("f(%d) = %d\n\n", N, Resposta);

}

int f (int X) {
    if (X == 0) return (3);
    else if (X > 0) return (2 * f(X - 1) + 5);
    else return (ERRO);
}