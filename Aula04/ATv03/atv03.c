#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    FILE *arquivo;
    int pontos;
    char time[20];
    arquivo = fopen("atv03.txt", "r");
    //obs: EOF "End of file" 

    if (arquivo == NULL) { //testar se a abertura do arquivo foi bem sucedida
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d %s", &pontos, time);
    printf("A equipe %s conquistou %d pontos.\n", time, pontos);

    fclose(arquivo);
    return 0;
}