#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

lista * criarLista(int n) {
    lista *L = (lista *)malloc(sizeof(lista));
    if (L == NULL) {
        printf("ERRO: Não foi possível alocar memória para a lista.\n\n");
        exit(ERRO);
    }

    L->array = (item *)malloc(n * sizeof(item));
    if (L->array == NULL) {
        printf("ERRO: Não foi possível alocar memória para o vetor de itens.");
        free(L);
        exit(ERRO);
    }

    L->tamanho = 0;
    L->capacidade = n;

    void inserirItem(lista *L, item x) {
        if (L->tamanho >= L->capacidade) {
            printf("ERRO: A lista está cheia!\n\n");
            return;
        }

        L->array[L->tamanho] = x;
        L->tamanho++;

    }
}