#include <stdio.h>
#include <stdlib.h>

// #define TAMANHO 20
#define VERDADEIRO 1
#define FALSO 0 

void swap(int *a, int *b);
int particao(int vetor[], int inf, int sup);
void quickSort(int vetor[], int inf, int sup);

int main() {

    int v[8] = {1, 8, 4, 6, 2, 3, 2, 0};
    int tamanho = sizeof(v) / sizeof(v[0]);
    
    quickSort(v, 0, tamanho - 1);

    for (int i = 0; i < tamanho; i++) {
        printf("%d", v[i]);
    }
    printf("\n\n");
     
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int particao(int vetor[], int inf, int sup) {
    int pivot = vetor[(inf + sup)/2];
    int i = inf - 1;
    int j = sup + 1;

    while(VERDADEIRO) {
        //percorrer da esquerda p/ direita
        do {
            i++;
        } while(vetor[i] < pivot);

        //percorrer da direita p/ esquerda
        do {
            j--;
        } while(vetor[i] > pivot);

        //quando i e j se cruzam, todas as posicoes foram percorridas
        if(i >= j) return i;
        swap(&vetor[i], &vetor[j]);
    }
}

void quickSort(int vetor[], int inf, int sup) {

    //evitar problemas de chamada recursiva
    if (inf < sup) {
        int p = particao(vetor, inf, sup);
        quickSort(vetor, inf, p - 1);
        quickSort(vetor, p + 1, sup);
    }
}