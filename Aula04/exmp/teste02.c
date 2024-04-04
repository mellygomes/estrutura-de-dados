#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arquivo;
    arquivo = fopen("teste02.txt", "r");
    //OBS para "MODO r": 
    //1) E usado para abrir arquivo existente, o arquivo precisa existir;
    //2) Se o arquivo nao existe o ponteiro vai ser NULL.

    if (arquivo == NULL) { //testar se a abertura do arquivo foi bem sucedida
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fclose(arquivo);
    return 0;
}