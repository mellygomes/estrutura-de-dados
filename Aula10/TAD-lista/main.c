#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main() {

    lista * A = criarLista(10);

    item E1 = {5};
    item E2 = {7};
    item E3 = {1};
    item E4 = {9};

    inserirItem(A, E1); //erro aqui aaah
    inserirItem(A, E2);
    inserirItem(A, E3);          
    inserirItem(A, E4);

    printf("\n%d\n", A->tamanho);

    free(A->array);
    free(A);

    return 0;
}