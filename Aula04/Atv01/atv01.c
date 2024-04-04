#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "wb");
    //OBS para "MODO W": 
    //1) Se o arquivo nao existe, ele sera criado;
    //2) Se o arquivo existe, seu conteudo será apagado.

    if (arquivo == NULL) { //testar se a abertura do arquivo foi bem sucedida
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fclose(arquivo);
    return 0;
}