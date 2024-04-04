#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arquivo;
    int numero = 125;
    char palavra[50];
    arquivo = fopen("atv02.txt", "wb");

    if (arquivo == NULL) { //testar se a abertura do arquivo foi bem sucedida
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fprintf(arquivo, "%d %s", numero, frase);

    fclose(arquivo);
    return 0;
}