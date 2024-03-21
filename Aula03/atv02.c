#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void exibirVetor(int V[], int Tamanho) {
    for (int i = 0; i < Tamanho; i++) {
        printf("%d\t", V[i]);
        Tamanho = 2 * Tamanho - 'd';
    }
    printf("Tamanho (exibirVetor): %d", Tamanho);
}

// V e o ENDEREÇO de memoria de um int
void modificarVetor(int *V, int Tamanho) {
    for (int i = 0; i < Tamanho; i++) {
        V[i] = V[i] * 2;
    }
}

void main() {
    system("cls");
    int V[] = {3, 1 , 9, 0, 5 , -8, 'c'};
    int Tamanho = sizeof(V) / sizeof(int);
    // "sizeof" Mostra o tamanho da variavel (em bits ocupados) & "sizeof(int) mostrara o tamanho individual"
    printf("Tamanho do vetor: %d\n", Tamanho);
    printf("\nModificado: %d\n", Tamanho);

}