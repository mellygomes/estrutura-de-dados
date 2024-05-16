#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main() {
    int c = 10;
    lista *teste = criarLista(c);
    printf("%d \n", sizeof(teste));
    printf("%d \n", sizeof(teste->array));

    free(teste->array);
    free(teste);
    return 0;


}